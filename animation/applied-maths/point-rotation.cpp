#include "raylib.h"
#include <cmath>

// Convierte coordenadas matemáticas a pantalla (origen en el centro)
Vector2 ToScreen(Vector2 origin, float x, float y)
{
    return { origin.x + x, origin.y - y };
}

int main()
{
    InitWindow(800, 600, "Rotacion simple con proyecciones");
    SetTargetFPS(60);

    Vector2 origin = {400, 300}; // centro
    float r = 150;               // radio
    float theta = 0;             // ángulo

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();
        theta += 1.0f * dt; // velocidad angular

        // Ecuaciones clave
        float x = r * cosf(theta);
        float y = r * sinf(theta);

        Vector2 P = ToScreen(origin, x, y);
        Vector2 Px = ToScreen(origin, x, 0);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Ejes
        DrawLine(0, origin.y, 800, origin.y, LIGHTGRAY); // eje X
        DrawLine(origin.x, 0, origin.x, 600, LIGHTGRAY); // eje Y

        // Circunferencia
        DrawCircleLines(origin.x, origin.y, r, GRAY);

        // Radio
        DrawLineV(origin, P, BLUE);

        // Proyección en X
        DrawLineV(origin, Px, ORANGE);

        // Proyección en Y
        DrawLineV(Px, P, GREEN);

        // Punto
        DrawCircleV(P, 8, RED);

        // Texto mínimo
        DrawText("x = r cos(theta)", 20, 20, 20, ORANGE);
        DrawText("y = r sin(theta)", 20, 50, 20, GREEN);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
