#include "engine.hpp"

void Engine::run() {
    for (auto& module : modules) {
        module->setEventManager(eventManager);
    }

    eventManager->subscribe<Events::StopRunningEvent>([this](std::shared_ptr<Event> event) {
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
