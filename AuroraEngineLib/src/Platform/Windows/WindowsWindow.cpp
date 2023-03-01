// Aurora Engine Library, v0.0.1 ALPHA
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
#include "Aurora/Core/Util.h"
#include "WindowsWindow.h"
#include "Aurora/Core/Event/ApplicationEvent.h"
#include "Aurora/Core/Event/KeyEvent.h"
#include "Aurora/Core/Event/MouseEvent.h"

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
#pragma region Static Initialization
/************************************************************************************
* [SECTION] STATIC VARIABLE INITIALIZATION
************************************************************************************/
    static bool GLFWInitialized = false;
#pragma endregion

#pragma region Functions
    /************************************************************************************
* [SECTION] FUNCTIONS
************************************************************************************/
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

      // Init GLFW
      if (!GLFWInitialized)
      {
        int success = glfwInit();
        PA_ENGINE_ASSERT(success, "Could not initialized GLFW!")

        glfwSetErrorCallback([](int error_code, const char* description)
        {
          PA_ENGINE_ERROR("GLFW ERROR: ({0}): {1}", error_code, description);
        });

        GLFWInitialized = true;
      }

      // Initialize Window
      m_Window = glfwCreateWindow((int)m_Props.Width, (int)m_Props.Height, m_Props.Title.c_str(), nullptr, nullptr);
      glfwMakeContextCurrent(m_Window);
      int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
      PA_ENGINE_ASSERT(status, "Failed to initialize Glad");
      glfwSetWindowUserPointer(m_Window, &m_Props);
      SetVSync(true);

      /******************
      *
      *  GLFW Callbacks
      *
      ******************/
      // Window Callbacks
      glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
      {
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
        WindowClosedEvent e;
        data.EventCallback(e);
      });

      glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
      {
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
        data.Width = width;
        data.Height = height;

        WindowResizedEvent e(width, height);
        data.EventCallback(e);
      });

      glfwSetWindowFocusCallback(m_Window, [](GLFWwindow* window, int focused)
      {
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
        data.Focused = focused;

        if (focused == GLFW_TRUE)
        {
          WindowGainedFocusEvent e(focused);
          data.EventCallback(e);
        }
        else if (focused == GLFW_FALSE)
        {
          WindowLostFocusEvent e(focused);
          data.EventCallback(e);
        }
      });

      glfwSetWindowMaximizeCallback(m_Window, [](GLFWwindow* window, int maximized)
      {
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
        data.Maximized = maximized;

        if (maximized == GLFW_TRUE)
        {
          WindowMaximizedEvent e(maximized);
          data.EventCallback(e);
        }
        else if (maximized == GLFW_FALSE)
        {
          WindowRestoredEvent e(maximized);
          data.EventCallback(e);
        }
      });

      // Why does glfw use Iconified instead of Minimized?
      glfwSetWindowIconifyCallback(m_Window, [](GLFWwindow* window, int iconified)
      {
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
        data.Iconified = iconified;

        if (iconified == GLFW_TRUE)
        {
          WindowMinimizedEvent e(iconified);
          data.EventCallback(e);
        }
        else if (iconified == GLFW_FALSE)
        {
          WindowRestoredEvent e(iconified);
          data.EventCallback(e);
        }
      });

      glfwSetWindowPosCallback(m_Window, [](GLFWwindow* window, int xpos, int ypos)
      {
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
        data.Xpos = xpos;
        data.Ypos = ypos;

        WindowMovedEvent e(xpos, ypos);
        data.EventCallback(e);
      });

      // Key Callbacks
      glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
      {
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

        switch (action)
        {
          case GLFW_PRESS:
          {
            KeyPressedEvent e(key, 0);
            data.EventCallback(e);
            break;
          }
          case GLFW_RELEASE:
          {
            KeyReleasedEvent e(key);
            data.EventCallback(e);
            break;
          }
          case GLFW_REPEAT:
          {
            KeyPressedEvent e(key, 1);
            data.EventCallback(e);
            break;
          }
        }
      });

      glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int key)
      {
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
        KeyTypedEvent e(key);
        data.EventCallback(e);
      });

      // Mouse Callbacks
      glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
      {
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

        switch (action)
        {
          case GLFW_PRESS:
          {
            MouseButtonPressedEvent e(button);
            data.EventCallback(e);
            break;
          }
          case GLFW_RELEASE:
          {
            MouseButtonReleasedEvent e(button);
            data.EventCallback(e);
            break;
          }
        }
      });

      glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset)
      {
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

        MouseScrolledEvent e(xoffset, yoffset);
        data.EventCallback(e);
      });

      glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos)
      {
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

        MouseMovedEvent e(xpos, ypos);
        data.EventCallback(e);
      });
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
#pragma endregion
  }
}