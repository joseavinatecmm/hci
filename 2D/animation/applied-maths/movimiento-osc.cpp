#include "raylib.h"
#include <cmath>

int main()
{
    InitWindow(800, 500, "Movimiento oscilatorio");
    SetTargetFPS(60);

    float t = 0.0f;

    float A = 80.0f;     // amplitud
    float w = 2.0f;      // velocidad angular

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();
        t += dt;

        float m = A * sinf(w * t);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("m = A * sin(w * t)", 280, 20, 24, DARKBLUE);

        // CIRCULO 1: Horizontal
        float x1 = 150 + m;
        float y1 = 250;

        DrawCircle(x1, y1, 20, RED);

        // CIRCULO 2: Vertical
        float x2 = 400;
        float y2 = 250 + m;

        DrawCircle(x2, y2, 20, BLUE);

        // CIRCULO 3: Respiración
        float x3 = 650;
        float y3 = 250;
        float r  = 20 + (m * 0.3f);

        DrawCircle(x3, y3, r, GREEN);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
