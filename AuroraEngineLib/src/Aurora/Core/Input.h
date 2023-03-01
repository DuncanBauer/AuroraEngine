// Aurora Engine Lib
// Header file

// For more information visit: https://github.com/DuncanBauer/ProjectAurora

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

#pragma region Preprocessor
/************************************************************************************
* [SECTION] PREPROCESSOR DIRECTIVES
************************************************************************************/
#pragma endregion

#pragma region Includes
/************************************************************************************
* [SECTION] INCLUDES
************************************************************************************/
// Project Specific Headers
#include "Core.h"

// C++ Standard Library Headers

// Third Party Library Headers
#pragma endregion

#pragma region Forward Declarations
/************************************************************************************
* [SECTION] FORWARD DECLARATIONS
************************************************************************************/
#pragma endregion

#pragma region Typenames
/************************************************************************************
* [SECTION] TYPENAMES
************************************************************************************/
#pragma endregion

namespace Aurora
{
  namespace Engine
  {
#pragma region Constants
    /************************************************************************************
* [SECTION] CONSTANTS
************************************************************************************/
#pragma endregion

#pragma region Enums
/************************************************************************************
* [SECTION] ENUMS
************************************************************************************/
#pragma endregion

#pragma region Structs
/************************************************************************************
* [SECTION] STRUCTS
************************************************************************************/
#pragma endregion

#pragma region Classes
/************************************************************************************
* [SECTION] CLASSES
************************************************************************************/
    class AURORA_ENGINE_API Input
    {
      public:
        inline static bool IsKeyPressed(int key) { return s_Instance->IsKeyPressedImpl(key); }

        inline static bool IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressedImpl(button); }
        inline static std::pair<float, float> GetMousePos() { return s_Instance->GetMousePosImpl(); }
        inline static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
        inline static float GetMouseY() { return s_Instance->GetMouseYImpl(); }

      protected:
        virtual bool IsKeyPressedImpl(int key) = 0;

        virtual bool IsMouseButtonPressedImpl(int button) = 0;
        virtual std::pair<float, float> GetMousePosImpl() = 0;
        virtual float GetMouseXImpl() = 0;
        virtual float GetMouseYImpl() = 0;

      private:
        static Input* s_Instance;
    };
#pragma endregion

#pragma region Functions
    /************************************************************************************
* [SECTION] FUNCTIONS
************************************************************************************/
#pragma endregion

#pragma region Macros
/************************************************************************************
* [SECTION] MACROS
************************************************************************************/
#pragma endregion

  }
}