#include "raylib.h"
#include "rlgl.h"

int main()
{
    InitWindow(1000, 700, "Transformacion - Rotacion");

    Camera3D camera = { 0 };

    camera.position = { 10.0f, 10.0f, 10.0f };
    camera.target = { 0.0f, 0.0f, 0.0f };
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetTargetFPS(60);

    float angulo = 0.0f;

    while (!WindowShouldClose())
    {
        UpdateCamera(&camera, CAMERA_ORBITAL);

        angulo += 1.0f;

        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        DrawGrid(20, 1.0f);

        rlPushMatrix();

        rlTranslatef(0.0f, 1.0f, 0.0f);

        rlRotatef(angulo, 0.0f, 1.0f, 0.0f);

        DrawCube({ 0.0f, 0.0f, 0.0f }, 2.0f, 2.0f, 2.0f, ORANGE);

        DrawCubeWires({ 0.0f, 0.0f, 0.0f }, 2.0f, 2.0f, 2.0f, BROWN);

        rlPopMatrix();

        EndMode3D();

        DrawText("Transformacion: Rotacion", 20, 20, 30, DARKGRAY);

        DrawText("El cubo rota sobre el eje Y.", 20, 70, 22, GRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
