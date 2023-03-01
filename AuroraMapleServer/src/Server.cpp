#include "Server.h"

#include <iostream>
#include <exception>

Server::Server()
{
  PushOverlay(new Aurora::ImGuiLayer());
}

Server::~Server()
{

}

void Server::Run()
{
  printf("Server running\n");

  try
  {
    std::shared_ptr<Master> master = std::make_shared<Master>(Master());
    master->run();
  }
  catch (const std::exception& e)
  {
    std::cout << e.what() << '\n';
  }
}

