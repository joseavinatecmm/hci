#include "raylib.h"
#include <cmath>

int main()
{
    InitWindow(800, 500, "Movimiento circular");
    SetTargetFPS(60);

    float t = 0.0f;

    float x0 = 400.0f;   // centro
    float y0 = 250.0f;

    float r = 120.0f;    // radio
    float w = 1.5f;      // velocidad angular

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();
        t += dt;

        // Movimiento circular
        float x = x0 + r * cosf(w * t);
        float y = y0 + r * sinf(w * t);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Movimiento circular: x = x0 + r cos(wt), y = y0 + r sin(wt)",
                 80, 20, 20, DARKBLUE);

        // Circunferencia guía
        DrawCircleLines(x0, y0, r, LIGHTGRAY);

        // Centro
        DrawCircle(x0, y0, 4, BLACK);

        // Radio (línea desde el centro al punto)
        DrawLine(x0, y0, x, y, GRAY);

        // Punto en movimiento
        DrawCircle(x, y, 10, RED);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
