#pragma once

#include "Aurora.h"

#include <Core/Log.h>

#ifdef PA_PLATFORM_WINDOWS

extern Aurora::Application* Aurora::CreateApplication();

int main(int argc, char** argv)
{
  Aurora::Core::Log::Init();

  //AE_ENGINE_INFO("INFO");
  //AE_ENGINE_TRACE("TRACE");
  //AE_ENGINE_WARN("WARN");
  //AE_ENGINE_ERROR("ERROR");
  //AE_ENGINE_CRITICAL("CRITICAL");

  //int x = 1;
  //AE_INFO("INFO Var={0}", x++);
  //AE_TRACE("TRACE Var={0}", x++);
  //AE_WARN("WARN Var={0}", x++);
  //AE_ERROR("ERROR Var={0}", x++);
  //AE_CRITICAL("CRITICAL Var={0}", x++);

  auto app = Aurora::CreateApplication();
  app->Run();
  delete app;
}

#endif