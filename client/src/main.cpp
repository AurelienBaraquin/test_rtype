#include "engine.hpp"
#include "render.hpp"

int main() {
    Engine engine;
    engine.addModule<Render>(800, 450, "Hello, World!");

    auto entity = engine.entityBuilder
        .with<Components::Mesh>("Hello, World!")
        .with<Components::Transform>(400, 225, 0)
        .with<Components::Visibility>(true)
        .build();

    engine.run();
    return 0;
}
