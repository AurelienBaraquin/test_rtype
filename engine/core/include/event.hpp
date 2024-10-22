#pragma once

#include <functional>
#include <unordered_map>
#include <vector>
#include <typeindex>
#include <memory>
#include <iostream>
#include <string>

class Event {
public:
    virtual ~Event() = default;
    virtual std::string getType() const = 0;
};

class EventManager {
public:
    using EventCallback = std::function<void(std::shared_ptr<Event>)>;

    template <typename EventType>
    void subscribe(EventCallback callback) {
        auto typeIndex = std::type_index(typeid(EventType));
        subscribers[typeIndex].push_back(callback);
    }

    template <typename EventType>
    void publish(std::shared_ptr<EventType> event) {
        auto typeIndex = std::type_index(typeid(EventType));

        if (subscribers.find(typeIndex) != subscribers.end()) {
            for (const auto& callback : subscribers[typeIndex]) {
                callback(event);
            }
        }
    }

private:
    std::unordered_map<std::type_index, std::vector<EventCallback>> subscribers;
};

namespace Events {
    class StopRunningEvent : public Event {
    public:
        StopRunningEvent() {}

        std::string getType() const override {
            return "StopRunningEvent";
        }
    };
}
