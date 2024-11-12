#pragma once

#include "module.hpp"
#include "raylib.h"

// Components

#include "mesh.hpp"
#include "transform.hpp"
#include "visibility.hpp"

class Render : public Module {
public:
    Render(entt::registry& registry, int width, int height, const std::string& title)
        : Module(registry, "Graphics"), screenWidth(width), screenHeight(height), windowTitle(title) {}

    void init() override;
    void update() override;
    void shutdown() override;

private:
    int screenWidth;
    int screenHeight;
    std::string windowTitle;


};
