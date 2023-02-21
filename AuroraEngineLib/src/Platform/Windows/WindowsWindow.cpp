#include "AuroraEngineLibPCH.h"

#include "WindowsWindow.h"

#include "Aurora/Log.h"

namespace Aurora
{
  static bool GLFWInitialized = false;

  Window* Window::Create(const WindowProperties& props)
  {
    return new WindowsWindow(props);
  }

  WindowsWindow::WindowsWindow(const WindowProperties& props)
  {
    Init(props);
  }

  WindowsWindow::~WindowsWindow()
  {
    Shutdown();
  }

  void WindowsWindow::Init(const WindowProperties& props)
  {
    m_Props.Title = props.Title;
    m_Props.Width = props.Width;
    m_Props.Height = props.Height;
  
    AE_ENGINE_INFO("Creating Windows {0} ({1}, {2})", m_Props.Title, m_Props.Width, m_Props.Height);
  
    if (!GLFWInitialized)
    {
      int success = glfwInit();
      AE_ENGINE_ASSERT(success, "Could not initialized GLFW!");

      GLFWInitialized = true;
    }

    m_Window = glfwCreateWindow((int)m_Props.Width, (int)m_Props.Height, m_Props.Title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(m_Window);
    glfwSetWindowUserPointer(m_Window, &m_Props);
    SetVSync(true);
  }

  void WindowsWindow::OnUpdate() const
  {
    glfwPollEvents();
    glfwSwapBuffers(m_Window);
  }

  void WindowsWindow::Shutdown()
  {
    glfwDestroyWindow(m_Window);
  }

  void WindowsWindow::SetVSync(bool enabled)
  {
    if (enabled)
    {
      glfwSwapInterval(1);
    }
    else
    {
      glfwSwapInterval(0);
    }

    m_Props.VSync = enabled;
  }

  bool WindowsWindow::IsVSync() const
  {
    return m_Props.VSync;
  }

}