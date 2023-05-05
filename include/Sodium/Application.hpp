#pragma once

#include "Core.hpp"

#include "Sodium/Events/Event.hpp"
#include "Sodium/Events/ApplicationEvent.hpp"

#include "Window.hpp"

namespace Sodium {
    class SOD_API Application {
      private:
        std::unique_ptr<Window> _window;
        bool _isRunning = true;

      public:
        Application();
        virtual ~Application();

        void run();
        void onEvent(Event& event);

      private:
        bool onWindowClose(WindowCloseEvent& event);
    };

    // To be defined in CLIENT
    Application* createApplication();
}
