#pragma once

#include "Core.hpp"

#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/spdlog.h"

namespace Sodium {
    class SOD_API Logger {
      private:
        static std::shared_ptr<spdlog::logger> coreLogger;
        static std::shared_ptr<spdlog::logger> clientLogger;

      public:
        Logger();

        virtual ~Logger();

        static void init();

        inline static std::shared_ptr<spdlog::logger>& getCoreLogger() {
            return coreLogger;
        }

        inline static std::shared_ptr<spdlog::logger>& getClientLogger() {
            return clientLogger;
        }
    };
}

// Core log macros
#define SOD_CORE_TRACE(...) ::Sodium::Logger::getCoreLogger()->trace(__VA_ARGS__)
#define SOD_CORE_INFO(...)  ::Sodium::Logger::getCoreLogger()->info(__VA_ARGS__)
#define SOD_CORE_WARN(...)  ::Sodium::Logger::getCoreLogger()->warn(__VA_ARGS__)
#define SOD_CORE_ERROR(...) ::Sodium::Logger::getCoreLogger()->error(__VA_ARGS__)
#define SOD_CORE_FATAL(...) ::Sodium::Logger::getCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define SOD_TRACE(...) ::Sodium::Logger::getClientLogger()->trace(__VA_ARGS__)
#define SOD_INFO(...)  ::Sodium::Logger::getClientLogger()->info(__VA_ARGS__)
#define SOD_WARN(...)  ::Sodium::Logger::getClientLogger()->warn(__VA_ARGS__)
#define SOD_ERROR(...) ::Sodium::Logger::getClientLogger()->error(__VA_ARGS__)
#define SOD_FATAL(...) ::Sodium::Logger::getClientLogger()->fatal(__VA_ARGS__)
