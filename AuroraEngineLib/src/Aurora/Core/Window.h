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
#include "Core.h"
#include "Event/Event.h"

// C++ Standard Library Headers

// Third Party Library Headers

/************************************************************************************
* [SECTION] FORWARD DECLARATIONS
************************************************************************************/
struct GLFWwindow;

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
    struct WindowProperties
    {
      std::string Title;
      unsigned int Width;
      unsigned int Height;

      WindowProperties(std::string _title = "Aurora Engine", unsigned int _width = 1280, unsigned int _height = 760)
        : Title(_title), Width(_width), Height(_height) {};
    };

/************************************************************************************
* [SECTION] CLASSES
************************************************************************************/
    class AURORA_ENGINE_API Window
    {
    public:
      using EventCallbackFn = std::function<void(Event&)>;

      virtual ~Window() {}
      inline GLFWwindow& GetGLFWwindow() { return *m_Window; }

      virtual void OnUpdate() const = 0;

      virtual std::string GetTitle() const = 0;
      virtual unsigned int GetWidth() const = 0;
      virtual unsigned int GetHeight() const = 0;

      virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
      virtual void SetVSync(bool enabled) = 0;
      virtual bool IsVSync() const = 0;

      static Window* Create(const WindowProperties& props = WindowProperties());

    protected:
      GLFWwindow* m_Window;
    };

/************************************************************************************
* [SECTION] FUNCTIONS
************************************************************************************/

/************************************************************************************
* [SECTION] MACROS
************************************************************************************/
  }
}