#pragma once

#include "AuroraEngineLibPCH.h"

#include "Core/Core.h"
#include "Event/Event.h"

namespace Aurora
{
  struct WindowProperties
  {
    std::string Title;
    unsigned int Width;
    unsigned int Height;

    WindowProperties(std::string _title = "Aurora Engine", unsigned int _width = 1280, unsigned int _height = 760)
      : Title(_title), Width(_width), Height(_height) {};
  };

  class AURORA_ENGINE_API Window
  {
  public:
    using EventCallbackFn = std::function<void(Event&)>;

    virtual ~Window() {}

    virtual void OnUpdate() const = 0;
    
    virtual std::string GetTitle() const = 0;
    virtual unsigned int GetWidth() const = 0;
    virtual unsigned int GetHeight() const = 0;
  
    virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
    virtual void SetVSync(bool enabled) = 0;
    virtual bool IsVSync() const = 0;

    static Window* Create(const WindowProperties& props = WindowProperties());
  private:

  };

}