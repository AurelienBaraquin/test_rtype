#include "engine.hpp"

Engine::Engine(int screenWidth, int screenHeight)
    : screenWidth(screenWidth), screenHeight(screenHeight) {
    Init();

    camera.target = (Vector2){0.0f, 0.0f};
    camera.offset = (Vector2){screenWidth / 2.0f, screenHeight / 2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
}

Engine::~Engine() {
    Shutdown();
}

void Engine::Init() {
    InitWindow(screenWidth, screenHeight, "Raylib + Box2D Engine");
    SetTargetFPS(60);

    worldDef = b2DefaultWorldDef();
    worldDef.gravity = (b2Vec2){0.0f, 10.0f};

    worldId = b2CreateWorld(&worldDef);

    groundBodyDef = b2DefaultBodyDef();
    groundBodyDef.position = (b2Vec2){0.0f, 10.0f};

    groundId = b2CreateBody(worldId, &groundBodyDef);
    groundBox = b2MakeBox(50.0f, 10.0f);

    groundShapeDef = b2DefaultShapeDef();
    b2CreatePolygonShape(groundId, &groundShapeDef, &groundBox);

    bodyDef = b2DefaultBodyDef();
    bodyDef.type = b2_dynamicBody;
    bodyDef.position = (b2Vec2){4.0f, 4.0f};
    bodyId = b2CreateBody(worldId, &bodyDef);

    dynamicBox = b2MakeBox(1.0f, 1.0f);

    shapeDef = b2DefaultShapeDef();
    shapeDef.density = 1.0f;
    shapeDef.friction = 0.3f;

    b2CreatePolygonShape(bodyId, &shapeDef, &dynamicBox);
}

void Engine::Update() {
    const float timeStep = 1.0f / 60.0f;
    const int subStepCount = 4;

    b2World_Step(worldId, timeStep, subStepCount);

    if (IsKeyPressed(KEY_R)) {
        b2Vec2 position = (b2Vec2){4.0f, 4.0f};
        b2Rot rotation = (b2Rot){0.0f};

        b2Body_SetTransform(bodyId, position, rotation);
    }
}

void Engine::Draw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    float pixelsPerMeter = 10.0f;  // Conversion de mètres à pixels

    b2Vec2 position = b2Body_GetPosition(bodyId);
    b2Rot rotation = b2Body_GetRotation(bodyId);

    // Multiplier la position par pixelsPerMeter pour rendre la boîte visible
    DrawRectanglePro(
        (Rectangle){position.x * pixelsPerMeter, position.y * pixelsPerMeter, 1.0f * pixelsPerMeter, 1.0f * pixelsPerMeter},
        (Vector2){0.5f * pixelsPerMeter, 0.5f * pixelsPerMeter},
        b2Rot_GetAngle(rotation) * RAD2DEG,
        RED
    );

    DrawText("Appuyez sur R pour réinitialiser la position de la boîte", 10, 10, 20, DARKGRAY);
    EndDrawing();
}

void Engine::Shutdown() {
    CloseWindow();
    b2DestroyWorld(worldId);
}

void Engine::Run() {
    while (!WindowShouldClose()) {
        Update();
        Draw();
    }
}
