#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cctype>

namespace Utils
{
    // Converts a string to a boolean (Not case sensitive)
    bool stob(std::string str)  
    {
      std::transform(str.begin(), str.end(), str.begin(), ::tolower);
      std::istringstream is(str);
      bool b;
      is >> std::boolalpha >> b;
      return b;
    }

    // Converts a string to a vector of ints
    std::vector<int> stoiv(std::string str)
    {
      std::string delimiter = ",";
      std::vector<int> arr;
      size_t pos = 0;
      std::string token;
      while ((pos = str.find(delimiter)) != std::string::npos)
      {
        token = str.substr(0, pos);
        str.erase(0, pos + delimiter.length());
        arr.push_back(std::stoi(token));
      }
      return arr;
    }
}