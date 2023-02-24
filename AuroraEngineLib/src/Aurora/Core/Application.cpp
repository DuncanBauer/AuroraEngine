#include "AuroraEngineLibPCH.h"

#include "Application.h"

#include <Util.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Aurora 
{
  namespace Engine
  {
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    Application::Application()
    {
      m_Window = std::unique_ptr<Window>(Window::Create());
      m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

      unsigned int id;
      glGenVertexArrays(1, &id);
    }

    Application::~Application()
    {

    }

    void Application::Run()
    {
      while (m_Running)
      {
        float time = Util::Time::GetTime();
        Util::DeltaTime d_time = time - m_LastFrameTime;
        m_LastFrameTime = time;

        glClearColor(1, 0, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        m_Window->OnUpdate();

        OnUpdate(d_time);
      }
    }

    void Application::OnUpdate(Util::DeltaTime t)
    {
      PA_ENGINE_TRACE("{0}", t.ToString());
      for (Layer* layer : m_LayerStack)
      {
        layer->OnUpdate(t);
      }
    }

    void Application::OnEvent(Event& e)
    {
      EventDispatcher dispatcher(e);
      dispatcher.Dispatch<WindowClosedEvent>(BIND_EVENT_FN(OnWindowClosed));
      dispatcher.Dispatch<WindowResizedEvent>(BIND_EVENT_FN(OnWindowResized));

      auto rit = m_LayerStack.rbegin();
      while (rit != m_LayerStack.rend())
      {
        (*rit)->OnEvent(e);
        rit++;
      }

      PA_ENGINE_TRACE("{0}", e);
    }

    void Application::PushLayer(Layer* layer)
    {
      m_LayerStack.PushLayer(layer);
      layer->OnAttach();
    }

    void Application::PushOverlay(Layer* overlay)
    {
      m_LayerStack.PushLayer(overlay);
      overlay->OnAttach();
    }

    bool Application::OnWindowClosed(WindowClosedEvent& e)
    {
      m_Running = false;
      return true;
    }

    bool Application::OnWindowResized(WindowResizedEvent& e)
    {
      return true;
    }
  }
}