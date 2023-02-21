#pragma once

//#include "AuroraPCH.h"

#include "Event.h"

namespace Aurora
{
  class AURORA_API WindowClosedEvent : public Event
  {
    public:
      WindowClosedEvent() = default;

      std::string ToString() const override
      {
        std::stringstream ss;
        ss << "WindowClosedEvent" << '\n';
        return ss.str();
      }

      EVENT_CLASS_TYPE(WindowClosed)
      EVENT_CLASS_CATEGORY(EventCategoryApplication)
  };

  class AURORA_API WindowResizedEvent : public Event
  {
    public:
      WindowResizedEvent(unsigned int _width, unsigned int _height) : width(_width), height(_height) {};
    
      inline unsigned int getWidth() { return width; }
      inline unsigned int getHeight() { return height; }
    
      std::string ToString() const override 
      {
        std::stringstream ss;
        ss << "WindowResizedEvent: " << width << ", " << height << '\n';
        return ss.str();
      }

      EVENT_CLASS_TYPE(WindowResized);
      EVENT_CLASS_CATEGORY(EventCategoryApplication);
  
    private:
      unsigned int width, height;

  };

  class AURORA_API WindowMaximizedEvent : public Event
  {
    public:
      WindowMaximizedEvent() = default;

      std::string ToString() const override
      {
        std::stringstream ss;
        ss << "WindowMaximizedEvent" << '\n';
        return ss.str();
      }

      EVENT_CLASS_TYPE(WindowMaximized)
      EVENT_CLASS_CATEGORY(EventCategoryApplication)
  };
  
  class AURORA_API WindowMinimizedEvent : public Event
  {
    public:
      WindowMinimizedEvent() = default;

      std::string ToString() const override
      {
        std::stringstream ss;
        ss << "WindowMinimizedEvent" << '\n';
        return ss.str();
      }

      EVENT_CLASS_TYPE(WindowMinimized)
      EVENT_CLASS_CATEGORY(EventCategoryApplication)
  };
  
  class AURORA_API WindowGainedFocusEvent : public Event
  {
    public:
      WindowGainedFocusEvent() = default;

      std::string ToString() const override
      {
        std::stringstream ss;
        ss << "WindowGainedFocusEvent" << '\n';
        return ss.str();
      }

      EVENT_CLASS_TYPE(WindowGainedFocus)
      EVENT_CLASS_CATEGORY(EventCategoryApplication)
  };
  
  class AURORA_API WindowLostFocusEvent : public Event
  {
    public:
      WindowLostFocusEvent() = default;

      std::string ToString() const override
      {
        std::stringstream ss;
        ss << "WindowLostFocusEvent" << '\n';
        return ss.str();
      }

      EVENT_CLASS_TYPE(WindowLostFocus)
      EVENT_CLASS_CATEGORY(EventCategoryApplication)
  };
  
  class AURORA_API WindowMovedEvent : public Event
  {
    public:
      WindowMovedEvent() = default;

      std::string ToString() const override
      {
        std::stringstream ss;
        ss << "WindowMovedEvent" << '\n';
        return ss.str();
      }

      EVENT_CLASS_TYPE(WindowMoved)
      EVENT_CLASS_CATEGORY(EventCategoryApplication)
  };
  
  class AURORA_API AppTickedEvent : public Event
  {
    public:
      AppTickedEvent() = default;

      std::string ToString() const override
      {
        std::stringstream ss;
        ss << "AppTickedEvent" << '\n';
        return ss.str();
      }

      EVENT_CLASS_TYPE(AppTicked)
      EVENT_CLASS_CATEGORY(EventCategoryApplication)
  };
  
  class AURORA_API AppUpdateEvent : public Event
  {
    public:
      AppUpdateEvent() = default;

      std::string ToString() const override
      {
        std::stringstream ss;
        ss << "AppUpdateEvent" << '\n';
        return ss.str();
      }

      EVENT_CLASS_TYPE(AppUpdate)
      EVENT_CLASS_CATEGORY(EventCategoryApplication)
  };
  
  class AURORA_API AppRenderEvent : public Event
  {
    public:
      AppRenderEvent() = default;

      std::string ToString() const override
      {
        std::stringstream ss;
        ss << "AppRenderEvent" << '\n';
        return ss.str();
      }

      EVENT_CLASS_TYPE(AppRender)
      EVENT_CLASS_CATEGORY(EventCategoryApplication)
  };
}