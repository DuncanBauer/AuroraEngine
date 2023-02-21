#pragma once

//#include "AuroraPCH.h"

// Engine
#include "Event.h"
#include "Aurora/Core/KeyCodes.h"

namespace Aurora
{
  class AURORA_API KeyEvent : public Event
  {
    public:
      inline int GetKeyCode() const { return KeyCode; }

      EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

    protected:
      KeyEvent(int _KeyCode) : KeyCode(_KeyCode) {}
      int KeyCode;
  };

  class AURORA_API KeyPressedEvent : public KeyEvent
  {
    public:
      KeyPressedEvent(int _KeyCode, int _RepeatCount) 
        : KeyEvent(_KeyCode), RepeatCount(_RepeatCount) {}

      int GetRepeatCount() { return RepeatCount; }

      std::string ToString() 
      {
        std::stringstream ss;
        ss << "KeyPressedEvent: " << KeyCode << ", " << RepeatCount << '\n';
        return ss.str();
      }

      EVENT_CLASS_TYPE(KeyPressed)
  
    private:
      int RepeatCount = 0;
  };

  class AURORA_API KeyReleasedEvent : public KeyEvent
  {
    public:
      KeyReleasedEvent(int _KeyCode, int _Duration)
        : KeyEvent(_KeyCode), Duration(_Duration) {}

      std::string ToString()
      {
        std::stringstream ss;
        ss << "KeyReleasedEvent: " << KeyCode << ", " << Duration << '\n';
        return ss.str();
      }

      EVENT_CLASS_TYPE(KeyReleased)

    private:
      int Duration = 0;
  };

  class AURORA_API KeyClickedEvent : public KeyEvent
  {
    public:
      KeyClickedEvent(int _KeyCode)
        : KeyEvent(_KeyCode) {}

      std::string ToString()
      {
        std::stringstream ss;
        ss << "KeyClickedEvent: " << KeyCode << '\n';
        return ss.str();
      }

      EVENT_CLASS_TYPE(KeyClicked)
  };
}