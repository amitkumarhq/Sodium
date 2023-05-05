#pragma once

#include "Event.hpp"

namespace Sodium {
    class SOD_API KeyEvent : public Event {
      protected:
        int _keyCode;

        KeyEvent(int keycode) : _keyCode(keycode) {}

      public:
        inline int getKeyCode() const { return _keyCode; }

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
    };

    class SOD_API KeyPressedEvent : public KeyEvent {
      private:
        int _repeatCount;

      public:
        KeyPressedEvent(int keycode, int repeatCount)
            : KeyEvent(keycode), _repeatCount(repeatCount) {}

        inline int getRepeatCount() const { return _repeatCount; }

        std::string toString() const override {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << _keyCode << " (" << _repeatCount << " repeats)";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)
    };

    class SOD_API KeyReleasedEvent : public KeyEvent {
      public:
        KeyReleasedEvent(int keycode)
            : KeyEvent(keycode) {}

        std::string toString() const override {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << _keyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };
}
