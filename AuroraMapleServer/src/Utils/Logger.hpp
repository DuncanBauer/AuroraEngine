/*********************************************************************************
* AuroraSource
* Copyright(C) 2021 Duncan Bauer <duncanebauer@gmail.com>
*
* This program is free software : you can redistribute itand /or modify
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
* along with this program.If not, see <http://www.gnu.org/licenses/>.
*********************************************************************************/

#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>

namespace Utils
{
    namespace Logger
    {
        template<typename T>
        inline void log(T _data) { std::cout << "LOG: " << _data << '\n'; }

        template<typename T>
        inline void warn(T _data) { std::cout << "WARNING: " << _data << '\n'; }

        template<typename T>
        inline void error(T _data) { std::cout << "ERROR: " << _data << '\n'; }
    }
}

#endif