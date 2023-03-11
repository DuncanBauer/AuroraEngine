// Aurora Engine Library
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
//   - [SECTION] ENUMS
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
#include "Core.h"
#include "Layer.h"

// C++ Standard Library Headers
#include <vector>

// Third Party Library Headers
#pragma endregion

/************************************************************************************
* [SECTION] FORWARD DECLARATIONS
************************************************************************************/
#pragma region Forward Declarations
#pragma endregion

/************************************************************************************
* [SECTION] TYPENAMES
************************************************************************************/
#pragma region Typenames
#pragma endregion

namespace Aurora
{
/************************************************************************************
* [SECTION] CONSTANTS
************************************************************************************/
#pragma region Constants
#pragma endregion

/************************************************************************************
* [SECTION] ENUMS
************************************************************************************/
#pragma region Enums
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
    class AURORA_ENGINE_API LayerStack
    {
      public:
        LayerStack() = default;

        ~LayerStack()
        {
          for (Layer* layer : Layers)
          {
            layer->OnDetach();
            delete layer;
          }
        }

        inline void PushLayer(Layer* _layer)
        {
          Layers.emplace(Layers.begin() + LayerIterIndex, _layer);
          LayerIterIndex++;
        }

        inline void PushOverlay(Layer* _overlay)
        {
          Layers.emplace_back(_overlay);
        }

        void PopLayer(Layer* _layer)
        {
          auto it = std::find(Layers.begin(), Layers.begin() + LayerIterIndex, _layer);
          if (it != Layers.begin() + LayerIterIndex)
          {
            _layer->OnDetach();
            Layers.erase(it);
            LayerIterIndex--;
          }
        }

        void PopOverlay(Layer* _overlay)
        {
          auto it = std::find(Layers.begin() + LayerIterIndex, Layers.end(), _overlay);
          if (it != Layers.end())
          {
            _overlay->OnDetach();
            Layers.erase(it);
          }
        }

        inline std::vector<Layer*>::iterator begin() { return Layers.begin(); }
        inline std::vector<Layer*>::iterator end() { return Layers.end(); }
        inline std::vector<Layer*>::reverse_iterator rbegin() { return Layers.rbegin(); }
        inline std::vector<Layer*>::reverse_iterator rend() { return Layers.rend(); }

        inline std::vector<Layer*>::const_iterator begin() const { return Layers.begin(); }
        inline std::vector<Layer*>::const_iterator end()	const { return Layers.end(); }
        inline std::vector<Layer*>::const_reverse_iterator rbegin() const { return Layers.rbegin(); }
        inline std::vector<Layer*>::const_reverse_iterator rend() const { return Layers.rend(); }

      private:
        std::vector<Layer*> Layers;
        unsigned int LayerIterIndex = 0;
    };
#pragma endregion

/************************************************************************************
* [SECTION] FUNCTIONS
************************************************************************************/
#pragma region Functionss
#pragma endregion

/************************************************************************************
* [SECTION] MACROS
************************************************************************************/
#pragma region Macros
#pragma endregion
}