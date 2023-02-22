#pragma once

#include "Core.h"

// SPDLOG
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Aurora
{
  namespace Core
  {
    class AURORA_CORE_API Log
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
}

#define PA_ENGINE_INFO(...)     ::Aurora::Core::Log::GetEngineLogger()->info(__VA_ARGS__)
#define PA_ENGINE_TRACE(...)    ::Aurora::Core::Log::GetEngineLogger()->trace(__VA_ARGS__)
#define PA_ENGINE_WARN(...)     ::Aurora::Core::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define PA_ENGINE_ERROR(...)    ::Aurora::Core::Log::GetEngineLogger()->error(__VA_ARGS__)
#define PA_ENGINE_CRITICAL(...) ::Aurora::Core::Log::GetEngineLogger()->critical(__VA_ARGS__)

#define PA_INFO(...)         ::Aurora::Core::Log::GetClientLogger()->info(__VA_ARGS__)
#define PA_TRACE(...)        ::Aurora::Core::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PA_WARN(...)         ::Aurora::Core::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PA_ERROR(...)        ::Aurora::Core::Log::GetClientLogger()->error(__VA_ARGS__)
#define PA_CRITICAL(...)     ::Aurora::Core::Log::GetClientLogger()->critical(__VA_ARGS__)