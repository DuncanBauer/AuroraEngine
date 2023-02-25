#pragma once

// Aurora Utilities Library, v0.0.1 ALPHA

// Help:
// Read README.MD at https://github.com/duncanbauer/projectaurora

#include <Core.h>

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Aurora
{
  namespace Util
  {
    /********************************************************************************
    * [CLASS] Time
    *********************************************************************************
    *
    * A light-weight static class that returns the current time.
    *
    ********************************************************************************/
    class AURORA_UTIL_API Time
    {
      public:
        static inline float GetTimeSeconds()
        {
          std::chrono::seconds s = std::chrono::duration_cast<std::chrono::seconds>(
            std::chrono::system_clock::now().time_since_epoch());
          return s.count();
        }

        static inline float GetTimeMilliseconds()
        {
          std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(
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
        static void Init();
        
        static inline std::shared_ptr<spdlog::logger>& GetUtilLogger()   { return UtilLogger; }
        static inline std::shared_ptr<spdlog::logger>& GetMapleLogger()  { return MapleLogger; }
        static inline std::shared_ptr<spdlog::logger>& GetEngineLogger() { return EngineLogger; }
        static inline std::shared_ptr<spdlog::logger>& GetProjectLogger() { return ProjectLogger; }

      private:
        static std::shared_ptr<spdlog::logger> UtilLogger;
        static std::shared_ptr<spdlog::logger> MapleLogger;
        static std::shared_ptr<spdlog::logger> EngineLogger;
        static std::shared_ptr<spdlog::logger> ProjectLogger;
     };
  }
}