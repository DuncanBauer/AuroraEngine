/*********************************************************************************
* AuroraSource - A C++ MapleStory Server Emulator
* Copyright(C) 2021 Duncan Bauer <duncanebauer@gmail.com>
*
* This program is free software : you can redistribute it and/or modify
* it under the terms of the GNU Affero General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
* GNU Affero General Public License for more details.
*
* You should have received a copy of the GNU Affero General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*********************************************************************************/

#ifndef MAPLECLIENT_H
#define MAPLECLIENT_H

// Aurora Server
#include <memory>

#include "TCPConnection.hpp"
#include "Crypto/MapleCrypto.hpp"
#include "PacketParser.hpp"

class MapleClient : public TCPConnection
{
    public:
        /*****************
         * Constructors
         ****************/
        // Default constructor
        MapleClient() = delete;

        // Deconstructor
        ~MapleClient() {};

        static std::shared_ptr<TCPConnection> create(boost::asio::io_context& _ioContext) { return std::shared_ptr<MapleClient>(new MapleClient(_ioContext)); }

        /*****************
         * Server Functions
         ****************/
        void start()
        {
            ByteBuffer recvIV = this->recvCipher->getIV();
            ByteBuffer sendIV = this->sendCipher->getIV();

            // This is the packet for the v83 MapleStory Global(NA) handshake
            ByteBuffer buff;
            PacketParser::writeShort(&buff, 0x0E);
            PacketParser::writeShort(&buff, 83);
            PacketParser::writeShort(&buff, 1);
            PacketParser::writeByte(&buff, 49);
            PacketParser::writeByte(&buff, &recvIV);
            PacketParser::writeByte(&buff, &sendIV);
            PacketParser::writeByte(&buff, 8);

            this->pushOntoWriteQueue(std::string(buff.begin(), buff.end()));
            this->write();
            this->readHeader();
        }

        void readHeader()
        {
            std::cout << "Read\n";
            boost::asio::async_read(this->getSocket(),
                                    this->getReadBuffer(),
                                    boost::asio::transfer_exactly(4),
                                    boost::bind(&MapleClient::handleReadHeader,
                                                std::dynamic_pointer_cast<MapleClient>(shared_from_this()),
                                                boost::asio::placeholders::error,
                                                boost::asio::placeholders::bytes_transferred));
        }

        void write()
        {
            // Async write
            std::cout << "Write\n";
            if(this->writeBufferQueue.size() > 0 && this->isSocketActive())
            {
                boost::asio::async_write(this->getSocket(),
                                         boost::asio::buffer(this->writeBufferQueue.front()),
                                         boost::bind(&MapleClient::handleWrite,
                                                     std::dynamic_pointer_cast<MapleClient>(shared_from_this()),
                                                     boost::asio::placeholders::error,
                                                     boost::asio::placeholders::bytes_transferred));
            }
        }

        /*****************
         * Getters & Setters
         ****************/

    private:
        MapleClient(boost::asio::io_context& _ioContext) : TCPConnection(_ioContext) 
        {
            ByteBuffer recvIV = { 70, 114, 122,  82 };
            ByteBuffer sendIV = { 82,  48, 120, 115 };

            this->recvCipher = new MapleCrypto::MapleAESOFB((short)83, recvIV, 0);
            this->sendCipher = new MapleCrypto::MapleAESOFB((short)(0xFFFF - 83), sendIV, 1);

            this->setSocketActive(true);
        }

        void handleReadHeader(const boost::system::error_code& _error, size_t _bytes_transferred)
        {
            std::cout << "handleReadHeader\n";
            // If theres an async error, close the connection
            if (!_error)
            {
                boost::asio::streambuf::const_buffers_type bufs = this->getReadBuffer().data();
                std::string str(boost::asio::buffers_begin(bufs), boost::asio::buffers_begin(bufs) + _bytes_transferred);

                std::cout << "DATA: " << std::hex << '\n';
                byte header[4];
                for(int i = 0; i < _bytes_transferred; ++i)
                {
                    header[i] = (byte)str[i];
                    std::cout << (unsigned int)str[i] << ' ';
                }
                std::cout << "\n_bytes_transferred: " << _bytes_transferred << '\n';

                short packetLength = MapleCrypto::MapleAESOFB::getPacketLength(header);
                if(packetLength < 2)
                {
                    this->shutdown();
                    return;
                }

                std::cout << "Packet Length: " << packetLength << '\n';
                this->readBuffer.consume(4);
                boost::asio::async_read(this->getSocket(),
                                        this->getReadBuffer(),
                                        boost::asio::transfer_exactly(packetLength),
                                        boost::bind(&MapleClient::handleReadBody,
                                                    std::dynamic_pointer_cast<MapleClient>(shared_from_this()),
                                                    boost::asio::placeholders::error,
                                                    boost::asio::placeholders::bytes_transferred));
            }
            else
            {
                std::cout << "MapleClient::handleRead error: " << _error.message() << '\n';
                this->shutdown();
            }
        }

        void handleReadBody(const boost::system::error_code& _error, size_t _bytes_transferred)
        {
            std::cout << "handleReadBody\n";
            // If theres an async error, close the connection
            if (!_error)
            {
                boost::asio::streambuf::const_buffers_type bufs = this->getReadBuffer().data();
                std::string str(boost::asio::buffers_begin(bufs), boost::asio::buffers_begin(bufs) + _bytes_transferred);

                // Try decrypting
                ByteBuffer bb(_bytes_transferred);

                auto it = boost::asio::buffers_begin(bufs);
                for(int i = 0; i < _bytes_transferred; ++i)
                {
                    bb[i] = (unsigned char)*it;
                    ++it;
                }

                // Process data
                std::cout << "(ENCRYPTED) ";
                std::cout << std::hex;
                for(int i = 0; i < bb.size(); ++i)
                {
                    std::cout << (unsigned int)bb[i] << ' ';
                }
                std::cout << "\n\n";

                std::cout << "(AESDECRYP) ";
                this->recvCipher->crypt(&bb);
                for(int i = 0; i < bb.size(); ++i)
                {
                    std::cout << (unsigned int)bb[i] << ' ';
                }
                std::cout << "\n\n";

                std::cout << "(DECRYPTED) ";
                MapleCrypto::CustomEncryption::decrypt(&bb, bb.size());
                for(int i = 0; i < bb.size(); ++i)
                {
                    std::cout << (unsigned int)bb[i] << ' ';
                }
                std::cout << "\n\n";

                std::cout << std::dec;
                if(bb.size() > 30)
                {
                    short version = PacketParser::readShort(&bb);
                    std::string username = PacketParser::readMapleString(&bb);
                    std::string password = PacketParser::readMapleString(&bb);
                    std::cout << "Version: "  << version << '\n';
                    std::cout << "Username: " << username << '\n';
                    std::cout << "Password: " << password << '\n';
                }
                std::cout << str << '\n';

                // Clear the read buffer
                this->readBuffer.consume(_bytes_transferred);
                this->readHeader();
            }
            else
            {
                std::cout << "MapleClient::handleRead error: " << _error.message() << '\n';
                this->shutdown();
            }
        }

        void handleWrite(const boost::system::error_code& _error, size_t _bytes_transferred)
        {
            // If theres an async error, close the connection
            if (!_error)
            {
                // Pop the written packet from the write buffer
                std::string str(this->writeBufferQueue.front());
                this->writeBufferQueue.pop();
                
                // Keep this for testing/examples
                std::cout << "Bytes written: ";
                for(int i = 0; i < _bytes_transferred; ++i)
                {
                    std::cout << std::hex << (unsigned int)str[i] << ' ';
                }
                std::cout << "\n\n";

                if(this->writeBufferQueue.size() > 0)
                {
                    this->write();
                }
            }
            else
            {
                std::cout << "MapleClient::handleWrite error: " << _error.message() << '\n';
                this->shutdown();
            }
        }

        MapleCrypto::MapleAESOFB* recvCipher = nullptr;
        MapleCrypto::MapleAESOFB* sendCipher = nullptr;
};

#endif