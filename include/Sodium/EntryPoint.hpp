#pragma once

#ifdef SOD_PLATFORM_WINDOWS

extern Sodium::Application* Sodium::createApplication();

int main(int argc, char** argv) {
    Sodium::Logger::init();

    auto app = Sodium::createApplication();
    app->run();

    delete app;
    return 0;
}

#endif
