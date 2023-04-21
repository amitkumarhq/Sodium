#include <Sodium.h>

class Example : public Sodium::Application {
public:
    Example() {
        // ...
    }

    ~Example() override {
        // ...
    }
};

Sodium::Application* Sodium::CreateApplication() {
    return new Example();
}
