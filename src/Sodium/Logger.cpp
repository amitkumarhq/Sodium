#include "sodpch.hpp"
#include "Sodium/Logger.hpp"

namespace Sodium {
    std::shared_ptr<spdlog::logger> Logger::coreLogger;
    std::shared_ptr<spdlog::logger> Logger::clientLogger;

    void Logger::init() {
        spdlog::set_pattern("%^[%l%$] [%T] %n: %v%$");

        coreLogger = spdlog::stdout_color_mt("SODIUM");
        coreLogger->set_level(spdlog::level::trace);

        clientLogger = spdlog::stdout_color_mt("APP");
        clientLogger->set_level(spdlog::level::trace);
    }
}
