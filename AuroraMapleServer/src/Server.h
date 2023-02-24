#pragma once

#include <Aurora.h>

#include "Master.hpp"

class Server : public Aurora::Engine::Application
{
  public:
    Server();
    virtual ~Server();

    virtual void Run();
};

Aurora::Engine::Application* Aurora::Engine::CreateApplication()
{
  return new Server();
}