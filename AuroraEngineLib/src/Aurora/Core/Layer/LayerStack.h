#pragma once

#include <vector>

#include <Core.h>
#include "Layer.h"

namespace Aurora
{
  namespace Engine
  {
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
  }
}