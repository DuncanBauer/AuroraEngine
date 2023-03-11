// Aurora Engine Library
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
//   - [SECTION] MACROS

#pragma once

#pragma region Preprocessor
/************************************************************************************
* [SECTION] PREPROCESSOR DIRECTIVES
************************************************************************************/
// Define dllexport and dllimport for Windows
#ifdef PA_PLATFORM_WINDOWS
  #if PA_DYNAMIC_LINK
    #ifdef PA_ENGINE_BUILD_DLL
      #define AURORA_ENGINE_API _declspec(dllexport)
    #else
      #define AURORA_ENGINE_API _declspec(dllimport)
    #endif
  #else
    #define AURORA_ENGINE_API
  #endif
#else
  #error PROJECT AURORA ONLY SUPPORTS WINDOWS!
#endif
#pragma endregion


#pragma region Includes
/************************************************************************************
* [SECTION] INCLUDES
************************************************************************************/
// C++ Standard Library Headers
#include <memory>
#pragma endregion


#pragma region Typedefs
/************************************************************************************
* [SECTION] TYPEDEFS
************************************************************************************/
namespace Aurora
{
  template<typename T>
  using Scope = std::unique_ptr<T>;

  template<typename T>
  using Ref = std::shared_ptr<T>;
}
#pragma endregion


#pragma region Functions
/************************************************************************************
* [SECTION] FUNCTIONS
************************************************************************************/
namespace Aurora
{
  template<typename T, typename ... Args>
  constexpr Scope<T> CreateScope(Args&& ... args)
  {
    return std::make_unique<T>(std::forward<Args>(args)...);
  }

  template<typename T, typename ... Args>
  constexpr Ref<T> CreateRef(Args&& ... args)
  {
    return std::make_shared<T>(std::forward<Args>(args)...);
  }
}
#pragma endregion


#pragma region Macros
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
  #define PA_ENGINE_ASSERT(x, ...)  { if(!(x)) { PA_ENGINE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
  #define PA_CLIENT_ASSERT(x, ...)  { if(!(x)) { PA_CLIENT_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
  #define PA_ENGINE_ASSERT(x, ...)
  #define PA_CLIENT_ASSERT(x, ...)
#endif

// Event binding macros
#define BIND_EVENT_FN(x, y) std::bind(&x::y, this, std::placeholders::_1)
#pragma endregion