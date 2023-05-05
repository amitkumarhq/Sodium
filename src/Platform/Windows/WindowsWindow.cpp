#include "sodpch.hpp"
#include "Platform/Windows/WindowsWindow.hpp"

#include "Sodium/Events/ApplicationEvent.hpp"
#include "Sodium/Events/MouseEvent.hpp"
#include "Sodium/Events/KeyEvent.hpp"

namespace Sodium {
    static bool glfwInitialized = false;
    static void glfwErrorCallback(int error, const char* description) {
        SOD_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
    }

    Window* Window::create(const WindowProps& props) {
        return new WindowsWindow(props);
    }

    WindowsWindow::WindowsWindow(const WindowProps& props) {
        init(props);
    }

    WindowsWindow::~WindowsWindow() {
        shutdown();
    }

    void WindowsWindow::init(const WindowProps& props) {
        _data.title  = props._title;
        _data.width  = props._width;
        _data.height = props._height;

        SOD_CORE_INFO(
            "Creating window {0} ({1}, {2})", props._title, props._width, props._height
        );

        if (!glfwInitialized) {
            // TODO: glfwTerminate on system shutdown

            int success = glfwInit();
            SOD_CORE_ASSERT(
                success, "Could not intialize GLFW!"
            );

            glfwSetErrorCallback(glfwErrorCallback);
            glfwInitialized = true;
        }

        _window = glfwCreateWindow(
            (int) props._width, (int) props._height, _data.title.c_str(), nullptr, nullptr
        );

        glfwMakeContextCurrent(_window);
        glfwSetWindowUserPointer(_window, &_data);
        setVSync(true);

        // Set GLFW callbacks

        glfwSetWindowSizeCallback(_window, [](GLFWwindow* window, int width, int height) {
            WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);
            data.width       = width;
            data.height      = height;

            WindowResizeEvent event(width, height);
            data.eventCallback(event);
        });

        glfwSetWindowCloseCallback(_window, [](GLFWwindow* window) {
            WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);
            WindowCloseEvent event;
            data.eventCallback(event);
        });

        glfwSetKeyCallback(_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
            WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);

            switch (action) {
                case GLFW_PRESS: {
                    KeyPressedEvent event(key, 0);
                    data.eventCallback(event);
                    break;
                }
                case GLFW_RELEASE: {
                    KeyReleasedEvent event(key);
                    data.eventCallback(event);
                    break;
                }
                case GLFW_REPEAT: {
                    KeyPressedEvent event(key, 1);
                    data.eventCallback(event);
                    break;
                }
            }
        });

        glfwSetMouseButtonCallback(_window, [](GLFWwindow* window, int button, int action, int mods) {
            WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);

            switch (action) {
                case GLFW_PRESS: {
                    MouseButtonPressedEvent event(button);
                    data.eventCallback(event);
                    break;
                }
                case GLFW_RELEASE: {
                    MouseButtonReleasedEvent event(button);
                    data.eventCallback(event);
                    break;
                }
            }
        });

        glfwSetScrollCallback(_window, [](GLFWwindow* window, double xOffset, double yOffset) {
            WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);

            MouseScrolledEvent event((float) xOffset, (float) yOffset);
            data.eventCallback(event);
        });

        glfwSetCursorPosCallback(_window, [](GLFWwindow* window, double xPos, double yPos) {
            WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);

            MouseMovedEvent event((float) xPos, (float) yPos);
            data.eventCallback(event);
        });
    }

    void WindowsWindow::shutdown() {
        glfwDestroyWindow(_window);
    }

    void WindowsWindow::onUpdate() {
        glfwPollEvents();
        glfwSwapBuffers(_window);
    }

    void WindowsWindow::setVSync(bool enabled) {
        glfwSwapInterval(enabled ? 1 : 0);
        _data.vSync = enabled;
    }

    bool WindowsWindow::isVSync() const {
        return _data.vSync;
    }
}
