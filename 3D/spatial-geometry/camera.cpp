// practica_camara_3d.cpp
#include "raylib.h"

int main()
{
    const int screenWidth = 1000;
    const int screenHeight = 700;

    InitWindow(screenWidth, screenHeight, "Practica - Manipulacion de Camara 3D");
    SetTargetFPS(60);

    Camera3D camera = { 0 };

    camera.position = { 6.0f, 5.0f, 6.0f };
    camera.target   = { 0.0f, 0.0f, 0.0f };
    camera.up       = { 0.0f, 1.0f, 0.0f };
    camera.fovy     = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    int cameraMode = CAMERA_FREE;

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_ONE)) cameraMode = CAMERA_FREE;
        if (IsKeyPressed(KEY_TWO)) cameraMode = CAMERA_ORBITAL;
        if (IsKeyPressed(KEY_THREE)) cameraMode = CAMERA_FIRST_PERSON;
        if (IsKeyPressed(KEY_R))
        {
            camera.position = { 6.0f, 5.0f, 6.0f };
            camera.target   = { 0.0f, 0.0f, 0.0f };
            camera.up       = { 0.0f, 1.0f, 0.0f };
            camera.fovy     = 45.0f;
        }

        UpdateCamera(&camera, cameraMode);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        DrawGrid(20, 1.0f);

        DrawCube({ 0.0f, 1.0f, 0.0f }, 2.0f, 2.0f, 2.0f, SKYBLUE);
        DrawCubeWires({ 0.0f, 1.0f, 0.0f }, 2.0f, 2.0f, 2.0f, DARKBLUE);

        DrawSphere({ 4.0f, 1.0f, 0.0f }, 0.6f, RED);
        DrawSphere({ -4.0f, 1.0f, 0.0f }, 0.6f, GREEN);
        DrawSphere({ 0.0f, 1.0f, 4.0f }, 0.6f, BLUE);

        EndMode3D();

        DrawText("Manipulacion de Camara 3D", 20, 20, 26, DARKGRAY);

        DrawText("Modos de camara:", 20, 70, 20, DARKGRAY);
        DrawText("1 - Camara libre", 40, 100, 18, cameraMode == CAMERA_FREE ? RED : GRAY);
        DrawText("2 - Camara orbital", 40, 125, 18, cameraMode == CAMERA_ORBITAL ? RED : GRAY);
        DrawText("3 - Camara primera persona", 40, 150, 18, cameraMode == CAMERA_FIRST_PERSON ? RED : GRAY);

        DrawText("Controles:", 20, 200, 20, DARKGRAY);
        DrawText("Mouse: orientar la camara", 40, 230, 18, GRAY);
        DrawText("W/A/S/D: mover la camara", 40, 255, 18, GRAY);
        DrawText("Q/E: subir y bajar", 40, 280, 18, GRAY);
        DrawText("R: reiniciar camara", 40, 305, 18, GRAY);
        DrawText("ESC: salir", 40, 330, 18, GRAY);

        DrawText("Objetivo didactico:", 20, 390, 20, DARKGRAY);
        DrawText("Observar como cambia la escena al modificar la posicion,", 40, 420, 18, GRAY);
        DrawText("orientacion y modo de visualizacion de la camara.", 40, 445, 18, GRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
