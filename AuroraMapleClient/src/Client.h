#pragma once

#include "Engine.h"

// C++
#include <iostream>


class ExampleLayer : public Aurora::Engine::Layer
{
  void OnUpdate(Aurora::Util::DeltaTime t) override
  {
    PA_PROJECT_TRACE("ExampleLayer::OnUpdate");
  }

  void OnEvent(Aurora::Engine::Event& e) override
  {
    PA_PROJECT_TRACE("ExampleLayer::OnEvent");
  }
};

class Client : public Aurora::Engine::Application
{
  public:
    Client();
    virtual ~Client();

    void Run();
};

Aurora::Engine::Application* Aurora::Engine::CreateApplication()
{
  return new Client();
}