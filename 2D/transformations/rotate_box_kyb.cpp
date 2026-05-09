#include "raylib.h"
#include <cmath>

Vector2 Rotar(Vector2 p, float angulo)
{
    Vector2 r;
    r.x = p.x * cosf(angulo) - p.y * sinf(angulo);
    r.y = p.x * sinf(angulo) + p.y * cosf(angulo);
    return r;
}

int main()
{
    InitWindow(800, 600, "Rotacion con teclado");
    SetTargetFPS(60);

    Vector2 posicion = {400, 300};
    float lado = 100;
    float theta = 0.0f;

    while (!WindowShouldClose())
    {
        // Control con teclado
        if (IsKeyDown(KEY_RIGHT))
            theta += 2.0f * GetFrameTime();

        if (IsKeyDown(KEY_LEFT))
            theta -= 2.0f * GetFrameTime();

        // Cuadrado base
        Vector2 v1 = {-lado/2, -lado/2};
        Vector2 v2 = { lado/2, -lado/2};
        Vector2 v3 = { lado/2,  lado/2};
        Vector2 v4 = {-lado/2,  lado/2};

        // Rotación
        v1 = Rotar(v1, theta);
        v2 = Rotar(v2, theta);
        v3 = Rotar(v3, theta);
        v4 = Rotar(v4, theta);

        // Traslación
        v1.x += posicion.x; v1.y += posicion.y;
        v2.x += posicion.x; v2.y += posicion.y;
        v3.x += posicion.x; v3.y += posicion.y;
        v4.x += posicion.x; v4.y += posicion.y;

        // Dibujo
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Usa flechas izquierda/derecha", 220, 20, 20, DARKBLUE);

        DrawLineV(v1, v2, BLUE);
        DrawLineV(v2, v3, BLUE);
        DrawLineV(v3, v4, BLUE);
        DrawLineV(v4, v1, BLUE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
