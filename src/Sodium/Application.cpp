#include "sodpch.hpp"
#include "Sodium/Application.hpp"
#include "Sodium/Logger.hpp"

#include <GLFW/glfw3.h>

namespace Sodium {
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

    Application::Application() {
        _window = std::unique_ptr<Window>(Window::create());
        _window->setEventCallback(BIND_EVENT_FN(Application::onEvent));
    }

    Application::~Application() {}

    void Application::onEvent(Sodium::Event& event) {
        EventDispatcher dispatcher(event);
        dispatcher.dispatch<WindowCloseEvent>(
            BIND_EVENT_FN(Application::onWindowClose)
        );

        SOD_CORE_TRACE("{0}", event);
    }

    void Application::run() {
        while (_isRunning) {
            glClearColor(0, 0, 0, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            _window->onUpdate();
        };
    }

    bool Application::onWindowClose(WindowCloseEvent& event) {
        _isRunning = false;
        return true;
    }
}
