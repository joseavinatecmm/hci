#include "raylib.h"
#include <cmath>

int main()
{
    InitWindow(800, 500, "Magnitud y normalizacion");
    SetTargetFPS(60);

    Vector2 origen = {400, 250};

    // vector original (puedes cambiarlo)
    Vector2 v = {150, -90};

    while (!WindowShouldClose())
    {
        // Magnitud
        float mag = sqrtf(v.x * v.x + v.y * v.y);

        // Vector normalizado
        Vector2 vn = {0, 0};

        if (mag > 0)
        {
            vn.x = v.x / mag;
            vn.y = v.y / mag;
        }

        // Escalar el normalizado para verlo mejor
        Vector2 vnEscalado = {vn.x * 100, vn.y * 100};

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Magnitud y normalizacion de un vector", 180, 20, 24, DARKBLUE);

        // Ejes
        DrawLine(0, origen.y, 800, origen.y, LIGHTGRAY);
        DrawLine(origen.x, 0, origen.x, 500, LIGHTGRAY);

        // Origen
        DrawCircleV(origen, 5, BLACK);

        // Vector original
        Vector2 destino = {origen.x + v.x, origen.y + v.y};
        DrawLineEx(origen, destino, 3, RED);
        DrawCircleV(destino, 6, RED);

        // Vector normalizado (escalado para visualizar)
        Vector2 destinoN = {origen.x + vnEscalado.x, origen.y + vnEscalado.y};
        DrawLineEx(origen, destinoN, 3, BLUE);
        DrawCircleV(destinoN, 6, BLUE);

        // Información
        DrawText("Vector original (rojo)", 50, 350, 20, RED);
        DrawText("Vector normalizado (azul)", 50, 380, 20, BLUE);

        DrawText(TextFormat("vx = %.2f", v.x), 50, 420, 20, BLACK);
        DrawText(TextFormat("vy = %.2f", v.y), 50, 450, 20, BLACK);

        DrawText(TextFormat("|v| = %.2f", mag), 500, 350, 20, BLACK);

        DrawText(TextFormat("vn.x = %.2f", vn.x), 500, 390, 20, BLUE);
        DrawText(TextFormat("vn.y = %.2f", vn.y), 500, 420, 20, BLUE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
