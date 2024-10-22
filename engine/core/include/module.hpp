#ifndef MODULE_HPP
#define MODULE_HPP

#include "event.hpp"

class Module {
public:
    Module(const std::string& name) : moduleName(name) {}
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
};

#endif // MODULE_HPP
