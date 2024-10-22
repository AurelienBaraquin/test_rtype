#include "engine.hpp"

#define VELOCITY    0.5f

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
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, "Raylib + Box2D Engine");
    SetTargetFPS(60);

    // Initialisation de la physique Chipmunk
    space = cpSpaceNew();
    cpSpaceSetGravity(space, cpv(0, 980));  // Appliquer la gravité

    // Création d'un corps dynamique (joueur)
    playerBody = cpSpaceAddBody(space, cpBodyNew(1.0f, cpMomentForBox(1.0f, 50, 50)));
    cpBodySetPosition(playerBody, cpv(400, 200));

    playerShape = cpSpaceAddShape(space, cpBoxShapeNew(playerBody, 50, 50, 0.0f));
    cpShapeSetFriction(playerShape, 0.7f);

    // Création d'un sol statique
    groundBody = cpSpaceGetStaticBody(space);
    groundShape = cpSpaceAddShape(space, cpSegmentShapeNew(groundBody, cpv(0, 400), cpv(800, 400), 0.0f));
    cpShapeSetFriction(groundShape, 1.0f);
}

void Engine::Update() {
    cpVect force = cpv(0, 0);

    // Appliquer une force basée sur les contrôles du joueur
    if (IsKeyDown(KEY_RIGHT)) force = cpv(1000, 0);
    if (IsKeyDown(KEY_LEFT)) force = cpv(-1000, 0);

    bool isOnGround = false;
    cpVect playerPos = cpBodyGetPosition(playerBody);
    if (playerPos.y + 25 >= 400) {  // Le bas du joueur touche le sol
        isOnGround = true;
    } else {
        isOnGround = false;
    }

    // Sauter si la touche Espace est pressée et que le joueur est au sol
    if (IsKeyPressed(KEY_SPACE) && isOnGround) {
        cpBodyApplyImpulseAtWorldPoint(playerBody, cpv(0, -400), cpBodyGetPosition(playerBody));  // Impulsion vers le haut
        isOnGround = false;  // Le joueur est maintenant en l'air
    }

    cpBodyApplyForceAtWorldPoint(playerBody, force, cpBodyGetPosition(playerBody));

    // Mettre à jour la physique
    cpSpaceStep(space, 1.0f / 60.0f);
}

void Engine::Draw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Dessiner le joueur
    cpVect pos = cpBodyGetPosition(playerBody);
    DrawRectangle(pos.x - 25, pos.y - 25, 50, 50, RED);

    // Dessiner le sol
    DrawLine(0, 400, 800, 400, BLACK);

    EndDrawing();
}

void Engine::Shutdown() {
    cpShapeFree(playerShape);
    cpBodyFree(playerBody);
    cpShapeFree(groundShape);
    cpSpaceFree(space);
    CloseWindow();
}

void Engine::Run() {
    while (!WindowShouldClose()) {
        Update();
        Draw();
    }
}
