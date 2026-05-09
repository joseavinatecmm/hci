// practica_01_coordenadas_3d.cpp
#include "raylib.h"

int main()
{
    const int screenWidth = 1000;
    const int screenHeight = 700;

    InitWindow(screenWidth, screenHeight, "Practica 1 - Sistema de Coordenadas 3D con raylib");
    SetTargetFPS(60);

    Camera3D camera = { 0 };

    camera.position = { 8.0f, 6.0f, 8.0f };
    camera.target   = { 0.0f, 0.0f, 0.0f };
    camera.up       = { 0.0f, 1.0f, 0.0f };
    camera.fovy     = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    while (!WindowShouldClose())
    {
        UpdateCamera(&camera, CAMERA_ORBITAL);

        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        // Cuadrícula del plano XZ
        DrawGrid(20, 1.0f);

        // Eje X - rojo
        DrawLine3D(
            { -10.0f, 0.0f, 0.0f },
            {  10.0f, 0.0f, 0.0f },
            RED
        );

        // Eje Y - verde
        DrawLine3D(
            { 0.0f, -10.0f, 0.0f },
            { 0.0f,  10.0f, 0.0f },
            GREEN
        );

        // Eje Z - azul
        DrawLine3D(
            { 0.0f, 0.0f, -10.0f },
            { 0.0f, 0.0f,  10.0f },
            BLUE
        );

        // Esfera en el origen
        DrawSphere({ 0.0f, 0.0f, 0.0f }, 0.15f, BLACK);

        // Pequeños cubos para marcar las puntas positivas
        DrawCube({ 10.0f, 0.0f, 0.0f }, 0.3f, 0.3f, 0.3f, RED);
        DrawCube({ 0.0f, 10.0f, 0.0f }, 0.3f, 0.3f, 0.3f, GREEN);
        DrawCube({ 0.0f, 0.0f, 10.0f }, 0.3f, 0.3f, 0.3f, BLUE);

        EndMode3D();

        // Texto explicativo 2D
        DrawText("Practica 1: Sistema de Coordenadas 3D", 20, 20, 24, DARKGRAY);

        DrawText("Eje X: rojo", 20, 60, 20, RED);
        DrawText("Eje Y: verde", 20, 90, 20, GREEN);
        DrawText("Eje Z: azul", 20, 120, 20, BLUE);

        DrawText("La cuadricula representa el plano XZ.", 20, 160, 20, DARKGRAY);
        DrawText("La esfera negra representa el origen (0, 0, 0).", 20, 190, 20, DARKGRAY);

        DrawText("Controles:", 20, 240, 20, DARKGRAY);
        DrawText("- La camara gira automaticamente alrededor del origen.", 40, 270, 18, GRAY);
        DrawText("- Presiona ESC para salir.", 40, 300, 18, GRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

