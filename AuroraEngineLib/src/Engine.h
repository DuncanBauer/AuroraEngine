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

#pragma once

#pragma region Preprocessor
/************************************************************************************
* [SECTION] PREPROCESSOR DIRECTIVES
************************************************************************************/
// Library Version
// (Integer encoded as XYYZZ for use in #if preprocessor conditionals, e.g. '#if AURORA_UTIL_VERSION_NUM > 12345')
#define AURORA_ENGINE_VERSION     "0.0.1 ALPHA"
#define AURORA_ENGINE_VERSION_NUM 00001
//#define IMGUI_API __declspec(dllexport)
#pragma endregion

#pragma region Includes
/************************************************************************************
* [SECTION] INCLUDES
************************************************************************************/
// Project Specific Headers
#include "Aurora/Core/Application.h"

#include "Aurora/Core/Input.h"
#include "Aurora/Core/Event/Event.h"
#include "Aurora/Core/Event/KeyCodes.h"
#include "Aurora/Core/Event/MouseCodes.h"

#include "Aurora/Core/Layer/Layer.h"
#include "Aurora/Core/Layer/LayerStack.h"
#include "Aurora/Core/Layer/ImGui/ImGuiLayer.h"

/****************************
* ENTRY POINT
****************************/
#include "Aurora/Core/EntryPoint.h"

// C++ Standard Library Headers

// Third Party Library Headers
#pragma endregion