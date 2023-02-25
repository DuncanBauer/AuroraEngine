// Aurora Engine Library, v0.0.1 ALPHA
// Header file

// For more information visit: https://github.com/DuncanBauer/ProjectAurora#table-of-contents

// Developed by Duncan Bauer and every direct or indirect contributors to the GitHub.
// LICENSING INFORMATION

// It is recommended that you don't modify any source code! It will become difficult for you to update the library.
// Note that 'Aurora::Util::' being a namespace, you can add functions into the namespace from your own source files, without
// modifying Util.h or Util.cpp. Discussing your changes on the GitHub Issue Tracker may lead you
// to a better solution or official support for them.

// Index of this file:
// CODE
//   - [SECTION] PREPROCESSOR DIRECTIVES
//   - [SECTION] INCLUDES
//   - [SECTION] FORWARD DECLARATIONS
//   - [SECTION] TYPENAMES
//   - [SECTION] CONSTANTS
//   - [SECTION] ENUMS
//   - [SECTION] CLASSES
//   - [SECTION] STRUCTS
//   - [SECTION] FUNCTIONS
//   - [SECTION] MACROS

/************************************************************************************
* [SECTION] PREPROCESSOR DIRECTIVES
************************************************************************************/
#pragma once

/************************************************************************************
* [SECTION] INCLUDES
************************************************************************************/
// Project Specific Headers
#include "Event.h"
#include "KeyCodes.h"

// C++ Standard Library Headers

// Third Party Library Headers

/************************************************************************************
* [SECTION] FORWARD DECLARATIONS
************************************************************************************/

/************************************************************************************
* [SECTION] TYPENAMES
************************************************************************************/

namespace Aurora
{
  namespace Engine
  {
/************************************************************************************
* [SECTION] CONSTANTS
************************************************************************************/

/************************************************************************************
* [SECTION] ENUMS
************************************************************************************/

/************************************************************************************
* [SECTION] STRUCTS
************************************************************************************/

/************************************************************************************
* [SECTION] CLASSES
************************************************************************************/
    class AURORA_ENGINE_API KeyEvent : public Event
    {
    public:
      inline int GetKey() const { return Key; }

      EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

    protected:
      KeyEvent(int _Key) : Key(_Key) {}
      int Key;
    };

    class AURORA_ENGINE_API KeyPressedEvent : public KeyEvent
    {
    public:
      KeyPressedEvent(int _Key, int _RepeatCount)
        : KeyEvent(_Key), RepeatCount(_RepeatCount) {}

      int GetRepeatCount() { return RepeatCount; }

      std::string ToString() const override
      {
        std::stringstream ss;
        ss << "KeyPressedEvent: " << Key << ", " << RepeatCount;
        return ss.str();
      }

      EVENT_CLASS_TYPE(KeyPressed)

    private:
      int RepeatCount = 0;
    };

    class AURORA_ENGINE_API KeyReleasedEvent : public KeyEvent
    {
    public:
      KeyReleasedEvent(int _Key)
        : KeyEvent(_Key) {}

      std::string ToString() const override
      {
        std::stringstream ss;
        ss << "KeyReleasedEvent: " << Key;
        return ss.str();
      }

      EVENT_CLASS_TYPE(KeyReleased)
    };

/************************************************************************************
* [SECTION] FUNCTIONS
************************************************************************************/

/************************************************************************************
* [SECTION] MACROS
************************************************************************************/
  }
}