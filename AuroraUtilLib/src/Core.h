#pragma once

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


#ifdef PA_ASSERTS_ENABLED
  #define PA_ENGINE_ASSERT(x, ...) { if(!(x)) { PA_ENGINE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
  #define PA_ASSERT(x, ...) { if(!(x)) { PA_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
  #define PA_ENGINE_ASSERT(x, ...)
  #define PA_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define PA_UTIL_INFO(...)     ::Aurora::Util::Log::GetUtilLogger()->info(__VA_ARGS__)
#define PA_UTIL_TRACE(...)    ::Aurora::Util::Log::GetUtilLogger()->trace(__VA_ARGS__)
#define PA_UTIL_WARN(...)     ::Aurora::Util::Log::GetUtilLogger()->warn(__VA_ARGS__)
#define PA_UTIL_ERROR(...)    ::Aurora::Util::Log::GetUtilLogger()->error(__VA_ARGS__)
#define PA_UTIL_CRITICAL(...) ::Aurora::Util::Log::GetUtilLogger()->critical(__VA_ARGS__)

#define PA_MAPLE_INFO(...)     ::Aurora::Util::Log::GetMapleLogger()->info(__VA_ARGS__)
#define PA_MAPLE_TRACE(...)    ::Aurora::Util::Log::GetMapleLogger()->trace(__VA_ARGS__)
#define PA_MAPLE_WARN(...)     ::Aurora::Util::Log::GetMapleLogger()->warn(__VA_ARGS__)
#define PA_MAPLE_ERROR(...)    ::Aurora::Util::Log::GetMapleLogger()->error(__VA_ARGS__)
#define PA_MAPLE_CRITICAL(...) ::Aurora::Util::Log::GetMapleLogger()->critical(__VA_ARGS__)

#define PA_ENGINE_INFO(...)     ::Aurora::Util::Log::GetEngineLogger()->info(__VA_ARGS__)
#define PA_ENGINE_TRACE(...)    ::Aurora::Util::Log::GetEngineLogger()->trace(__VA_ARGS__)
#define PA_ENGINE_WARN(...)     ::Aurora::Util::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define PA_ENGINE_ERROR(...)    ::Aurora::Util::Log::GetEngineLogger()->error(__VA_ARGS__)
#define PA_ENGINE_CRITICAL(...) ::Aurora::Util::Log::GetEngineLogger()->critical(__VA_ARGS__)

#define PA_PROJECT_INFO(...)     ::Aurora::Util::Log::GetProjectLogger()->info(__VA_ARGS__)
#define PA_PROJECT_TRACE(...)    ::Aurora::Util::Log::GetProjectLogger()->trace(__VA_ARGS__)
#define PA_PROJECT_WARN(...)     ::Aurora::Util::Log::GetProjectLogger()->warn(__VA_ARGS__)
#define PA_PROJECT_ERROR(...)    ::Aurora::Util::Log::GetProjectLogger()->error(__VA_ARGS__)
#define PA_PROJECT_CRITICAL(...) ::Aurora::Util::Log::GetProjectLogger()->critical(__VA_ARGS__)