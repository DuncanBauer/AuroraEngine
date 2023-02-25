#pragma once

#include "Aurora/Core/Layer/Layer.h"

namespace Aurora
{
  namespace Engine
  {
    class AURORA_ENGINE_API ImGuiLayer : public Layer
    {
      public:
        ImGuiLayer();
        ~ImGuiLayer();
        
        void OnAttach();
        void OnDetach();

        void OnUpdate(Aurora::Util::DeltaTime t) override;
        void OnEvent(Aurora::Engine::Event& e) override;

      private:
        float m_Time = 0.0f;
    };
  }
}
