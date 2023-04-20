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

int main() {
    Example* app = new Example();
    app->Run();
    delete app;

    return 0;
}
