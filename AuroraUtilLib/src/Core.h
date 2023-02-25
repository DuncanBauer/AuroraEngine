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

// SPDLog Macros for the Project Aurora Util Library
#define PA_UTIL_INFO(...)     ::Aurora::Util::Log::GetUtilLogger()->info(__VA_ARGS__)
#define PA_UTIL_TRACE(...)    ::Aurora::Util::Log::GetUtilLogger()->trace(__VA_ARGS__)
#define PA_UTIL_WARN(...)     ::Aurora::Util::Log::GetUtilLogger()->warn(__VA_ARGS__)
#define PA_UTIL_ERROR(...)    ::Aurora::Util::Log::GetUtilLogger()->error(__VA_ARGS__)
#define PA_UTIL_CRITICAL(...) ::Aurora::Util::Log::GetUtilLogger()->critical(__VA_ARGS__)

// SPDLog Macros for the Project Aurora Maple Library
#define PA_MAPLE_INFO(...)     ::Aurora::Util::Log::GetMapleLogger()->info(__VA_ARGS__)
#define PA_MAPLE_TRACE(...)    ::Aurora::Util::Log::GetMapleLogger()->trace(__VA_ARGS__)
#define PA_MAPLE_WARN(...)     ::Aurora::Util::Log::GetMapleLogger()->warn(__VA_ARGS__)
#define PA_MAPLE_ERROR(...)    ::Aurora::Util::Log::GetMapleLogger()->error(__VA_ARGS__)
#define PA_MAPLE_CRITICAL(...) ::Aurora::Util::Log::GetMapleLogger()->critical(__VA_ARGS__)

// SPDLog Macros for the Project Aurora Engine Library
#define PA_ENGINE_INFO(...)     ::Aurora::Util::Log::GetEngineLogger()->info(__VA_ARGS__)
#define PA_ENGINE_TRACE(...)    ::Aurora::Util::Log::GetEngineLogger()->trace(__VA_ARGS__)
#define PA_ENGINE_WARN(...)     ::Aurora::Util::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define PA_ENGINE_ERROR(...)    ::Aurora::Util::Log::GetEngineLogger()->error(__VA_ARGS__)
#define PA_ENGINE_CRITICAL(...) ::Aurora::Util::Log::GetEngineLogger()->critical(__VA_ARGS__)

// SPDLog Macros for projects made with the Project Aurora Libraries 
#define PA_PROJECT_INFO(...)     ::Aurora::Util::Log::GetProjectLogger()->info(__VA_ARGS__)
#define PA_PROJECT_TRACE(...)    ::Aurora::Util::Log::GetProjectLogger()->trace(__VA_ARGS__)
#define PA_PROJECT_WARN(...)     ::Aurora::Util::Log::GetProjectLogger()->warn(__VA_ARGS__)
#define PA_PROJECT_ERROR(...)    ::Aurora::Util::Log::GetProjectLogger()->error(__VA_ARGS__)
#define PA_PROJECT_CRITICAL(...) ::Aurora::Util::Log::GetProjectLogger()->critical(__VA_ARGS__)