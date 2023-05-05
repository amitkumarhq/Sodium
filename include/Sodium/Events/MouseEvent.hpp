#pragma once

#include "Event.hpp"

namespace Sodium {
    class SOD_API MouseMovedEvent : public Event {
      private:
        f32 _mouseX, _mouseY;

      public:
        MouseMovedEvent(f32 x, f32 y)
            : _mouseX(x), _mouseY(y) {}

        inline f32 getX() const { return _mouseX; }
        inline f32 getY() const { return _mouseY; }

        std::string toString() const override {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << _mouseX << ", " << _mouseY;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    };

    class SOD_API MouseScrolledEvent : public Event {
      private:
        f32 _xOffset, _yOffset;

      public:
        MouseScrolledEvent(f32 xOffset, f32 yOffset)
            : _xOffset(xOffset), _yOffset(yOffset) {}

        inline f32 getXOffset() const { return _xOffset; }
        inline f32 getYOffset() const { return _yOffset; }

        std::string toString() const override {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << getXOffset() << ", " << getYOffset();
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    };

    class SOD_API MouseButtonEvent : public Event {
      protected:
        int _button;

        MouseButtonEvent(int button)
            : _button(button) {}

      public:
        inline int GetMouseButton() const { return _button; }

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    };

    class SOD_API MouseButtonPressedEvent : public MouseButtonEvent {
      public:
        MouseButtonPressedEvent(int button)
            : MouseButtonEvent(button) {}

        std::string toString() const override {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << _button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class SOD_API MouseButtonReleasedEvent : public MouseButtonEvent {
      public:
        MouseButtonReleasedEvent(int button)
            : MouseButtonEvent(button) {}

        std::string toString() const override {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << _button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonReleased)
    };
}
