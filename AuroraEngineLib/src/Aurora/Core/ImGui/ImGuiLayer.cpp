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
#include "ImGuiLayer.h"
#include "Aurora/Core/Application.h"

// C++ Headers

// Third Party Library Headers
#include "imgui.h"
#include "backends/imgui_impl_glfw.h" 
#include "backends/imgui_impl_opengl3.h"
#include <glad/glad.h>
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
#pragma endregion

/************************************************************************************
* [SECTION] FUNCTIONS
************************************************************************************/
#pragma region Functions
    ImGuiLayer::ImGuiLayer() : Layer()
    {
    }
    
    ImGuiLayer::~ImGuiLayer() 
    {
    }

    void ImGuiLayer::OnAttach() 
    {
      IMGUI_CHECKVERSION();
      ImGui::CreateContext();

      ImGuiIO& io = ImGui::GetIO();
      io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
      io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
      io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
      io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
      io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows

      ImGui::StyleColorsDark();
      ImGuiStyle& style = ImGui::GetStyle();
      if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
      {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
      }

      ImGui_ImplGlfw_InitForOpenGL(glfwGetCurrentContext(), true);
      ImGui_ImplOpenGL3_Init("#version 410");
    }

    void ImGuiLayer::OnDetach() 
    {
      ImGui_ImplOpenGL3_Shutdown();
      ImGui_ImplGlfw_Shutdown();
      ImGui::DestroyContext();
    }

    void ImGuiLayer::Begin()
    {
      ImGuiIO& io = ImGui::GetIO();
      Application& app = Application::Get();

      float time = Util::Time::GetTimeSeconds();
      io.DeltaTime = m_Time > 0.0 ? (time - m_Time) : (1.0f / 60.0f);
      m_Time = time;

      ImGui_ImplGlfw_NewFrame();
      ImGui_ImplOpenGL3_NewFrame();
      ImGui::NewFrame();
    }

    void ImGuiLayer::End()
    {
      ImGuiIO& io = ImGui::GetIO();
      Application& app = Application::Get();

      int x = app.GetWindow().GetWidth();
      int y = app.GetWindow().GetHeight();

      ImGui::Render();
      glfwGetFramebufferSize(glfwGetCurrentContext(), &x, &y);
      glViewport(0, 0, x, y);
      glClearColor(1, 0, 1, 1);
      glClear(GL_COLOR_BUFFER_BIT);
      ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

      // Update and Render additional Platform Windows
      // (Platform functions may change the current OpenGL context, so we save/restore it to make it easier to paste this code elsewhere.
      //  For this specific demo app we could also call glfwMakeContextCurrent(window) directly)
      if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
      {
        GLFWwindow* backup_current_context = glfwGetCurrentContext();
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        glfwMakeContextCurrent(backup_current_context);
      }
    }
    
    void ImGuiLayer::OnUpdate(Aurora::Util::DeltaTime t)
    {
      PA_ENGINE_TRACE("ImGuiLayer::OnUpdate");

      Begin();

      static bool show_demo = false;
      ImGui::ShowDemoWindow(&show_demo);

      End();
    }

    void ImGuiLayer::OnEvent(Aurora::Engine::Event& e)
    {
      PA_ENGINE_TRACE("ImGuiLayer::{0}", e);
      
      EventDispatcher dispatcher(e);
      dispatcher.Dispatch<WindowGainedFocusEvent>(BIND_EVENT_FN(ImGuiLayer, OnWindowGainedFocus));
      dispatcher.Dispatch<WindowLostFocusEvent>(BIND_EVENT_FN(ImGuiLayer, OnWindowLoseFocus));
      dispatcher.Dispatch<WindowClosedEvent>(BIND_EVENT_FN(ImGuiLayer, OnWindowClosed));
      dispatcher.Dispatch<WindowMaximizedEvent>(BIND_EVENT_FN(ImGuiLayer, OnWindowMaximized));
      dispatcher.Dispatch<WindowMinimizedEvent>(BIND_EVENT_FN(ImGuiLayer, OnWindowMinimized));
      dispatcher.Dispatch<WindowRestoredEvent>(BIND_EVENT_FN(ImGuiLayer, OnWindowRestored));
      dispatcher.Dispatch<WindowMovedEvent>(BIND_EVENT_FN(ImGuiLayer, OnWindowMoved));
      dispatcher.Dispatch<WindowResizedEvent>(BIND_EVENT_FN(ImGuiLayer, OnWindowResized));

      dispatcher.Dispatch<MouseButtonPressedEvent>(BIND_EVENT_FN(ImGuiLayer, OnMouseButtonPressedEvent));
      dispatcher.Dispatch<MouseButtonReleasedEvent>(BIND_EVENT_FN(ImGuiLayer, OnMouseButtonReleasedEvent));
      dispatcher.Dispatch<MouseMovedEvent>(BIND_EVENT_FN(ImGuiLayer, OnMouseMovedEvent));
      dispatcher.Dispatch<MouseScrolledEvent>(BIND_EVENT_FN(ImGuiLayer, OnMouseScrolledEvent));

      dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FN(ImGuiLayer, OnKeyboardButtonPressedEvent));
      dispatcher.Dispatch<KeyReleasedEvent>(BIND_EVENT_FN(ImGuiLayer, OnKeyboardButtonReleasedEvent));
    }

    bool ImGuiLayer::OnWindowGainedFocus(Aurora::Engine::WindowGainedFocusEvent& e)
    {
      ImGuiIO& io = ImGui::GetIO();
      
      return IsBlocking();
    }

    bool ImGuiLayer::OnWindowLoseFocus(Aurora::Engine::WindowLostFocusEvent& e)
    {
      ImGuiIO& io = ImGui::GetIO();
      
      return IsBlocking();
    }

    bool ImGuiLayer::OnWindowClosed(Aurora::Engine::WindowClosedEvent& e)
    {
      ImGuiIO& io = ImGui::GetIO();
      
      return IsBlocking();
    }

    bool ImGuiLayer::OnWindowMaximized(Aurora::Engine::WindowMaximizedEvent& e)
    {
      ImGuiIO& io = ImGui::GetIO();
      
      return IsBlocking();
    }

    bool ImGuiLayer::OnWindowMinimized(Aurora::Engine::WindowMinimizedEvent& e)
    {
      ImGuiIO& io = ImGui::GetIO();
      
      return IsBlocking();
    }

    bool ImGuiLayer::OnWindowRestored(Aurora::Engine::WindowRestoredEvent& e)
    {
      ImGuiIO& io = ImGui::GetIO();
      
      return IsBlocking();
    }

    bool ImGuiLayer::OnWindowMoved(Aurora::Engine::WindowMovedEvent& e)
    {
      ImGuiIO& io = ImGui::GetIO();
      return IsBlocking();
    }

    bool ImGuiLayer::OnWindowResized(Aurora::Engine::WindowResizedEvent& e)
    {
      ImGuiIO& io = ImGui::GetIO();
      io.DisplaySize = ImVec2(e.GetWidth(), e.GetHeight());
      io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
      glViewport(0, 0, e.GetWidth(), e.GetWidth());
      return IsBlocking();
    }
 
    bool ImGuiLayer::OnMouseButtonPressedEvent(Aurora::Engine::MouseButtonPressedEvent& e)
    {
      ImGuiIO& io = ImGui::GetIO();
      io.MouseDown[e.GetMouseButton()] = true;
      return IsBlocking();
    }
    
    bool ImGuiLayer::OnMouseButtonReleasedEvent(Aurora::Engine::MouseButtonReleasedEvent& e)
    {
      ImGuiIO& io = ImGui::GetIO();
      io.MouseDown[e.GetMouseButton()] = false;
      return IsBlocking();
    }
    
    bool ImGuiLayer::OnMouseScrolledEvent(Aurora::Engine::MouseScrolledEvent& e)
    {
      ImGuiIO& io = ImGui::GetIO();
      io.MouseWheelH += e.GetXOffset();
      io.MouseWheel += e.GetYOffset();
      return IsBlocking();
    }

    bool ImGuiLayer::OnMouseMovedEvent(Aurora::Engine::MouseMovedEvent& e)
    {
      ImGuiIO& io = ImGui::GetIO();
      io.MousePos = ImVec2(e.GetX(), e.GetY());
      return IsBlocking();
    }
    
    bool ImGuiLayer::OnKeyboardButtonPressedEvent(Aurora::Engine::KeyPressedEvent& e)
    {
      ImGuiIO& io = ImGui::GetIO();
      io.KeysDown[e.GetKey()] = true;
      return IsBlocking();
    }
    
    bool ImGuiLayer::OnKeyboardButtonReleasedEvent(Aurora::Engine::KeyReleasedEvent& e)
    {
      ImGuiIO& io = ImGui::GetIO();
      io.KeysDown[e.GetKey()] = false;
      return IsBlocking();
    }
#pragma endregion
  }
}