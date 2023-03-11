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
#include "Aurora/Core/Util.h"

// C++ Standard Library Headers
#include <sstream>

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
/************************************************************************************
* [SECTION] CONSTANTS
************************************************************************************/
#pragma region Constants
#pragma endregion

/************************************************************************************
* [SECTION] ENUMS
************************************************************************************/
#pragma region Enums
    enum class EventType
    {
      None = 0,
      WindowClosed, WindowResized, WindowMaximized, WindowMinimized, WindowGainedFocus, WindowLostFocus, WindowMoved,
      AppTicked, AppUpdate, AppRender,
      KeyPressed, KeyReleased, KeyTyped,
      MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    enum EventCategory
    {
      None = 0,
      EventCategoryApplication = BIT(0),
      EventCategoryInput = BIT(1),
      EventCategoryKeyboard = BIT(2),
      EventCategoryMouse = BIT(3),
      EventCategoryMouseButon = BIT(4)
    };
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
    class AURORA_ENGINE_API Event
    {
      friend class EventDispatcher;

    public:
      virtual EventType GetEventType() const = 0;
      virtual const char* GetName() const = 0;
      virtual int GetCategoryFlags() const = 0;
      virtual std::string ToString() const { return GetName(); }

      inline bool IsInCategory(EventCategory category)
      {
        return GetCategoryFlags() & category;
      }

    protected:
      bool m_Handled = false;
    };

    class EventDispatcher
    {
    public:
      EventDispatcher(Event& _event) : m_Event(_event) { }

      template<typename T, typename F>
      bool Dispatch(const F& func)
      {
        if (m_Event.GetEventType() == T::GetStaticType())
        {
          m_Event.m_Handled |= func(static_cast<T&>(m_Event));
          return true;
        }
        return false;
      }

    private:
      Event& m_Event;
    };
#pragma endregion

/************************************************************************************
* [SECTION] FUNCTIONS
************************************************************************************/
#pragma region Functions
    inline std::ostream& operator<<(std::ostream& os, const Event& e)
    {
      return os << e.ToString();
    }
#pragma endregion

/************************************************************************************
* [SECTION] MACROS
************************************************************************************/
#pragma region Macros
#define EVENT_CLASS_TYPE(type) static  EventType   GetStaticType()               { return EventType::type; }\
                               virtual EventType   GetEventType() const override { return GetStaticType(); }\
                               virtual const char* GetName()      const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }
#pragma endregion
}