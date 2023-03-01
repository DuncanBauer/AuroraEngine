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
// Aurora Engine  
#include "Core.h"
#include "Util.h"
#include "Window.h"
#include "Event/Event.h"
#include "Event/ApplicationEvent.h"
#include "Event/KeyEvent.h"
#include "Event/MouseEvent.h"
#include "Aurora/Core/Layer/LayerStack.h"

// C++ Standard Library Headers

// Third Party Library Headers
#pragma endregion

namespace Aurora
{
  namespace Engine
  {
/************************************************************************************
* [SECTION] FORWARD DECLARATIONS
************************************************************************************/
#pragma region Forward Declarations
    class ImGuiLayer;
#pragma endregion

/************************************************************************************
* [SECTION] TYPENAMES
************************************************************************************/
#pragma region Typenames
#pragma endregion

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
    class AURORA_ENGINE_API Application
    {
    public:
      Application();
      virtual ~Application();

      inline static Application& Get() { return *ps_Instance; }

      void Run();

      void OnUpdate(Util::DeltaTime t);
      void OnEvent(Event& e);

      void PushLayer(Layer* layer);
      void PushOverlay(Layer* overlay);

      inline Window& GetWindow() { return *pm_Window; }

    private:
      bool OnWindowClosed(WindowClosedEvent& e);
      bool OnWindowResized(WindowResizedEvent& e);

    private:
      std::unique_ptr<Window> pm_Window;
      ImGuiLayer* pm_ImGuiLayer;
      bool m_Running = true;
      LayerStack m_LayerStack;
      float m_LastFrameTime = 0;

      static Application* ps_Instance;
    };
#pragma endregion

/************************************************************************************
* [SECTION] FUNCTIONS
************************************************************************************/
#pragma region Functions
    Application* CreateApplication(); // To be defined in client
#pragma endregion

/************************************************************************************
* [SECTION] MACROS
************************************************************************************/
#pragma region Macros
#pragma endregion
  }
}

