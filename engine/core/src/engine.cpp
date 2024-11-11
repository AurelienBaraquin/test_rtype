#include "engine.hpp"

int add(int a, int b) {
    return a + b;
}

void Engine::run() {
    // sol::state lua;
    // lua.open_libraries(sol::lib::base);

    // lua.set_function("add", &add);

    // lua.script_file("script.lua");

    for (auto& [type, module] : modules) {
        module->setEventManager(eventManager);
    }

    eventManager->subscribe<Events::Shutdown>([this](std::shared_ptr<Event> event) {
        running = false;
    });

    while (running) {
        for (auto& [type, module] : modules) {
            module->update();
        }
    }

    for (auto& [type, module] : modules) {
        module->shutdown();
    }
}
