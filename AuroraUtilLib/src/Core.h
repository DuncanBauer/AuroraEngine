// Aurora Util Library, v0.0.1 ALPHA
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
//   - [SECTION] CLASSES
//   - [SECTION] STRUCTS
//   - [SECTION] FUNCTIONS
//   - [SECTION] MACROS

/************************************************************************************
* [SECTION] PREPROCESSOR DIRECTIVES
************************************************************************************/
#pragma once

// Define dllexport and dllimport for Windows
#ifdef PA_PLATFORM_WINDOWS
  #ifdef PA_UTIL_BUILD_DLL
    #define AURORA_UTIL_API _declspec(dllexport)
  #else
    #define AURORA_UTIL_API _declspec(dllimport)
  #endif
  #ifdef PA_ENGINE_BUILD_DLL
    #define AURORA_ENGINE_API _declspec(dllexport)
  #else
    #define AURORA_ENGINE_API _declspec(dllimport)
  #endif
  #ifdef PA_MAPLE_BUILD_DLL
    #define AURORA_MAPLE_API _declspec(dllexport)
  #else
    #define AURORA_MAPLE_API _declspec(dllimport)
  #endif
#else
  #error PROJECT AURORA ONLY SUPPORTS WINDOWS!
#endif

/************************************************************************************
* [SECTION] INCLUDES
************************************************************************************/
// Project Specific Headers
// C++ Standard Library Headers
// Third Party Library Headers

/************************************************************************************
* [SECTION] FORWARD DECLARATIONS
************************************************************************************/

/************************************************************************************
* [SECTION] TYPENAMES
************************************************************************************/

/************************************************************************************
* [SECTION] CONSTANTS
************************************************************************************/

/************************************************************************************
* [SECTION] CLASSES
************************************************************************************/

/************************************************************************************
* [SECTION] STRUCTS
************************************************************************************/

/************************************************************************************
* [SECTION] FUNCTIONS
************************************************************************************/

/************************************************************************************
* [SECTION] MACROS
************************************************************************************/
// Bitwise macros
// BIT macro that takes a single argument x and performs a bitwise left shift operation
// on the integer value 1 by x bits. The result of this operation is a binary number
// where the bit at position x is set to 1 and all other bits are set to 0.
#define BIT(x) (1 << x)

// Assert Macros for Project Aurora Libraries and projects made with Project Aurora Libraries
#ifdef PA_ASSERTS_ENABLED
  #define PA_UTIL_ASSERT(x, ...)    { if(!(x)) { PA_UTIL_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
  #define PA_MAPLE_ASSERT(x, ...)   { if(!(x)) { PA_MAPLE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
  #define PA_ENGINE_ASSERT(x, ...)  { if(!(x)) { PA_ENGINE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
  #define PA_PROJECT_ASSERT(x, ...) { if(!(x)) { PA_PROJECT_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
  #define PA_UTIL_ASSERT(x, ...)
  #define PA_MAPLE_ASSERT(x, ...)
  #define PA_ENGINE_ASSERT(x, ...)
  #define PA_PROJECT_ASSERT(x, ...)
#endif

// Event binding macros
#define BIND_EVENT_FN(x, y) std::bind(&x::y, this, std::placeholders::_1)
