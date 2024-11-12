#pragma once

#include "module.hpp"

#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>

#include "basicComponents.hpp"

class Console : public Module {
public:
    Console(entt::registry& registry)
        : Module(registry, "Console") {}

    void init() override;
    void update() override;
    void shutdown() override;

private:
    std::string input;
    std::thread inputThread;
    std::mutex inputMutex;
    bool running = true;
};
