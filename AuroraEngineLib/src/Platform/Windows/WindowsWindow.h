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
#include "Aurora/Core/Window.h"

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

      void OnUpdate() const override;

      inline std::string GetTitle() const override { return m_Props.Title; }
      inline unsigned int GetWidth() const override { return m_Props.Width; }
      inline unsigned int GetHeight() const override { return m_Props.Height; }

      inline void SetEventCallback(const EventCallbackFn& callback) override { m_Props.EventCallback = callback; }
      void SetVSync(bool enabled);
      bool IsVSync() const;

    private:
      virtual void Init(const WindowProperties& props);
      virtual void Shutdown();

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
}