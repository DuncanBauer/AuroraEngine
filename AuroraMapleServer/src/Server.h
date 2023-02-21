#pragma once

#include <Aurora.h>

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