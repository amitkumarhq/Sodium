#pragma once

#include "Core.hpp"

namespace Sodium {
    class SOD_API Application {
      public:
        Application();
        virtual ~Application();

        void run();
    };

    // To be defined in CLIENT
    Application* createApplication();
}
