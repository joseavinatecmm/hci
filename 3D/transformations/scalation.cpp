#include "raylib.h"
#include <cmath>

int main()
{
    InitWindow(1000, 700, "Transformacion - Escalamiento");

    Camera3D camera = { 0 };

    camera.position = { 10.0f, 10.0f, 10.0f };
    camera.target = { 0.0f, 0.0f, 0.0f };
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetTargetFPS(60);

    float escala = 1.0f;

    while (!WindowShouldClose())
    {
        UpdateCamera(&camera, CAMERA_ORBITAL);

        escala = 1.0f + 0.5f * sinf((float)GetTime() * 2.0f);

        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        DrawGrid(20, 1.0f);

        DrawCube(
            { 0.0f, 1.0f, 0.0f },
            2.0f * escala,
            2.0f * escala,
            2.0f * escala,
            GREEN
        );

        DrawCubeWires(
            { 0.0f, 1.0f, 0.0f },
            2.0f * escala,
            2.0f * escala,
            2.0f * escala,
            DARKGREEN
        );

        EndMode3D();

        DrawText("Transformacion: Escalamiento", 20, 20, 30, DARKGRAY);

        DrawText("El cubo cambia continuamente de tamano.", 20, 70, 22, GRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
