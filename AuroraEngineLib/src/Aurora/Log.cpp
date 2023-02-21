#include "AuroraEngineLibPCH.h"

#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace Aurora 
{
  std::shared_ptr<spdlog::logger> Log::EngineLogger;
  std::shared_ptr<spdlog::logger> Log::ClientLogger;

  void Log::Init()
  {
    spdlog::set_pattern("%^[%T] %n: %v%$");
    
    Log::EngineLogger = spdlog::stdout_color_mt("EngineLogger");
    Log::EngineLogger->set_level(spdlog::level::level_enum::trace);

    Log::ClientLogger = spdlog::stdout_color_mt("ClientLogger");
    Log::ClientLogger->set_level(spdlog::level::level_enum::trace);
  }
}