#include <entt/entt.hpp>
#include <iostream>
#include <functional>

template<typename... Components>
class EntityView {
public:
    using EntityAction = std::function<void(entt::entity, Components&...)>;

    EntityView(entt::registry& registry) : registry_(registry) {}

    void each(EntityAction action) {
        auto view = registry_.view<Components...>();
        for (auto entity : view) {
            invoke_action(entity, action, view.template get<Components>(entity)...);
        }
    }

private:
    entt::registry& registry_;

    template<typename... Args>
    void invoke_action(entt::entity entity, EntityAction action, Args&... args) {
        action(entity, args...);
    }
};
