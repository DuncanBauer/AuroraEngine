#pragma once

#include "Engine.h"

#include "Master.hpp"

class Server : public Aurora::Application
{
  public:
    Server();
    virtual ~Server();

    virtual void Run();
};

Aurora::Application* Aurora::CreateApplication()
{
  return new Server();
}