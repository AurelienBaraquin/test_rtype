#ifndef RAYLIB_GRAPHICS_MODULE_HPP
#define RAYLIB_GRAPHICS_MODULE_HPP

#include "module.hpp"
#include "raylib.h"

class Render : public Module {
public:
    Render(int width, int height, const std::string& title)
        : Module("Graphics"), screenWidth(width), screenHeight(height), windowTitle(title) {}

    void init() override;
    void update() override;
    void shutdown() override;

private:
    int screenWidth;
    int screenHeight;
    std::string windowTitle;
};

#endif // RAYLIB_GRAPHICS_MODULE_HPP
