#include "engine.hpp"
#include "basicComponents.hpp"
#include "console.hpp"

int main() {
    Engine engine;
    engine.addModule<Console>();

    auto entity = engine.createEntity()
        .with<Components::Mesh>("Hello, World!")
        .with<Components::Transform>(400, 225, 0)
        .build();

    engine.run();
    return 0;
}
