#include "raylib.h"

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    InitWindow(800, 600, "Ventana redimensionable");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        int w = GetScreenWidth();
        int h = GetScreenHeight();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Puedes cambiar el tamaño de la ventana", 150, 40, 20, DARKBLUE);
        DrawText(TextFormat("Ancho: %d", w), 20, 100, 20, BLACK);
        DrawText(TextFormat("Alto: %d", h), 20, 130, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
