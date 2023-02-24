#pragma once

#include "Aurora/Core/Event/Event.h"
#include "Util.h"

namespace Aurora
{
  namespace Engine
  {
    class Layer
    {
      public:
        Layer() {}
        virtual ~Layer() = default;
        virtual void OnUpdate(Util::DeltaTime t) {}
        virtual void OnEvent(Event& e) {}
        virtual void OnRender() {}

        virtual void OnAttach() {}
        virtual void OnDetach() {}
    };
  }
}

