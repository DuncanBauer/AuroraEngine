#pragma once

#include "Event.h"

namespace Aurora
{
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
      WindowResizedEvent(unsigned int _width, unsigned int _height) : width(_width), height(_height) {};
    
      inline unsigned int getWidth() { return width; }
      inline unsigned int getHeight() { return height; }
    
      std::string ToString() const override 
      {
        std::stringstream ss;
        ss << "WindowResizedEvent: " << width << ", " << height;
        return ss.str();
      }

      EVENT_CLASS_TYPE(WindowResized);
      EVENT_CLASS_CATEGORY(EventCategoryApplication);
  
    private:
      unsigned int width, height;

  };

  class AURORA_ENGINE_API WindowMaximizedEvent : public Event
  {
    public:
      WindowMaximizedEvent(unsigned int _maximized) : maximized(_maximized) {};

      std::string ToString() const override
      {
        std::stringstream ss;
        ss << "WindowMaximizedEvent";
        return ss.str();
      }

      EVENT_CLASS_TYPE(WindowMaximized)
      EVENT_CLASS_CATEGORY(EventCategoryApplication)

    private:
      unsigned int maximized;
  };
  
  class AURORA_ENGINE_API WindowMinimizedEvent : public Event
  {
    public:
      WindowMinimizedEvent(unsigned int _minimized) : minimized(_minimized) {};

      std::string ToString() const override
      {
        std::stringstream ss;
        ss << "WindowMinimizedEvent";
        return ss.str();
      }

      EVENT_CLASS_TYPE(WindowMinimized)
      EVENT_CLASS_CATEGORY(EventCategoryApplication)

    private:
      unsigned int minimized;
  };

  class AURORA_ENGINE_API WindowRestoredEvent : public Event
  {
  public:
    WindowRestoredEvent(unsigned int _restored) : restored(_restored) {};

    std::string ToString() const override
    {
      std::stringstream ss;
      ss << "WindowMinimizedEvent";
      return ss.str();
    }

    EVENT_CLASS_TYPE(WindowMinimized)
    EVENT_CLASS_CATEGORY(EventCategoryApplication)

  private:
    unsigned int restored;
  };

  class AURORA_ENGINE_API WindowGainedFocusEvent : public Event
  {
    public:
      WindowGainedFocusEvent(int _focus) : focus(_focus) {};

      std::string ToString() const override
      {
        std::stringstream ss;
        ss << "WindowGainedFocusEvent";
        return ss.str();
      }

      EVENT_CLASS_TYPE(WindowGainedFocus)
      EVENT_CLASS_CATEGORY(EventCategoryApplication)

    private:
      unsigned int focus;
  };
  
  class AURORA_ENGINE_API WindowLostFocusEvent : public Event
  {
    public:
      WindowLostFocusEvent(int _focus) : focus(_focus) {};

      std::string ToString() const override
      {
        std::stringstream ss;
        ss << "WindowLostFocusEvent";
        return ss.str();
      }

      EVENT_CLASS_TYPE(WindowLostFocus)
      EVENT_CLASS_CATEGORY(EventCategoryApplication)

    private:
      unsigned int focus;
  };
  
  class AURORA_ENGINE_API WindowMovedEvent : public Event
  {
    public:
      WindowMovedEvent(int _xpos, int _ypos) : xpos(_xpos), ypos(_ypos) {};

      std::string ToString() const override
      {
        std::stringstream ss;
        ss << "WindowMovedEvent: " << xpos << ", " << ypos;
        return ss.str();
      }

      EVENT_CLASS_TYPE(WindowMoved)
      EVENT_CLASS_CATEGORY(EventCategoryApplication)

    private:
      int xpos, ypos;
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
}