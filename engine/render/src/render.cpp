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
    EndDrawing();
}

void Render::shutdown() {
    CloseWindow();
}
