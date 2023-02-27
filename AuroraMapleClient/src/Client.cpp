// Aurora Maple Client, v0.0.1 ALPHA
// Source file

// For more information visit: https://github.com/DuncanBauer/ProjectAurora

// Developed by Duncan Bauer and every direct or indirect contributors to the GitHub.
// LICENSING INFORMATION

// It is recommended that you don't modify any source code! It will become difficult for you to update the library.
// Note that 'Aurora::Util::' being a namespace, you can add functions into the namespace from your own source files, without
// modifying Util.h or Util.cpp. Discussing your changes on the GitHub Issue Tracker may lead you
// to a better solution or official support for them.

// Index of this file:
// CODE
//   - [SECTION] INCLUDES
//   - [SECTION] STATIC VARIABLE INITIALIZATION
//   - [SECTION] FUNCTIONS

/************************************************************************************
* [SECTION] INCLUDES
************************************************************************************/
#pragma region Includes
// PCH

// Project Specific Header
#include "Client.h"

// C++ Headers

// Third Party Library Headers
#pragma endregion

/************************************************************************************
* [SECTION] STATIC VARIABLE INITIALIZATION
************************************************************************************/
#pragma region StaticInitialization
#pragma endregion

/************************************************************************************
* [SECTION] FUNCTIONS
************************************************************************************/
#pragma region Functions
Client::Client()
{
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
#pragma endregion