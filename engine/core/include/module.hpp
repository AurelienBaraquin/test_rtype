#ifndef MODULE_HPP
#define MODULE_HPP

#include "event.hpp"
#include <entt/entt.hpp>

class Module {
public:
    Module(entt::registry& registry, const std::string& name)
        : registry(registry), moduleName(name) {}
    virtual ~Module() {}

    void setEventManager(std::shared_ptr<EventManager> manager) {
        eventManager = manager;
    }

    virtual void init() = 0;
    virtual void update() = 0;
    virtual void shutdown() = 0;

    const std::string& getName() const {
        return moduleName;
    }

protected:
    std::string moduleName;
    std::shared_ptr<EventManager> eventManager;
    entt::registry& registry;
};

#endif // MODULE_HPP
