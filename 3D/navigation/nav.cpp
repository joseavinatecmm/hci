#include "raylib.h"

int main()
{
    InitWindow(1000, 700, "Practica 4 - Navegacion en el Espacio 3D");

    Camera3D camera = { 0 };

    camera.position = { 6.0f, 4.0f, 6.0f };
    camera.target = { 0.0f, 1.0f, 0.0f };
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        UpdateCamera(&camera, CAMERA_FREE);

        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        DrawGrid(30, 1.0f);

        DrawCube({ 0.0f, 1.0f, 0.0f }, 2.0f, 2.0f, 2.0f, SKYBLUE);
        DrawCubeWires({ 0.0f, 1.0f, 0.0f }, 2.0f, 2.0f, 2.0f, DARKBLUE);

        DrawSphere({ 5.0f, 1.0f, 0.0f }, 1.0f, RED);
        DrawSphere({ -5.0f, 1.0f, 0.0f }, 1.0f, GREEN);
        DrawSphere({ 0.0f, 1.0f, 5.0f }, 1.0f, BLUE);
        DrawSphere({ 0.0f, 1.0f, -5.0f }, 1.0f, ORANGE);

        EndMode3D();

        DrawText("Practica 4 - Navegacion en el Espacio 3D", 20, 20, 28, DARKGRAY);

        DrawText("Controles basicos:", 20, 70, 22, DARKGRAY);
        DrawText("W/A/S/D: mover la camara", 40, 105, 20, GRAY);
        DrawText("Mouse: cambiar direccion de vista", 40, 135, 20, GRAY);
        DrawText("Q/E: subir y bajar", 40, 165, 20, GRAY);
        DrawText("ESC: salir", 40, 195, 20, GRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
