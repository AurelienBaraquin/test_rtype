#pragma once

#include "module.hpp"
#include <chipmunk/chipmunk.h>
#include <unordered_map>
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

    template<typename T, typename... Args>
    T* addModule(Args&&... args) {
        static_assert(std::is_base_of<Module, T>::value, "T must be derived from IModule");

        auto module = std::make_unique<T>(registry, std::forward<Args>(args)...);
        T* modulePtr = module.get();
        modules[std::type_index(typeid(T))] = std::move(module);

        modulePtr->init();
        return modulePtr;
    }

    void run();

    EntityBuilder entityBuilder = EntityBuilder(registry);
private:
    bool running = true;
    std::unordered_map<std::type_index, std::unique_ptr<Module>> modules;
    std::shared_ptr<EventManager> eventManager = std::make_shared<EventManager>();
    entt::registry registry;
};
