#pragma once

#include "Event.hpp"

namespace Sodium {
    class SOD_API WindowResizeEvent : public Event {
      private:
        u32 width, height;

      public:
        WindowResizeEvent(u32 width, u32 height)
            : width(width), height(height) {}

        inline u32 getWidth() const { return width; }
        inline u32 getHeight() const { return height; }

        std::string toString() const override {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << width << ", " << height;
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class SOD_API WindowCloseEvent : public Event {
      public:
        WindowCloseEvent() {}

        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class SOD_API AppTickEvent : public Event {
      public:
        AppTickEvent() {}

        EVENT_CLASS_TYPE(AppTick)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class SOD_API AppUpdateEvent : public Event {
      public:
        AppUpdateEvent() {}

        EVENT_CLASS_TYPE(AppUpdate)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class SOD_API AppRenderEvent : public Event {
      public:
        AppRenderEvent() {}

        EVENT_CLASS_TYPE(AppRender)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
}
