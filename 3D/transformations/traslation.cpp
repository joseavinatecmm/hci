#include "raylib.h"

int main()
{
    InitWindow(1000, 700, "Transformacion - Traslacion");

    Camera3D camera = { 0 };

    camera.position = { 10.0f, 10.0f, 10.0f };
    camera.target = { 0.0f, 0.0f, 0.0f };
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetTargetFPS(60);

    float x = -5.0f;

    while (!WindowShouldClose())
    {
        UpdateCamera(&camera, CAMERA_ORBITAL);

        x += 0.03f;

        if (x > 5.0f)
        {
            x = -5.0f;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        DrawGrid(20, 1.0f);

        DrawCube({ x, 1.0f, 0.0f }, 2.0f, 2.0f, 2.0f, BLUE);

        DrawCubeWires({ x, 1.0f, 0.0f }, 2.0f, 2.0f, 2.0f, DARKBLUE);

        EndMode3D();

        DrawText("Transformacion: Traslacion", 20, 20, 30, DARKGRAY);

        DrawText("El cubo se desplaza sobre el eje X.", 20, 70, 22, GRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
