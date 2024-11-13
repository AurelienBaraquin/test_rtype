#include "engine.hpp"

void Engine::start() {
    for (auto& [type, module] : modules) {
        module->setEventManager(eventManager);
    }

    eventManager->subscribe<Events::Shutdown>([this](std::shared_ptr<Event> event) {
        running = false;
    });
}

int Engine::step() {
    for (auto& [type, module] : modules) {
        module->update();
    }
    return running;
}

void Engine::stop() {
    for (auto& [type, module] : modules) {
        module->shutdown();
    }
}
