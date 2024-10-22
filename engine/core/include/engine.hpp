#pragma once

#include "module.hpp"
#include <chipmunk/chipmunk.h>
#include <vector>
#include <memory>

class Engine {
public:
    template <typename ModuleType, typename... Args>
    void addModule(Args&&... args) {
        modules.push_back(std::make_unique<ModuleType>(std::forward<Args>(args)...));
    }

    void run();

private:
    bool running = true;
    std::vector<std::unique_ptr<Module>> modules;
    std::shared_ptr<EventManager> eventManager = std::make_shared<EventManager>();
};
