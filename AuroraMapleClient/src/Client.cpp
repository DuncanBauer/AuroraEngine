#include "Client.h"

Client::Client()
{
  PushLayer(new ExampleLayer());
}

Client::~Client()
{

}

void Client::Run()
{
  printf("Client running\n");
  while (true);
}

