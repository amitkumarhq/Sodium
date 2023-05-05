#pragma once

#include "sodpch.hpp"

#include "Sodium/Core.hpp"
#include "Sodium/Events/Event.hpp"

namespace Sodium {
    struct WindowProps {
        std::string _title;
        uint32_t _width;
        uint32_t _height;

        WindowProps(
            const std::string& title = "Sodium Engine",
            uint32_t width           = 640,
            uint32_t height          = 360
        ) : _title(title), _width(width), _height(height) {}
    };

    /**
     * @brief Interface representing a desktop system based Window
     */
    class SOD_API Window {
      public:
        using EventCallbackFn = std::function<void(Event&)>;

        virtual ~Window() = default;

        virtual void onUpdate()            = 0;
        virtual uint32_t getWidth() const  = 0;
        virtual uint32_t getHeight() const = 0;

        // Window attributes
        virtual void setEventCallback(const EventCallbackFn& callback) = 0;
        virtual void setVSync(bool enabled)                            = 0;
        virtual bool isVSync() const                                   = 0;

        static Window* create(const WindowProps& props = WindowProps());
    };
}
