#include "raylib.h"

int main()
{
    InitWindow(800, 600, "Triangulo con raylib");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Raylib: triangulo", 280, 20, 20, DARKBLUE);

        // Dibujar triangulo
        DrawTriangle(
            (Vector2){400, 150},
            (Vector2){300, 450},
            (Vector2){500, 450},
            RED
        );

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
