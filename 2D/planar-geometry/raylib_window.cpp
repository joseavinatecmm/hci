#include "raylib.h"

int main()
{
    // Dimensiones de la ventana
    const int width = 800;
    const int height = 600;

    // Crear la ventana
    InitWindow(width, height, "Mi primera ventana en raylib");

    // Bucle principal
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    // Cerrar la ventana
    CloseWindow();

    return 0;
}
