// Aurora Engine Library, v0.0.1 ALPHA
// Header file

// For more information visit: https://github.com/DuncanBauer/ProjectAurora#table-of-contents

// Developed by Duncan Bauer and every direct or indirect contributors to the GitHub.
// LICENSING INFORMATION

// It is recommended that you don't modify any source code! It will become difficult for you to update the library.
// Note that 'Aurora::Util::' being a namespace, you can add functions into the namespace from your own source files, without
// modifying Util.h or Util.cpp. Discussing your changes on the GitHub Issue Tracker may lead you
// to a better solution or official support for them.

// Index of this file:
// CODE
//   - [SECTION] PREPROCESSOR DIRECTIVES
//   - [SECTION] INCLUDES
//   - [SECTION] FORWARD DECLARATIONS
//   - [SECTION] TYPENAMES
//   - [SECTION] CONSTANTS
//   - [SECTION] ENUMS
//   - [SECTION] CLASSES
//   - [SECTION] STRUCTS
//   - [SECTION] FUNCTIONS
//   - [SECTION] MACROS

/************************************************************************************
* [SECTION] PREPROCESSOR DIRECTIVES
************************************************************************************/
#pragma once

/************************************************************************************
* [SECTION] INCLUDES
************************************************************************************/
// Project Specific Headers
#include "Aurora/Core/Event/Event.h"
#include "Aurora/Core/Event/ApplicationEvent.h"
#include "Aurora/Core/Event/MouseEvent.h"
#include "Aurora/Core/Event/KeyEvent.h"
#include "Aurora/Core/Layer/Layer.h"

// C++ Standard Library Headers

// Third Party Library Headers

/************************************************************************************
* [SECTION] FORWARD DECLARATIONS
************************************************************************************/
struct GLFWwindow;
struct GLFWmonitor;

/************************************************************************************
* [SECTION] TYPENAMES
************************************************************************************/

namespace Aurora
{
  namespace Engine
  {
/************************************************************************************
* [SECTION] CONSTANTS
************************************************************************************/

/************************************************************************************
* [SECTION] ENUMS
************************************************************************************/

/************************************************************************************
* [SECTION] STRUCTS
************************************************************************************/

/************************************************************************************
* [SECTION] CLASSES
************************************************************************************/
    class AURORA_ENGINE_API ImGuiLayer : public Layer
    {
      public:
        ImGuiLayer();
        ~ImGuiLayer();

        void OnAttach();
        void OnDetach();

        void Begin();
        void End();

        void OnUpdate(Aurora::Util::DeltaTime t) override;
        void OnEvent(Aurora::Engine::Event& e) override;

      private:
        bool OnWindowGainedFocus(Aurora::Engine::WindowGainedFocusEvent& e);
        bool OnWindowLoseFocus(Aurora::Engine::WindowLostFocusEvent& e);
        bool OnWindowClosed(Aurora::Engine::WindowClosedEvent& e);
        bool OnWindowMaximized(Aurora::Engine::WindowMaximizedEvent& e);
        bool OnWindowMinimized(Aurora::Engine::WindowMinimizedEvent& e);
        bool OnWindowRestored(Aurora::Engine::WindowRestoredEvent& e);
        bool OnWindowMoved(Aurora::Engine::WindowMovedEvent& e);
        bool OnWindowResized(Aurora::Engine::WindowResizedEvent& e);
        
        bool OnMouseButtonPressedEvent(Aurora::Engine::MouseButtonPressedEvent& e);
        bool OnMouseButtonReleasedEvent(Aurora::Engine::MouseButtonReleasedEvent& e);
        bool OnMouseScrolledEvent(Aurora::Engine::MouseScrolledEvent& e);
        bool OnMouseMovedEvent(Aurora::Engine::MouseMovedEvent& e);
        
        bool OnKeyboardButtonPressedEvent(Aurora::Engine::KeyPressedEvent& e);
        bool OnKeyboardButtonReleasedEvent(Aurora::Engine::KeyReleasedEvent& e);

      private:
        float m_Time = 0.0f;
    };

/************************************************************************************
* [SECTION] FUNCTIONS
************************************************************************************/

/************************************************************************************
* [SECTION] MACROS
************************************************************************************/
  }
}
