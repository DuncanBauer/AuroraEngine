// Aurora Maple Client, v0.0.1 ALPHA
// Header file

// For more information visit: https://github.com/DuncanBauer/ProjectAurora#table-of-contents

// Developed by Duncan Bauer and every direct or indirect contributors to the GitHub.
// LICENSING INFORMATION

// It is recommended that you don't modify any source code! It will become difficult for you to update the library.
// Note that 'Aurora::' being a namespace, you can add functions into the namespace from your own source files, without
// modifying Util.h or Util.cpp. Discussing your changes on the GitHub Issue Tracker may lead you
// to a better solution or official support for them.

// Index of this file:
// CODE
//   - [SECTION] PREPROCESSOR DIRECTIVES
//   - [SECTION] INCLUDES
//   - [SECTION] FORWARD DECLARATIONS
//   - [SECTION] TYPENAMES
//   - [SECTION] CONSTANTS
//   - [SECTION] CLASSES
//   - [SECTION] STRUCTS
//   - [SECTION] FUNCTIONS
//   - [SECTION] MACROS

#pragma once

/************************************************************************************
* [SECTION] PREPROCESSOR DIRECTIVES
************************************************************************************/
#pragma region Preprocessor
#pragma endregion

/************************************************************************************
* [SECTION] INCLUDES
************************************************************************************/
#pragma region Includes
// Project Specific Headers
#include "Engine.h"
#include "Maple.h"

// C++ Standard Library Headers

// Third Party Library Headers
#pragma endregion

/************************************************************************************
* [SECTION] FORWARD DECLARATIONS
************************************************************************************/
#pragma region ForwardDeclarations
#pragma endregion

/************************************************************************************
* [SECTION] TYPENAMES
************************************************************************************/
#pragma region Typenames
#pragma endregion

/************************************************************************************
* [SECTION] CONSTANTS
************************************************************************************/
#pragma region Constants
#pragma endregion

/************************************************************************************
* [SECTION] STRUCTS
************************************************************************************/
#pragma region Structs
#pragma endregion

/************************************************************************************
* [SECTION] CLASSES
************************************************************************************/
#pragma region Classes
class ExampleLayer : public Aurora::Layer
{
  public:
    ExampleLayer(bool _blocking) : Layer(_blocking) {}
    virtual ~ExampleLayer() = default;

    virtual void OnUpdate() override {}
    virtual void OnImGuiRender() override {}
    virtual void OnEvent(Aurora::Event& event) 
    {
      if (event.GetEventType() == Aurora::EventType::KeyPressed)
      {
        Aurora::KeyPressedEvent& e = (Aurora::KeyPressedEvent&)event;
        switch (e.GetKey())
        {
          case Aurora::Key::Tab:
            PA_PROJECT_CRITICAL("Tab key pressed");
            break;
        }
        PA_PROJECT_TRACE("{0}", (char)e.GetKey());
      }
    }
};

class Client : public Aurora::Application
{
  public:
    Client();
    virtual ~Client();

    void Run();
};
#pragma endregion

/************************************************************************************
* [SECTION] FUNCTIONS
************************************************************************************/
#pragma region Functions
Aurora::Application* Aurora::CreateApplication()
{
  return new Client();
}
#pragma endregion

/************************************************************************************
* [SECTION] MACROS
************************************************************************************/
#pragma region Macros
#pragma endregion