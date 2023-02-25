#pragma once

#include "Aurora/Core/Window.h"

namespace Aurora
{
  namespace Engine
  {
    class AURORA_ENGINE_API WindowsWindow : public Window
    {
      public:
        WindowsWindow(const WindowProperties& props);
        virtual ~WindowsWindow();

        void OnUpdate() const override;

        inline std::string GetTitle() const override { return m_Props.Title; }
        inline unsigned int GetWidth() const override { return m_Props.Width; }
        inline unsigned int GetHeight() const override { return m_Props.Height; }

        inline void SetEventCallback(const EventCallbackFn& callback) override { m_Props.EventCallback = callback; }
        void SetVSync(bool enabled);
        bool IsVSync() const;

      private:
        virtual void Init(const WindowProperties& props);
        virtual void Shutdown();

        struct WindowData
        {
          std::string Title;
          unsigned int Width, Height, Focused, Maximized, Iconified;
          int Xpos, Ypos;
          bool VSync;

          EventCallbackFn EventCallback;
        };

        WindowData m_Props;
    };
  }
}