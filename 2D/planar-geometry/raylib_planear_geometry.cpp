#include "raylib.h"

int main()
{
    const int screenWidth = 900;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Ventana y primitivas");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Practica 01: Ventana y primitivas en raylib", 180, 20, 28, DARKBLUE);
        DrawText("Objetivo: reconocer el ciclo Init -> Update -> Draw", 180, 55, 20, GRAY);

        // Sol
        DrawCircle(760, 110, 45, GOLD);

        // Casa
        DrawRectangle(270, 280, 220, 170, BEIGE);
        DrawTriangle((Vector2){250, 280}, (Vector2){380, 180}, (Vector2){510, 280}, BROWN);
        DrawRectangle(350, 365, 55, 85, DARKBROWN);
        DrawRectangle(300, 320, 45, 45, SKYBLUE);
        DrawRectangle(415, 320, 45, 45, SKYBLUE);

        // Suelo
        DrawRectangle(0, 450, screenWidth, 150, DARKGREEN);

        // Arbol simple
        DrawRectangle(120, 340, 28, 110, BROWN);
        DrawCircle(134, 300, 45, GREEN);
        DrawCircle(100, 330, 35, GREEN);
        DrawCircle(168, 330, 35, GREEN);

        // Ejes de referencia
        DrawLine(40, 520, 250, 520, LIGHTGRAY);
        DrawLine(40, 520, 40, 350, LIGHTGRAY);
        DrawText("x", 255, 512, 18, DARKGRAY);
        DrawText("y", 28, 340, 18, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
