#include "raylib.h"

int main()
{
    InitWindow(800, 500, "Vectores en 2D");
    SetTargetFPS(60);

    // Punto origen del vector
    Vector2 origen = {400, 250};

    // Vector (componentes)
    Vector2 v = {120, -80};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Vector v = (vx, vy)", 300, 20, 24, DARKBLUE);

        // Dibujar ejes
        DrawLine(0, origen.y, 800, origen.y, LIGHTGRAY);
        DrawLine(origen.x, 0, origen.x, 500, LIGHTGRAY);

        // Dibujar origen
        DrawCircleV(origen, 5, BLACK);

        // Punto final del vector
        Vector2 destino = {origen.x + v.x, origen.y + v.y};

        // Dibujar vector
        DrawLineEx(origen, destino, 3, RED);

        // Punta del vector (flecha simple)
        DrawCircleV(destino, 6, RED);

        // Componentes (proyecciones)
        DrawLine(origen.x, origen.y, destino.x, origen.y, BLUE); // vx
        DrawLine(destino.x, origen.y, destino.x, destino.y, GREEN); // vy

        // Etiquetas
        DrawText("Origen", origen.x + 10, origen.y + 10, 18, BLACK);
        DrawText("v", destino.x + 10, destino.y, 20, RED);

        DrawText(TextFormat("vx = %.0f", v.x), origen.x + v.x / 2, origen.y + 10, 18, BLUE);
        DrawText(TextFormat("vy = %.0f", v.y), destino.x + 10, origen.y + v.y / 2, 18, GREEN);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
