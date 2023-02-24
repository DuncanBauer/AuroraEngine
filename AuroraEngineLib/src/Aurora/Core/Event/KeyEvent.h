#pragma once

// Engine
#include "Event.h"
#include "KeyCodes.h"

namespace Aurora
{
  namespace Engine
  {
    class AURORA_ENGINE_API KeyEvent : public Event
    {
      public:
        inline int GetKey() const { return Key; }

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

      protected:
        KeyEvent(int _Key) : Key(_Key) {}
        int Key;
    };

    class AURORA_ENGINE_API KeyPressedEvent : public KeyEvent
    {
      public:
        KeyPressedEvent(int _Key, int _RepeatCount)
          : KeyEvent(_Key), RepeatCount(_RepeatCount) {}

        int GetRepeatCount() { return RepeatCount; }

        std::string ToString() const override
        {
          std::stringstream ss;
          ss << "KeyPressedEvent: " << Key << ", " << RepeatCount;
          return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)

      private:
        int RepeatCount = 0;
    };

    class AURORA_ENGINE_API KeyReleasedEvent : public KeyEvent
    {
      public:
        KeyReleasedEvent(int _Key)
          : KeyEvent(_Key) {}

        std::string ToString() const override
        {
          std::stringstream ss;
          ss << "KeyReleasedEvent: " << Key;
          return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };
  }
}