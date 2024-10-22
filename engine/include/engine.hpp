#pragma once

#include <iostream>
#include <raylib.h>
#include <chipmunk/chipmunk.h>

class Engine {
public:
    Engine(int screenWidth, int screenHeight);
    ~Engine();
    void Run();

private:
    void Init();
    void Update();
    void Draw();
    void Shutdown();

    Camera2D camera;
    int screenWidth;
    int screenHeight;

    cpSpace* space;
    cpBody* playerBody;
    cpShape* playerShape;
    cpBody* groundBody;
    cpShape* groundShape;
};
