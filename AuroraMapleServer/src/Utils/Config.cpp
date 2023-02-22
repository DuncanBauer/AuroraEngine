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

#include "Config.hpp"

#include <iostream>
#include <fstream>

namespace Utils
{
  void Config::load()
  {
    std::ifstream file("config.cfg");
    if (file.is_open())
    {
      std::string line;
      while (std::getline(file, line))
      {
        if (line.rfind("##", 0) == 0)
        {
          continue;
        }
        size_t index = line.find("=");
        if (index != -1)
        {
          this->data[line.substr(0, index)] = line.substr(index + 1, line.length() - index - 1);
        }
      }
      file.close();
    }
    else
    {
      std::cout << "Failed to open file" << '\n';
    }
  }

  std::map<std::string, std::string> Config::getData()
  {
    return this->data;
  }
}
