#include "AuroraEngineLibPCH.h"

#include "ImGuiLayer.h"

#include "Aurora/Core/Application.h"
#include <Util.h>

#include "imgui.h"
#include "backends/imgui_impl_glfw.h" 
#include "backends/imgui_impl_opengl3.h"




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
      ImGui::CreateContext();
      ImGui::StyleColorsDark();

      ImGuiIO& io = ImGui::GetIO();
      io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
      io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

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

      ImGui_ImplOpenGL3_NewFrame();
      ImGui::NewFrame();

      float time = Util::Time::GetTime();
      io.DeltaTime = m_Time > 0.0 ? (time - m_Time) : (1.0f / 60.0f);
      m_Time = time;



      static bool show_demo = true;
      ImGui::ShowDemoWindow(&show_demo);

      ImGui::Render();
      ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void ImGuiLayer::OnEvent(Aurora::Engine::Event& e)
    {
      PA_ENGINE_TRACE("ImGuiLayer::OnEvent");
    }
  }
}