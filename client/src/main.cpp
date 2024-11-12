#include "engine.hpp"
#include "basicComponents.hpp"

int main() {
    Engine engine;

    auto entity = engine.createEntity()
        .with<Components::Mesh>("Hello, World!")
        .with<Components::Transform>(400, 225, 0)
        .build();

    engine.run();
    return 0;
}
