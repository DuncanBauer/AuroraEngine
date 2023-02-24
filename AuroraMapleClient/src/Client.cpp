#include "Client.h"


Client::Client()
{
  PushLayer(new ExampleLayer());
  PushOverlay(new Aurora::Engine::ImGuiLayer());
}

Client::~Client()
{

}

void Client::Run()
{
  printf("Client running\n");
  while (true);
}

