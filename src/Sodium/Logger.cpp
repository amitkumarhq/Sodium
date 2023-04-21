#include "Sodium/Logger.hpp"

namespace Sodium {
    std::shared_ptr<spdlog::logger> Logger::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Logger::s_ClientLogger;

    void Logger::init() {
        spdlog::set_pattern("%^[%l] [%T] %n: %v%$");

        s_CoreLogger = spdlog::stdout_color_mt("SODIUM");
        s_CoreLogger->set_level(spdlog::level::trace);

        s_ClientLogger = spdlog::stdout_color_mt("APP");
        s_ClientLogger->set_level(spdlog::level::trace);
    }
}
