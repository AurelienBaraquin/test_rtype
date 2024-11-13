#include "engine.hpp"

void Engine::start() {
    for (auto& [_, module] : modules) {
        module->setEventManager(eventManager);
    }

    eventManager->subscribe<Events::Shutdown>([this](std::shared_ptr<Event> event) {
        running = false;
    });
}

int Engine::step() {
    for (auto& [_, module] : modules) {
        module->update();
    }
    return running;
}

void Engine::stop() {
    for (auto& [_, module] : modules) {
        module->shutdown();
    }
}
