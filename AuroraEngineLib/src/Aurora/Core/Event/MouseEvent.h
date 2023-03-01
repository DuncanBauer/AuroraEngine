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
#include "MouseCodes.h"

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
#pragma region Enum
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
    class AURORA_ENGINE_API MouseMovedEvent : public Event
    {
    public:
      MouseMovedEvent(const double x, const double y)
        : X(x), Y(y) {}

      double GetX() const { return X; }
      double GetY() const { return Y; }

      std::string ToString() const override
      {
        std::stringstream ss;
        ss << "MouseMovedEvent: " << X << ", " << Y;
        return ss.str();
      }

      EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
      double X, Y;
    };

    class AURORA_ENGINE_API MouseScrolledEvent : public Event
    {
    public:
      MouseScrolledEvent(const double _XOffset, const double _YOffset)
        : XOffset(_XOffset), YOffset(_YOffset) {}

      double GetXOffset() { return XOffset; }
      double GetYOffset() { return YOffset; }

      std::string ToString() const override
      {
        std::stringstream ss;
        ss << "MouseScrolledEvent: " << XOffset << ", " << YOffset;
        return ss.str();
      }

      EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
      double XOffset, YOffset;
    };

    class AURORA_ENGINE_API MouseButtonEvent : public Event
    {
    public:
      MouseCode GetMouseButton() { return MouseButton; }

      EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryMouseButon | EventCategoryInput)

    protected:
      MouseButtonEvent(const MouseCode button)
        : MouseButton(button) {}

      MouseCode MouseButton;
    };

    class AURORA_ENGINE_API MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
      MouseButtonPressedEvent(const MouseCode button)
        : MouseButtonEvent(button) {}

      std::string ToString() const override
      {
        std::stringstream ss;
        ss << "MouseButtonPressedEvent: " << MouseButton;
        return ss.str();
      }

      EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class AURORA_ENGINE_API MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
      MouseButtonReleasedEvent(const MouseCode button)
        : MouseButtonEvent(button) {}

      std::string ToString() const override
      {
        std::stringstream ss;
        ss << "MouseButtonReleasedEvent: " << MouseButton;
        return ss.str();
      }

      EVENT_CLASS_TYPE(MouseButtonPressed)
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