// Aurora Engine Lib
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

#pragma region Includes
/************************************************************************************
* [SECTION] INCLUDES
************************************************************************************/
// PCH
#include "AuroraEngineLibPCH.h"

// Project Specific Header
#include "Aurora/Core/Application.h"
#include "WindowsInput.h"

// C++ Headers

// Third Party Library Headers
#include <GLFW/glfw3.h>
#pragma endregion

namespace Aurora
{
  namespace Engine
  {
#pragma region StaticInitialization
/************************************************************************************
* [SECTION] STATIC VARIABLE INITIALIZATION
************************************************************************************/
    Input* Input::s_Instance = new WindowsInput();      // Seems dangerous but Input doesn't manage any memory. It only acts as a container for various input functions.
#pragma endregion

#pragma region Functions
/************************************************************************************
* [SECTION] FUNCTIONS
************************************************************************************/
    bool WindowsInput::IsKeyPressedImpl(int key)
    {
      auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
      auto state = glfwGetKey(window, key);
      return (state == GLFW_PRESS);
    }

    bool WindowsInput::IsMouseButtonPressedImpl(int button)
    {
      auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
      auto state = glfwGetMouseButton(window, button);
      return state == GLFW_PRESS;
    }

    std::pair<float, float> WindowsInput::GetMousePosImpl()
    {
      auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
      double xpos, ypos;
      glfwGetCursorPos(window, &xpos, &ypos);
      return { (float)xpos, (float)ypos };
    }

    float WindowsInput::GetMouseXImpl()
    {
      auto [x, y] = GetMousePosImpl();
      return x;
    }

    float WindowsInput::GetMouseYImpl()
    {
      auto [x, y] = GetMousePosImpl();
      return y;
    }
#pragma endregion
  }
}