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
#include "Aurora/Core/Input.h"

// C++ Standard Library Headers

// Third Party Library Headers
#pragma endregion

#pragma region ForwardDeclarations
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
    class AURORA_ENGINE_API WindowsInput : public Input
    {
      protected:
        virtual bool IsKeyPressedImpl(int key) override;
        virtual bool IsMouseButtonPressedImpl(int button) override;
        virtual std::pair<float, float> GetMousePosImpl() override;
        virtual float GetMouseXImpl() override;
        virtual float GetMouseYImpl() override;
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