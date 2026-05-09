#include "raylib.h"

int main()
{
    InitWindow(800, 600, "Traslacion en eje X");
    SetTargetFPS(60);

    // Posición inicial
    Vector2 posicion = {100, 300};

    float lado = 100;
    float velocidad = 200.0f; // pixeles por segundo

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        // Movimiento en eje X
        posicion.x += velocidad * dt;

        // Rebote en bordes
        if (posicion.x > 800 - lado/2 || posicion.x < lado/2)
        {
            velocidad = -velocidad;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Traslacion automatica en X", 250, 20, 20, DARKBLUE);

        DrawRectangle(
            posicion.x - lado/2,
            posicion.y - lado/2,
            lado,
            lado,
            RED
        );

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
