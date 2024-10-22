#pragma once

#include <iostream>
#include <raylib.h>
#include <box2d/box2d.h>

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

    int screenWidth, screenHeight;
    b2WorldDef worldDef;
    b2WorldId worldId;
    b2BodyDef groundBodyDef;
    b2BodyId groundId;
    b2Polygon groundBox;
    b2ShapeDef groundShapeDef;
    b2BodyDef bodyDef;
    b2BodyId bodyId;
    b2Polygon dynamicBox;
    b2ShapeDef shapeDef;
};
