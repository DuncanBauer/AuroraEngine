#pragma once

#include <Aurora.h>

class Client : public Aurora::Application
{
  public:
    Client();
    virtual ~Client();

    virtual void Run();
};

Aurora::Application* Aurora::CreateApplication()
{
  return new Client();
}