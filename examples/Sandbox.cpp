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

Sodium::Application* Sodium::createApplication() {
    return new Example();
}
