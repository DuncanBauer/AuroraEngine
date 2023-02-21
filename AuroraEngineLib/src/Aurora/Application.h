#pragma once

// Aurora Engine
#include "Core/Core.h"
#include "Event/Event.h"
#include "Window.h"

namespace Aurora 
{
  class AURORA_ENGINE_API Application
  {
    public:
      Application();
      virtual ~Application();

      void Run();
      
    private:
      std::unique_ptr<Window> m_Window;
      bool m_Running = true;
  };
 
  Application* CreateApplication(); // To be defined in client
}

