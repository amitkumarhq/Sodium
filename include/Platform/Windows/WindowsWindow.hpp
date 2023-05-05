#pragma once

#include "Sodium/Window.hpp"

#include <GLFW/glfw3.h>

namespace Sodium {
    class WindowsWindow : public Window {
      private:
        GLFWwindow* _window;

        struct WindowData {
            std::string title;
            u32 width, height;
            bool vSync;

            EventCallbackFn eventCallback;
        };

        WindowData _data;

      private:
        virtual void init(const WindowProps& props);
        virtual void shutdown();

      public:
        WindowsWindow(const WindowProps& props);
        virtual ~WindowsWindow();

        void onUpdate() override;

        inline u32 getWidth() const override { return _data.width; }
        inline u32 getHeight() const override { return _data.height; }

        // Window attributes
        inline void setEventCallback(const EventCallbackFn& callback) override {
            _data.eventCallback = callback;
        }
        void setVSync(bool enabled) override;
        bool isVSync() const override;
    };
}
