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

/************************************************************************************
* [SECTION] FORWARD DECLARATIONS
************************************************************************************/

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
    class AURORA_ENGINE_API Application
    {
    public:
      Application();
      virtual ~Application();

      inline static Application& Get() { return *s_Instance; }

      void Run();

      void OnUpdate(Util::DeltaTime t);
      void OnEvent(Event& e);

      void PushLayer(Layer* layer);
      void PushOverlay(Layer* overlay);

      inline Window& GetWindow() { return *m_Window; }

    private:
      // Event handlers
      bool OnWindowClosed(WindowClosedEvent& e);
      bool OnWindowResized(WindowResizedEvent& e);

      std::unique_ptr<Window> m_Window;
      bool m_Running = true;
      LayerStack m_LayerStack;
      float m_LastFrameTime = 0;

    private:
      static Application* s_Instance;
    };

/************************************************************************************
* [SECTION] FUNCTIONS
************************************************************************************/
    Application* CreateApplication(); // To be defined in client

/************************************************************************************
* [SECTION] MACROS
************************************************************************************/
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
  }
}

