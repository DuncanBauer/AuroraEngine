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
    class AURORA_ENGINE_API WindowClosedEvent : public Event
    {
      public:
        WindowClosedEvent() = default;

        std::string ToString() const override
        {
          std::stringstream ss;
          ss << "WindowClosedEvent";
          return ss.str();
        }

        EVENT_CLASS_TYPE(WindowClosed)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class AURORA_ENGINE_API WindowResizedEvent : public Event
    {
      public:
        WindowResizedEvent(unsigned int _width, unsigned int _height) : m_Width(_width), m_Height(_height) {};

        inline unsigned int GetWidth() { return m_Width; }
        inline unsigned int GetHeight() { return m_Height; }

        std::string ToString() const override
        {
          std::stringstream ss;
          ss << "WindowResizedEvent: " << m_Width << ", " << m_Height;
          return ss.str();
        }

        EVENT_CLASS_TYPE(WindowResized);
        EVENT_CLASS_CATEGORY(EventCategoryApplication);

      private:
        unsigned int m_Width, m_Height;
    };

    class AURORA_ENGINE_API WindowMaximizedEvent : public Event
    {
      public:
        WindowMaximizedEvent(unsigned int _maximized) : m_Maximized(_maximized) {};

        std::string ToString() const override
        {
          std::stringstream ss;
          ss << "WindowMaximizedEvent";
          return ss.str();
        }

        EVENT_CLASS_TYPE(WindowMaximized)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)

      private:
        unsigned int m_Maximized;
    };

    class AURORA_ENGINE_API WindowMinimizedEvent : public Event
    {
      public:
        WindowMinimizedEvent(unsigned int _minimized) : m_Minimized(_minimized) {};

        std::string ToString() const override
        {
          std::stringstream ss;
          ss << "WindowMinimizedEvent";
          return ss.str();
        }

        EVENT_CLASS_TYPE(WindowMinimized)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)

      private:
        unsigned int m_Minimized;
    };

    class AURORA_ENGINE_API WindowRestoredEvent : public Event
    {
      public:
        WindowRestoredEvent(unsigned int _restored) : m_Restored(_restored) {};

        std::string ToString() const override
        {
          std::stringstream ss;
          ss << "WindowMinimizedEvent";
          return ss.str();
        }

        EVENT_CLASS_TYPE(WindowMinimized)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)

      private:
        unsigned int m_Restored;
    };

    class AURORA_ENGINE_API WindowGainedFocusEvent : public Event
    {
      public:
        WindowGainedFocusEvent(int _focus) : m_Focused(_focus) {};

        std::string ToString() const override
        {
          std::stringstream ss;
          ss << "WindowGainedFocusEvent";
          return ss.str();
        }

        EVENT_CLASS_TYPE(WindowGainedFocus)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)

      private:
        unsigned int m_Focused;
    };

    class AURORA_ENGINE_API WindowLostFocusEvent : public Event
    {
      public:
        WindowLostFocusEvent(int _focus) : m_Focused(_focus) {};

        std::string ToString() const override
        {
          std::stringstream ss;
          ss << "WindowLostFocusEvent";
          return ss.str();
        }

        EVENT_CLASS_TYPE(WindowLostFocus)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)

      private:
        unsigned int m_Focused;
    };

    class AURORA_ENGINE_API WindowMovedEvent : public Event
    {
      public:
        WindowMovedEvent(int _xpos, int _ypos) : m_Xpos(_xpos), m_Ypos(_ypos) {};

        std::string ToString() const override
        {
          std::stringstream ss;
          ss << "WindowMovedEvent: " << m_Xpos << ", " << m_Ypos;
          return ss.str();
        }

        EVENT_CLASS_TYPE(WindowMoved)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)

      private:
        int m_Xpos, m_Ypos;
    };

    class AURORA_ENGINE_API AppTickedEvent : public Event
    {
      public:
        AppTickedEvent() = default;

        std::string ToString() const override
        {
          std::stringstream ss;
          ss << "AppTickedEvent";
          return ss.str();
        }

        EVENT_CLASS_TYPE(AppTicked)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class AURORA_ENGINE_API AppUpdateEvent : public Event
    {
      public:
        AppUpdateEvent() = default;

        std::string ToString() const override
        {
          std::stringstream ss;
          ss << "AppUpdateEvent";
          return ss.str();
        }

        EVENT_CLASS_TYPE(AppUpdate)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class AURORA_ENGINE_API AppRenderEvent : public Event
    {
      public:
        AppRenderEvent() = default;

        std::string ToString() const override
        {
          std::stringstream ss;
          ss << "AppRenderEvent";
          return ss.str();
        }

        EVENT_CLASS_TYPE(AppRender)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

/************************************************************************************
* [SECTION] FUNCTIONS
************************************************************************************/

/************************************************************************************
* [SECTION] MACROS
************************************************************************************/
  }
}