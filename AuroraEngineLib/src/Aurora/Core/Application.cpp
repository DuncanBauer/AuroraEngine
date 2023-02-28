// Aurora Engine Library
// Source file

// For more information visit: https://github.com/DuncanBauer/ProjectAurora

// Developed by Duncan Bauer and every direct or indirect contributors to the GitHub.
// LICENSING INFORMATION

// It is recommended that you don't modify any source code! It will become difficult for you to update the library.
// Note that 'Aurora::Util::' being a namespace, you can add functions into the namespace from your own source files, without
// modifying Util.h or Util.cpp. Discussing your changes on the GitHub Issue Tracker may lead you
// to a better solution or official support for them.

// Index of this file:
// CODE
//   - [SECTION] INCLUDES
//   - [SECTION] STATIC VARIABLE INITIALIZATION
//   - [SECTION] FUNCTIONS

/************************************************************************************
* [SECTION] INCLUDES
************************************************************************************/
#pragma region Includes
// PCH
#include "AuroraEngineLibPCH.h"

// Project Specific Header
#include "Util.h"
#include "Application.h"
#include "Input.h"

// C++ Headers

// Third Party Library Headers
// Glad 
#include <glad/glad.h>

// GLFW
#include <GLFW/glfw3.h>
#pragma endregion

namespace Aurora
{
  namespace Engine
  {
/************************************************************************************
* [SECTION] STATIC VARIABLE INITIALIZATION
************************************************************************************/
#pragma region Static Initialization
    Application* Application::s_Instance = nullptr;
#pragma endregion

/************************************************************************************
* [SECTION] FUNCTIONS
************************************************************************************/
#pragma region Functions
    Application::Application()
    {
      PA_ENGINE_ASSERT(!s_Instance, "Application already exists!")
      s_Instance = this;

      m_Window = std::unique_ptr<Window>(Window::Create());
      m_Window->SetEventCallback(BIND_EVENT_FN(Application, OnEvent));
    }

    Application::~Application()
    {

    }

    void Application::Run()
    {
      while (m_Running)
      {
        float time = Util::Time::GetTimeSeconds();
        Util::DeltaTime d_time = time - m_LastFrameTime;
        m_LastFrameTime = time;

        OnUpdate(d_time);

        auto [x, y] = Input::GetMousePos();
        PA_ENGINE_TRACE("Mouse Position: {0} {1}", x, y);
      }
    }

    void Application::OnUpdate(Util::DeltaTime t)
    {
      PA_ENGINE_TRACE("{0}", t.ToString());

      m_Window->OnUpdate();

      for (Layer* layer : m_LayerStack)
      {
        layer->OnUpdate(t);
      }
    }

    void Application::OnEvent(Event& e)
    {
      PA_ENGINE_TRACE("{0}", e);
     
      EventDispatcher dispatcher(e);
      dispatcher.Dispatch<WindowClosedEvent>(BIND_EVENT_FN(Application, OnWindowClosed));
      dispatcher.Dispatch<WindowResizedEvent>(BIND_EVENT_FN(Application, OnWindowResized));

      auto rit = m_LayerStack.rbegin();
      while (rit != m_LayerStack.rend())
      {
        (*rit)->OnEvent(e);
        rit++;
      }
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
#pragma endregion
  }
}