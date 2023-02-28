#pragma once

#include <Core.h>
#include <string>

namespace Aurora
{
  namespace Maple
  {
    class AURORA_MAPLE_API WzObject
    {
      public:
        WzObject(std::string name);
        ~WzObject();

        std::string m_Name;
      private:
      };
  }
}