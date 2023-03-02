#pragma once
#include "Aurora/Core/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Aurora
{
  class AURORA_ENGINE_API OpenGLContext : public GraphicsContext
  {
  public:
    OpenGLContext(GLFWwindow* windowHandle);
    virtual void Init() override;
    virtual void SwapBuffers() override;

  private:
    GLFWwindow* pm_WindowHandle;
  };
}