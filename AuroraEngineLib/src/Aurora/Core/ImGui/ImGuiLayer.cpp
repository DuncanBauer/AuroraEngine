#include "AuroraEngineLibPCH.h"

#include "ImGuiLayer.h"

#include "Aurora/Core/Application.h"
#include <Util.h>

#include "imgui.h"
#include "backends/imgui_impl_glfw.h" 
#include "backends/imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>

namespace Aurora
{
  namespace Engine
  {

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
    }

    void ImGuiLayer::OnUpdate(Aurora::Util::DeltaTime t)
    {
      PA_ENGINE_TRACE("ImGuiLayer::OnUpdate");

      ImGuiIO& io = ImGui::GetIO();

      Application& app = Application::Get();
      io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());
      int x = static_cast<int>(io.DisplaySize.x);
      int y = static_cast<int>(io.DisplaySize.y);

      float time = Util::Time::GetTime();
      io.DeltaTime = m_Time > 0.0 ? (time - m_Time) : (1.0f / 60.0f);
      m_Time = time;


      ImGui_ImplGlfw_NewFrame();
      ImGui_ImplOpenGL3_NewFrame();
      ImGui::NewFrame();

      static bool show_demo = true;
      ImGui::ShowDemoWindow(&show_demo);


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

    void ImGuiLayer::OnEvent(Aurora::Engine::Event& e)
    {
      PA_ENGINE_TRACE("ImGuiLayer::OnEvent");
    }
  }
}