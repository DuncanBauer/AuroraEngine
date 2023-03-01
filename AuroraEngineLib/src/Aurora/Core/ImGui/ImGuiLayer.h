// Aurora Engine Library, v0.0.1 ALPHA
// Header file

// For more information visit: https://github.com/DuncanBauer/ProjectAurora#table-of-contents

// Developed by Duncan Bauer and every direct or indirect contributors to the GitHub.
// LICENSING INFORMATION

// It is recommended that you don't modify any source code! It will become difficult for you to update the library.
// Note that 'Aurora::' being a namespace, you can add functions into the namespace from your own source files, without
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

#pragma once

/************************************************************************************
* [SECTION] PREPROCESSOR DIRECTIVES
************************************************************************************/
#pragma region Preprocessor
#pragma endregion

/************************************************************************************
* [SECTION] INCLUDES
************************************************************************************/
#pragma region Includes
// Project Specific Headers
#include "Aurora/Core/Event/Event.h"
#include "Aurora/Core/Event/ApplicationEvent.h"
#include "Aurora/Core/Event/MouseEvent.h"
#include "Aurora/Core/Event/KeyEvent.h"
#include "Aurora/Core/Layer/Layer.h"

// C++ Standard Library Headers

// Third Party Library Headers
#pragma endregion

/************************************************************************************
* [SECTION] FORWARD DECLARATIONS
************************************************************************************/
#pragma region Forward Declarations
struct GLFWwindow;
struct GLFWmonitor;
#pragma endregion

/************************************************************************************
* [SECTION] TYPENAMES
************************************************************************************/
#pragma region Typenames
#pragma endregion

namespace Aurora
{
/************************************************************************************
* [SECTION] CONSTANTS
************************************************************************************/
#pragma region Constants
#pragma endregion

/************************************************************************************
* [SECTION] ENUMS
************************************************************************************/
#pragma region Enums
#pragma endregion

/************************************************************************************
* [SECTION] STRUCTS
************************************************************************************/
#pragma region Structs
#pragma endregion

/************************************************************************************
* [SECTION] CLASSES
************************************************************************************/
#pragma region Classes
    class AURORA_ENGINE_API ImGuiLayer : public Layer
    {
      public:
        ImGuiLayer() {}
        ImGuiLayer(bool _blocking) : Layer(_blocking) {}
        ~ImGuiLayer() {}

        void OnAttach();
        void OnDetach();

        void Begin();
        void End();

        void OnUpdate() override;
        void OnImGuiRender() override;
        void OnEvent(Aurora::Event& e) override;

      private:
      // Handled in GLFW and OPENGL backends
        //bool OnWindowGainedFocus(Aurora::WindowGainedFocusEvent& e);
        //bool OnWindowLoseFocus(Aurora::WindowLostFocusEvent& e);
        //bool OnWindowClosed(Aurora::WindowClosedEvent& e);
        //bool OnWindowMaximized(Aurora::WindowMaximizedEvent& e);
        //bool OnWindowMinimized(Aurora::WindowMinimizedEvent& e);
        //bool OnWindowRestored(Aurora::WindowRestoredEvent& e);
        //bool OnWindowMoved(Aurora::WindowMovedEvent& e);
        //bool OnWindowResized(Aurora::WindowResizedEvent& e);
        //
        //bool OnMouseButtonPressedEvent(Aurora::MouseButtonPressedEvent& e);
        //bool OnMouseButtonReleasedEvent(Aurora::MouseButtonReleasedEvent& e);
        //bool OnMouseScrolledEvent(Aurora::MouseScrolledEvent& e);
        //bool OnMouseMovedEvent(Aurora::MouseMovedEvent& e);
        //
        //bool OnKeyboardButtonPressedEvent(Aurora::KeyPressedEvent& e);
        //bool OnKeyboardButtonReleasedEvent(Aurora::KeyReleasedEvent& e);
        //bool OnKeyboardButtonTypedEvent(Aurora::KeyTypedEvent& e);

      private:
        float m_Time = 0.0f;
    };
#pragma endregion

/************************************************************************************
* [SECTION] FUNCTIONS
************************************************************************************/
#pragma region Functions
#pragma endregion

/************************************************************************************
* [SECTION] MACROS
************************************************************************************/
#pragma region Macros
#pragma endregion
}