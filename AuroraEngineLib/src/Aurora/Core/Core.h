#pragma once

#ifdef PA_PLATFORM_WINDOWS
  #ifdef PA_BUILD_DLL
    #define AURORA_API _declspec(dllexport)
  #else
    #define AURORA_API _declspec(dllimport)
  #endif
#else 
  #error PROJECT AURORA ONLY SUPPORTS WINDOWS!
#endif


#ifdef PA_ASSERTS_ENABLED
  #define PA_ENGINE_LIB_ASSERT(x, ...) { if(!(x)) { PA_ENGINE_LIB_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
  #define PA_ASSERT(x, ...) { if(!(x)) { PA_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
  #define PA_ENGINE_LIB_ASSERT(x, ...)
  #define PA_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
