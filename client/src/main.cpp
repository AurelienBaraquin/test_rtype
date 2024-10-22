#include "engine.hpp"
#include "render.hpp"

int main() {
    Engine engine;
    engine.addModule<Render>(800, 450, "Hello, World!");
    engine.run();
    return 0;
}
