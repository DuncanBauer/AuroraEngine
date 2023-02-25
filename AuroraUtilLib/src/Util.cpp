#include "AuroraUtilLibPCH.h"

#include "Util.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace Aurora
{
  namespace Util
  {
    std::shared_ptr<spdlog::logger> Log::UtilLogger;
    std::shared_ptr<spdlog::logger> Log::MapleLogger;
    std::shared_ptr<spdlog::logger> Log::EngineLogger;
    std::shared_ptr<spdlog::logger> Log::ProjectLogger;

    void Log::Init()
    {
      spdlog::set_pattern("%^[%T] %n: %v%$");

      Log::UtilLogger = spdlog::stdout_color_mt("LibLogger");
      Log::UtilLogger->set_level(spdlog::level::level_enum::trace);

      Log::MapleLogger = spdlog::stdout_color_mt("MapleLogger");
      Log::MapleLogger->set_level(spdlog::level::level_enum::trace);

      Log::EngineLogger = spdlog::stdout_color_mt("EngineLogger");
      Log::EngineLogger->set_level(spdlog::level::level_enum::trace);

      Log::ProjectLogger = spdlog::stdout_color_mt("ProjectLogger");
      Log::ProjectLogger->set_level(spdlog::level::level_enum::trace);
    }
  }
}