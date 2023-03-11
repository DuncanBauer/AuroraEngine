#include "AuroraEnginePCH.h"

#include "OpenGLContext.h"
#include "Aurora/Core/Util.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Aurora
{
  OpenGLContext::OpenGLContext(GLFWwindow* windowHandle) : pm_WindowHandle(windowHandle)
  {
  }

  void OpenGLContext::Init()
  {
    glfwMakeContextCurrent(pm_WindowHandle);
    int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    PA_ENGINE_ASSERT(status, "Failed to initialize Glad");
  }

  void OpenGLContext::SwapBuffers()
  {
    glBegin(GL_TRIANGLES);
    glEnd();

    glfwSwapBuffers(pm_WindowHandle);
  }
}