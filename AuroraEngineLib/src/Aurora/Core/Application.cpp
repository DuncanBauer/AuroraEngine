// Aurora Engine Library
// Source file

// For more information visit: https://github.com/DuncanBauer/ProjectAurora

// Developed by Duncan Bauer and every direct or indirect contributors to the GitHub.
// LICENSING INFORMATION

// It is recommended that you don't modify any source code! It will become difficult for you to update the library.
// Note that 'Aurora::' being a namespace, you can add functions into the namespace from your own source files, without
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
#include "Layer/ImGui/ImGuiLayer.h"

// C++ Headers

// Third Party Library Headers
// Glad 
#include <glad/glad.h>

// GLFW
#include <GLFW/glfw3.h>
#pragma endregion

namespace Aurora
{
/************************************************************************************
* [SECTION] STATIC VARIABLE INITIALIZATION
************************************************************************************/
#pragma region Static Initialization
    Application* Application::ps_Instance = nullptr;
#pragma endregion

/************************************************************************************
* [SECTION] FUNCTIONS
************************************************************************************/
#pragma region Functions
    Application::Application()
    {
      ps_Instance = this;

      pm_Window = std::unique_ptr<Window>(Window::Create());
      pm_Window->SetEventCallback(BIND_EVENT_FN(Application, OnEvent));

      pm_ImGuiLayer = new ImGuiLayer(false);
      PushOverlay(pm_ImGuiLayer);

      glGenVertexArrays(1, &m_VA);
      glBindVertexArray(m_VA);

      glGenBuffers(1, &m_VB);
      glBindBuffer(GL_ARRAY_BUFFER, m_VB);

      float vertices[3 * 3] = {
        -0.5f, -0.5f, 0.0f,
        0.5f,  -0.5f, 0.0f,
        0.0f,   0.5f, 0.0f
      };
      glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
      
      glEnableVertexAttribArray(0);
      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

      glGenBuffers(1, &m_IB);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IB);

      unsigned int indices[3] = {0, 1, 2};
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
      while (m_Running)
      {
        glClearColor(0.1f, 0.1f, 0.1f, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glBindVertexArray(m_VA);
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);


        float time = (float)Time::GetTimeSeconds();
        DeltaTime d_time = time - m_LastFrameTime;
        m_LastFrameTime = time;

        OnUpdate(d_time); // This must be last apparently?
        OnRender();
      }
    }

    void Application::OnUpdate(DeltaTime t)
    {
      for (Layer* layer : m_LayerStack)
      {
        layer->OnUpdate();
      }
      pm_Window->OnUpdate();
    }

    void Application::OnRender()
    {
      // ImGui Rendering
      pm_ImGuiLayer->Begin();
      {
        for (Layer* layer : m_LayerStack)
        {
          layer->OnImGuiRender();
        }
      }
      pm_ImGuiLayer->End();
      pm_Window->OnRender();
    }

    void Application::OnEvent(Event& e)
    {
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