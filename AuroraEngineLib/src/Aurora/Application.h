#pragma once

// Aurora Engine
#include "Core/Core.h"
#include "Window.h"

#include "Event/Event.h"
#include "Event/ApplicationEvent.h"
#include "Event/KeyEvent.h"
#include "Event/MouseEvent.h"


namespace Aurora 
{
  class AURORA_ENGINE_API Application
  {
    public:
      Application();
      virtual ~Application();

      void Run();
      
      void OnEvent(Event& e);

    private:
      // Event handlers
      bool OnWindowClosed(WindowClosedEvent& e);

      std::unique_ptr<Window> m_Window;
      bool m_Running = true;
  };
 
  Application* CreateApplication(); // To be defined in client
}

