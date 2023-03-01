// Aurora Engine Library
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

// C++ Standard Library Headers

// Third Party Library Headers
#pragma endregion

/************************************************************************************
* [SECTION] FORWARD DECLARATIONS
************************************************************************************/
#pragma region ForwardDeclarations
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
    class AURORA_ENGINE_API WindowEvent : public Event
    {
    public:
      WindowEvent() = default;

      std::string ToString() const override
      {
        std::stringstream ss;
        ss << "WindowEvent";
        return ss.str();
      }

        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class AURORA_ENGINE_API WindowClosedEvent : public WindowEvent
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

    class AURORA_ENGINE_API WindowResizedEvent : public WindowEvent
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

    class AURORA_ENGINE_API WindowMaximizedEvent : public WindowEvent
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

    class AURORA_ENGINE_API WindowMinimizedEvent : public WindowEvent
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

    class AURORA_ENGINE_API WindowRestoredEvent : public WindowEvent
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

    class AURORA_ENGINE_API WindowGainedFocusEvent : public WindowEvent
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

    class AURORA_ENGINE_API WindowLostFocusEvent : public WindowEvent
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

    class AURORA_ENGINE_API WindowMovedEvent : public WindowEvent
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

    class AURORA_ENGINE_API AppEvent : public Event
    {
    public:
      AppEvent() = default;

      std::string ToString() const override
      {
        std::stringstream ss;
        ss << "AppEvent";
        return ss.str();
      }

      EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class AURORA_ENGINE_API AppTickedEvent : public AppEvent
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

    class AURORA_ENGINE_API AppUpdatedEvent : public AppEvent
    {
      public:
        AppUpdatedEvent() = default;

        std::string ToString() const override
        {
          std::stringstream ss;
          ss << "AppUpdateEvent";
          return ss.str();
        }

        EVENT_CLASS_TYPE(AppUpdate)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class AURORA_ENGINE_API AppRenderedEvent : public AppEvent
    {
      public:
        AppRenderedEvent() = default;

        std::string ToString() const override
        {
          std::stringstream ss;
          ss << "AppRenderEvent";
          return ss.str();
        }

        EVENT_CLASS_TYPE(AppRender)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
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