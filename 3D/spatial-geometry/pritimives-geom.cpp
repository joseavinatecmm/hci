#include "raylib.h"

int main()
{
    const int screenWidth = 1200;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Practica 2 - Primitivas Geometricas 3D");

    Camera3D camera = { 0 };
    camera.position = { 10.0f, 10.0f, 10.0f };
    camera.target = { 0.0f, 1.0f, 0.0f };
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        UpdateCamera(&camera, CAMERA_ORBITAL);

        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        DrawGrid(20, 1.0f);

        DrawCube({ -4.0f, 1.0f, 0.0f }, 2.0f, 2.0f, 2.0f, RED);
        DrawCubeWires({ -4.0f, 1.0f, 0.0f }, 2.0f, 2.0f, 2.0f, MAROON);

        DrawSphere({ 0.0f, 1.0f, 0.0f }, 1.2f, BLUE);

        DrawCylinder({ 4.0f, 1.5f, 0.0f }, 1.0f, 1.0f, 3.0f, 32, GREEN);

        DrawPlane({ 0.0f, 0.0f, 0.0f }, { 20.0f, 20.0f }, LIGHTGRAY);

        EndMode3D();

        DrawText("Practica 2 - Primitivas Geometricas 3D", 20, 20, 30, DARKGRAY);

        DrawRectangle(20, 80, 25, 25, RED);
        DrawText("Cubo", 60, 82, 20, DARKGRAY);

        DrawRectangle(20, 120, 25, 25, BLUE);
        DrawText("Esfera", 60, 122, 20, DARKGRAY);

        DrawRectangle(20, 160, 25, 25, GREEN);
        DrawText("Cilindro", 60, 162, 20, DARKGRAY);

        DrawText("La camara gira automaticamente alrededor de la escena.", 20, 230, 20, GRAY);

        DrawText("ESC para salir", 20, 270, 20, GRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
