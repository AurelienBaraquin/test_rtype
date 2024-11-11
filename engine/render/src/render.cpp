#include "render.hpp"
#include "event.hpp"

void Render::init() {
    InitWindow(screenWidth, screenHeight, windowTitle.c_str());
    SetTargetFPS(60);
}

void Render::update() {
    if (WindowShouldClose()) {
        eventManager->publish(std::make_shared<Events::Shutdown>());
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);
        DrawFPS(10, 10);

    std::vector<std::tuple<entt::entity, const Components::Transform*, const Components::Mesh*>> renderQueue;

    auto view = registry.view<Components::Transform, Components::Mesh, Components::Visibility>();
    for (auto entity : view) {
        auto& visibility = view.get<Components::Visibility>(entity);
        if (visibility.value) {
            renderQueue.emplace_back(
                entity,
                &view.get<Components::Transform>(entity),
                &view.get<Components::Mesh>(entity)
            );
        }
    }

    std::sort(renderQueue.begin(), renderQueue.end(), [](const auto& a, const auto& b) {
        return std::get<1>(a)->z < std::get<1>(b)->z;
    });

    for (const auto& item : renderQueue) {
        auto& transform = *std::get<1>(item);
        auto& mesh = *std::get<2>(item);

        DrawText(mesh.name.c_str(), transform.x, transform.y, 20, BLACK);
    }

    EndDrawing();
}

void Render::shutdown() {
    CloseWindow();
}
