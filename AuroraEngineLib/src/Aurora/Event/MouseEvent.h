#pragma once

//#include "AuroraPCH.h"

// Engine
#include "Event.h"
#include "Aurora/Core/MouseCodes.h"


namespace Aurora
{
  class AURORA_API MouseMovedEvent : public Event
  {
    public:
      MouseMovedEvent(const float x, const float y) {}

      float GetX() const { return X; }
      float GetY() const { return Y; }

      std::string ToString()
      {
        std::stringstream ss;
        ss << "MouseScrolledEvent: " << X << ", " << Y << '\n';
        return ss.str();
      }

      EVENT_CLASS_TYPE(MouseMoved)
      EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
      float X, Y;
  };

  class AURORA_API MouseScrolledEvent : public Event
  {
    public:
      MouseScrolledEvent(float _XOffset, float _YOffset) 
        : XOffset(_XOffset), YOffset(_YOffset) {}

      float GetXOffset() { return XOffset; }
      float GetYOffset() { return YOffset; }

      std::string ToString()
      {
        std::stringstream ss;
        ss << "MouseScrolledEvent: " << XOffset << ", " << YOffset << '\n';
        return ss.str();
      }

      EVENT_CLASS_TYPE(MouseScrolled)
    
    private:
      float XOffset, YOffset;
  };

  class AURORA_API MouseButtonEvent : public Event
  {
    public:
      MouseCode GetMouseButton() { return MouseButton; }

      EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryMouseButon | EventCategoryInput)

    protected:
      MouseButtonEvent(const MouseCode button) 
        : MouseButton(button) {}

      MouseCode MouseButton;
  };

  class AURORA_API MouseButtonPressedEvent : public MouseButtonEvent
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

  class AURORA_API MouseButtonReleasedEvent : public MouseButtonEvent
  {
    public:
      MouseButtonReleasedEvent(const MouseCode button)
        : MouseButtonEvent(button) {}

      std::string ToString() const override
      {
        std::stringstream ss;
        ss << "MouseButtonPressedEvent: " << MouseButton;
        return ss.str();
      }

      EVENT_CLASS_TYPE(MouseButtonPressed)
  };
}