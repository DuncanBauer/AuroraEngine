#include "AuroraUtilLibPCH.h"

#include "Util.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace Aurora
{
  namespace Util
  {
    std::shared_ptr<spdlog::logger> Log::LibLogger;
    std::shared_ptr<spdlog::logger> Log::EngineLogger;
    std::shared_ptr<spdlog::logger> Log::ClientLogger;

    void Log::Init()
    {
      spdlog::set_pattern("%^[%T] %n: %v%$");

      Log::LibLogger = spdlog::stdout_color_mt("LibLogger");
      Log::LibLogger->set_level(spdlog::level::level_enum::trace);

      Log::EngineLogger = spdlog::stdout_color_mt("EngineLogger");
      Log::EngineLogger->set_level(spdlog::level::level_enum::trace);

      Log::ClientLogger = spdlog::stdout_color_mt("ClientLogger");
      Log::ClientLogger->set_level(spdlog::level::level_enum::trace);
    }
  }
}