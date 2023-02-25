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
#include "Core.h"

// C++ Standard Library Headers
#include <sstream>

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
    enum class EventType
    {
      None = 0,
      WindowClosed, WindowResized, WindowMaximized, WindowMinimized, WindowGainedFocus, WindowLostFocus, WindowMoved,
      AppTicked, AppUpdate, AppRender,
      KeyPressed, KeyReleased,
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
    
/************************************************************************************
* [SECTION] STRUCTS
************************************************************************************/

/************************************************************************************
* [SECTION] CLASSES
************************************************************************************/
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
      bool Handled = false;
    };

    class EventDispatcher
    {
    public:
      EventDispatcher(Event& _event) : Event(_event) { }

      template<typename T, typename F>
      bool Dispatch(const F& func)
      {
        if (Event.GetEventType() == T::GetStaticType())
        {
          Event.Handled |= func(static_cast<T&>(Event));
          return true;
        }
        return false;
      }

    private:
      Event& Event;
    };

/************************************************************************************
* [SECTION] FUNCTIONS
************************************************************************************/
    inline std::ostream& operator<<(std::ostream& os, const Event& e)
    {
      return os << e.ToString();
    }

/************************************************************************************
* [SECTION] MACROS
************************************************************************************/
#define EVENT_CLASS_TYPE(type) static  EventType   GetStaticType()               { return EventType::type; }\
                               virtual EventType   GetEventType() const override { return GetStaticType(); }\
                               virtual const char* GetName()      const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }
  }
}