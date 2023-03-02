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
#include "Aurora/Core/Window.h"
#include "Aurora/Core/Renderer/GraphicsContext.h"

// C++ Standard Library Headers

// Third Party Library Headers
#pragma endregion

namespace Aurora
{
/************************************************************************************
* [SECTION] FORWARD DECLARATIONS
************************************************************************************/
#pragma region Forward Declarations
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
    class AURORA_ENGINE_API WindowsWindow : public Window
    {
      public:
        WindowsWindow(const WindowProperties& props);
        virtual ~WindowsWindow();

        virtual void OnUpdate() const override;
        virtual void OnRender() const override;

        virtual inline std::string  GetTitle()  const override { return m_Props.Title; }
        virtual inline unsigned int GetWidth()  const override { return m_Props.Width; }
        virtual inline unsigned int GetHeight() const override { return m_Props.Height; }

        virtual inline void SetEventCallback(const EventCallbackFn& callback) override { m_Props.EventCallback = callback; }
        virtual void SetVSync(bool enabled);
        virtual bool IsVSync() const;

        virtual inline void* GetNativeWindow() const { return pm_Window; }

      protected:
        GLFWwindow* pm_Window;
        GraphicsContext* pm_Context;

      private:
        void Init(const WindowProperties& props);
        void Shutdown();

        struct WindowData
        {
          std::string Title;
          unsigned int Width, Height, Focused, Maximized, Iconified;
          int Xpos, Ypos;
          bool VSync;

          EventCallbackFn EventCallback;
        };

        WindowData m_Props;
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