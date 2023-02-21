#pragma once

// Engine
#include "Aurora/Core/Core.h"

// SPDLOG
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Aurora 
{
  class AURORA_API Log
  {
    public:
      static inline std::shared_ptr<spdlog::logger>& GetEngineLogger() { return EngineLogger; }
      static inline std::shared_ptr<spdlog::logger>& GetClientLogger() { return ClientLogger; }

      static void Init();
      
    private:
      static std::shared_ptr<spdlog::logger> EngineLogger;
      static std::shared_ptr<spdlog::logger> ClientLogger;
  };
}

#define AE_ENGINE_INFO(...)     ::Aurora::Log::GetEngineLogger()->info(__VA_ARGS__)
#define AE_ENGINE_TRACE(...)    ::Aurora::Log::GetEngineLogger()->trace(__VA_ARGS__)
#define AE_ENGINE_WARN(...)     ::Aurora::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define AE_ENGINE_ERROR(...)    ::Aurora::Log::GetEngineLogger()->error(__VA_ARGS__)
#define AE_ENGINE_CRITICAL(...) ::Aurora::Log::GetEngineLogger()->critical(__VA_ARGS__)

#define AE_INFO(...)         ::Aurora::Log::GetClientLogger()->info(__VA_ARGS__)
#define AE_TRACE(...)        ::Aurora::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AE_WARN(...)         ::Aurora::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AE_ERROR(...)        ::Aurora::Log::GetClientLogger()->error(__VA_ARGS__)
#define AE_CRITICAL(...)     ::Aurora::Log::GetClientLogger()->critical(__VA_ARGS__)
