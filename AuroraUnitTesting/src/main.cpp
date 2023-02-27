// Aurora Maple Lib, v0.0.1 ALPHA
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

// C++ Headers
#include <iostream>

// Third Party Library Headers
// Boost
#include <boost/version.hpp>
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
int main(int argc, char** argv)
{
  std::cout << BOOST_VERSION << '\n';
  std::cout << "Aurora Unit Testing\n";
  std::cin.ignore(1000, '\n');
  return 0;
}
#pragma endregion