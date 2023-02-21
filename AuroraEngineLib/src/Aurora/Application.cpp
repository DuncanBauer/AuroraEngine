#include "AuroraEngineLibPCH.h"

#include "Application.h"

#include "Aurora/Event/ApplicationEvent.h"
#include "Aurora/Event/MouseEvent.h"
#include "Aurora/Log.h"
#include "Window.h"

#include <GLFW/glfw3.h>

namespace Aurora 
{
  Application::Application()
  {
    m_Window = std::unique_ptr<Window>(Window::Create());
  }

  Application::~Application()
  {

  }

  void Application::Run()
  {
    while (m_Running)
    {
      glClearColor(1, 0, 1, 1);
      glClear(GL_COLOR_BUFFER_BIT);
      m_Window->OnUpdate();

    }
  }
}