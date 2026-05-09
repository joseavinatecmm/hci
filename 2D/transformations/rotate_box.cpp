#include "raylib.h"
#include <cmath>

// Función para rotar un punto alrededor del origen
Vector2 Rotar(Vector2 p, float angulo)
{
    Vector2 r;
    r.x = p.x * cosf(angulo) - p.y * sinf(angulo);
    r.y = p.x * sinf(angulo) + p.y * cosf(angulo);
    return r;
}

int main()
{
    InitWindow(800, 600, "Traslacion y rotacion automatica");
    SetTargetFPS(60);

    // Centro del cuadrado
    Vector2 posicion = {400, 300};

    // Tamaño
    float lado = 100;

    // Ángulo
    float theta = 0.0f;

    while (!WindowShouldClose())
    {
        // Actualización
        theta += 1.0f * GetFrameTime(); // rotación automática

        // Definición del cuadrado (centrado en el origen)
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

        DrawText("Rotacion automatica", 300, 20, 20, DARKBLUE);

        DrawLineV(v1, v2, RED);
        DrawLineV(v2, v3, RED);
        DrawLineV(v3, v4, RED);
        DrawLineV(v4, v1, RED);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
