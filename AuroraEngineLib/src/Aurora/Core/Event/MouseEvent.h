#pragma once

// Engine
#include "Event.h"

#include "MouseCodes.h"

namespace Aurora
{
  namespace Engine
  {
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
  }
}