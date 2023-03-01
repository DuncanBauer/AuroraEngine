// Aurora Engine Library
// Header file

// For more information visit: https://github.com/DuncanBauer/ProjectAurora#table-of-contents

// Developed by Duncan Bauer and every direct or indirect contributors to the GitHub.
// LICENSING INFORMATION

// It is recommended that you don't modify any source code! It will become difficult for you to update the library.
// Note that 'Aurora::' being a namespace, you can add functions into the namespace from your own source files, without
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

#pragma once

/************************************************************************************
* [SECTION] PREPROCESSOR DIRECTIVES
************************************************************************************/
#pragma region Preprocessor
#pragma endregion

/************************************************************************************
* [SECTION] INCLUDES
************************************************************************************/
#pragma region Includes
// Project Specific Headers
#include "Event.h"
#include "KeyCodes.h"

// C++ Standard Library Headers

// Third Party Library Headers
#pragma endregion

/************************************************************************************
* [SECTION] FORWARD DECLARATIONS
************************************************************************************/
#pragma region Forward Declarations
#pragma endregion

/************************************************************************************
* [SECTION] TYPENAMES
************************************************************************************/
#pragma region Typenames
#pragma endregion

namespace Aurora
{
  namespace Engine
  {
/************************************************************************************
* [SECTION] CONSTANTS
************************************************************************************/
#pragma region Constants
#pragma endregion

/************************************************************************************
* [SECTION] ENUMS
************************************************************************************/
#pragma region Enums
#pragma endregion

/************************************************************************************
* [SECTION] STRUCTS
************************************************************************************/
#pragma region Structs
#pragma endregion

/************************************************************************************
* [SECTION] CLASSES
************************************************************************************/
#pragma region Classes
    class AURORA_ENGINE_API KeyEvent : public Event
    {
    public:
      inline int GetKey() const { return m_Key; }

      EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

    protected:
      KeyEvent(int _Key) : m_Key(_Key) {}
      int m_Key;
    };

    class AURORA_ENGINE_API KeyPressedEvent : public KeyEvent
    {
    public:
      KeyPressedEvent(int _Key, int _RepeatCount)
        : KeyEvent(_Key), m_RepeatCount(_RepeatCount) {}

      int GetRepeatCount() { return m_RepeatCount; }

      std::string ToString() const override
      {
        std::stringstream ss;
        ss << "KeyPressedEvent: " << m_Key << ", " << m_RepeatCount;
        return ss.str();
      }

      EVENT_CLASS_TYPE(KeyPressed)

    private:
      int m_RepeatCount = 0;
    };

    class AURORA_ENGINE_API KeyReleasedEvent : public KeyEvent
    {
    public:
      KeyReleasedEvent(int _Key)
        : KeyEvent(_Key) {}

      std::string ToString() const override
      {
        std::stringstream ss;
        ss << "KeyReleasedEvent: " << m_Key;
        return ss.str();
      }

      EVENT_CLASS_TYPE(KeyReleased)
    };

    class AURORA_ENGINE_API KeyTypedEvent : public KeyEvent
    {
    public:
      KeyTypedEvent(int _Key)
        : KeyEvent(_Key) {}

      std::string ToString() const override
      {
        std::stringstream ss;
        ss << "KeyTypedEvent: " << m_Key;
        return ss.str();
      }

      EVENT_CLASS_TYPE(KeyTyped)
    };
#pragma endregion

/************************************************************************************
* [SECTION] FUNCTIONS
************************************************************************************/
#pragma region Functions
#pragma endregion

/************************************************************************************
* [SECTION] MACROS
************************************************************************************/
#pragma region Macros
#pragma endregion
  }
}