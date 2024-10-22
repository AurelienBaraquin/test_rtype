#include "engine.hpp"

void Engine::print() {
    std::cout << "Hello, Engine!" << std::endl;
}

void Engine::createWorld() {
    world = new b2WorldDef();
}

void Engine::printWorld() {
    std::cout << "World: " << world << std::endl;
}
