#pragma once

extern Sodium::Application* Sodium::CreateApplication();

int main(int argc, char** argv) {
    Sodium::Logger::init();

    auto app = Sodium::CreateApplication();
    app->Run();

    delete app;
    return 0;
}
