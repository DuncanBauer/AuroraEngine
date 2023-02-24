#pragma once

// Aurora Engine
#include <Core.h>
#include <Util.h>

#include "Window.h"
#include "Event/Event.h"
#include "Event/ApplicationEvent.h"
#include "Event/KeyEvent.h"
#include "Event/MouseEvent.h"

#include "Aurora/Core/Layer/LayerStack.h"


namespace Aurora 
{
  namespace Engine
  {
    class AURORA_ENGINE_API Application
    {
      public:
        Application();
        virtual ~Application();

        void Run();

        void OnUpdate(Util::DeltaTime t);
        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);

      private:
        // Event handlers
        bool OnWindowClosed(WindowClosedEvent& e);
        bool OnWindowResized(WindowResizedEvent& e);

        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
        float m_LastFrameTime = 0;
        
    };

    Application* CreateApplication(); // To be defined in client
  }
}

