#pragma once

#include <Core.h>

#include <chrono>

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>


namespace Aurora
{
  namespace Util
  {
    class AURORA_UTIL_API Time
    {
      public:
        static inline float GetTime() 
        {
          std::chrono::seconds s = std::chrono::duration_cast<std::chrono::seconds>(
            std::chrono::system_clock::now().time_since_epoch());
          return s.count();
        }
    };

    class AURORA_UTIL_API DeltaTime
    {
      public:
        DeltaTime(float _time = 0.0f) : time(_time) {}
        DeltaTime& operator=(const float& _time)
        {
          time = _time;
          return *this;
        }

        operator float() const { return time; }
        float GetSeconds() const { return time; }
        float GetMilliseconds() const { return time * 1000; }
        std::string ToString() const {
          std::stringstream ss;
          ss << std::fixed << "Delta Time: " << time << std::scientific;
          return ss.str();
        }

      private:
        float time;
    };

    class AURORA_UTIL_API Log
    {
      public:
        static inline std::shared_ptr<spdlog::logger>& GetLibLogger() { return LibLogger; }
        static inline std::shared_ptr<spdlog::logger>& GetEngineLogger() { return EngineLogger; }
        static inline std::shared_ptr<spdlog::logger>& GetClientLogger() { return ClientLogger; }

        static void Init();

      private:
        static std::shared_ptr<spdlog::logger> LibLogger;
        static std::shared_ptr<spdlog::logger> EngineLogger;
        static std::shared_ptr<spdlog::logger> ClientLogger;
     };
  }
}

#define PA_LIB_INFO(...)     ::Aurora::Util::Log::GetLibLogger()->info(__VA_ARGS__)
#define PA_LIB_TRACE(...)    ::Aurora::Util::Log::GetLibLogger()->trace(__VA_ARGS__)
#define PA_LIB_WARN(...)     ::Aurora::Util::Log::GetLibLogger()->warn(__VA_ARGS__)
#define PA_LIB_ERROR(...)    ::Aurora::Util::Log::GetLibLogger()->error(__VA_ARGS__)
#define PA_LIB_CRITICAL(...) ::Aurora::Util::Log::GetLibLogger()->critical(__VA_ARGS__)

#define PA_ENGINE_INFO(...)     ::Aurora::Util::Log::GetEngineLogger()->info(__VA_ARGS__)
#define PA_ENGINE_TRACE(...)    ::Aurora::Util::Log::GetEngineLogger()->trace(__VA_ARGS__)
#define PA_ENGINE_WARN(...)     ::Aurora::Util::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define PA_ENGINE_ERROR(...)    ::Aurora::Util::Log::GetEngineLogger()->error(__VA_ARGS__)
#define PA_ENGINE_CRITICAL(...) ::Aurora::Util::Log::GetEngineLogger()->critical(__VA_ARGS__)

#define PA_CLIENT_INFO(...)         ::Aurora::Util::Log::GetClientLogger()->info(__VA_ARGS__)
#define PA_CLIENT_TRACE(...)        ::Aurora::Util::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PA_CLIENT_WARN(...)         ::Aurora::Util::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PA_CLIENT_ERROR(...)        ::Aurora::Util::Log::GetClientLogger()->error(__VA_ARGS__)
#define PA_CLIENT_CRITICAL(...)     ::Aurora::Util::Log::GetClientLogger()->critical(__VA_ARGS__)