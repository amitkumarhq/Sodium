#pragma once

#include "sodpch.hpp"
#include "Sodium/Core.hpp"

namespace Sodium {
    enum class EventType {
        None = 0,

        WindowClose,
        WindowResize,
        WindowFocus,
        WindowLostFocus,
        WindowMoved,

        AppTick,
        AppUpdate,
        AppRender,

        KeyPressed,
        KeyReleased,

        MouseButtonPressed,
        MouseButtonReleased,
        MouseMoved,
        MouseScrolled,
    };

    enum EventCategory {
        None = 0,

        EventCategoryApplication = BIT(0),
        EventCategoryInput       = BIT(1),
        EventCategoryKeyboard    = BIT(2),
        EventCategoryMouse       = BIT(3),
        EventCategoryMouseButton = BIT(4),
    };

#define EVENT_CLASS_TYPE(T)                                                     \
    static EventType getStaticType() { return EventType::T; }                   \
    virtual EventType getEventType() const override { return getStaticType(); } \
    virtual const char* getName() const override { return #T; }

#define EVENT_CLASS_CATEGORY(C) \
    virtual int getCategoryFlags() const override { return C; }

    class SOD_API Event {
        friend class EventDispatcher;

      protected:
        bool _isHandled = false;

      public:
        virtual EventType getEventType() const = 0;
        virtual const char* getName() const    = 0;
        virtual int getCategoryFlags() const   = 0;
        virtual std::string toString() const {
            return getName();
        };

        inline bool isInCategory(EventCategory category) {
            return getCategoryFlags() & category;
        }
    };

    class EventDispatcher {
        template<typename T>
        using EventFn = std::function<bool(T&)>;

      private:
        Event& _event;

      public:
        EventDispatcher(Event& event) : _event(event) {}

        template<typename T>
        bool dispatch(EventFn<T> func) {
            if (_event.getEventType() == T::getStaticType()) {
                _event._isHandled = func(*(T*) &_event);
                return true;
            }

            return false;
        }
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& e) {
        return os << e.toString();
    }
}
