#pragma once

#include "module.hpp"
#include <chipmunk/chipmunk.h>
#include <vector>
#include <memory>

class EntityBuilder {
public:
    EntityBuilder(entt::registry& registry)
        : registry(registry) {}
    
    template <typename ComponentType, typename... Args>
    EntityBuilder& with(Args&&... args) {
        registry.emplace<ComponentType>(entity, std::forward<Args>(args)...);
        return *this;
    }

    entt::entity build() {
        return entity;
    }

private:
    entt::registry& registry;
    entt::entity entity;
};

class Engine {
public:
    Engine() {}

    template <typename ModuleType, typename... Args>
    void addModule(Args&&... args) {
        modules.push_back(std::make_unique<ModuleType>(registry, std::forward<Args>(args)...));
    }

    void run();

    EntityBuilder entityBuilder = EntityBuilder(registry);
private:
    bool running = true;
    std::vector<std::unique_ptr<Module>> modules;
    std::shared_ptr<EventManager> eventManager = std::make_shared<EventManager>();
    entt::registry registry;
};
