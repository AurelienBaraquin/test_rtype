#include "engine.hpp"

int add(int a, int b) {
    return a + b;
}

void Engine::run() {
    // sol::state lua;
    // lua.open_libraries(sol::lib::base);

    // lua.set_function("add", &add);

    // lua.script_file("script.lua");

    for (auto& module : modules) {
        module->setEventManager(eventManager);
    }

    eventManager->subscribe<Events::Shutdown>([this](std::shared_ptr<Event> event) {
        running = false;
    });

    for (auto& module : modules) {
        module->init();
    }

    while (running) {
        for (auto& module : modules) {
            module->update();
        }
    }

    for (auto& module : modules) {
        module->shutdown();
    }
}
