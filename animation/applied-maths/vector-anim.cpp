#include "raylib.h"

int main()
{
    InitWindow(900, 600, "Algebra Lineal 1 - Vector como desplazamiento");
    SetTargetFPS(60);

    Vector2 punto = {200, 300};
    Vector2 desplazamiento = {250, -120};

    while (!WindowShouldClose())
    {
        Vector2 puntoFinal = {
            punto.x + desplazamiento.x,
            punto.y + desplazamiento.y
        };

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Vector como desplazamiento", 260, 30, 26, DARKBLUE);

        DrawCircleV(punto, 8, RED);
        DrawText("P", punto.x - 20, punto.y + 15, 20, RED);

        DrawCircleV(puntoFinal, 8, BLUE);
        DrawText("P' = P + v", puntoFinal.x + 10, puntoFinal.y, 20, BLUE);

        DrawLineEx(punto, puntoFinal, 4, DARKGREEN);

        DrawText("Modelo matematico:", 40, 470, 22, BLACK);
        DrawText("P' = P + v", 40, 500, 22, DARKGREEN);
        DrawText(TextFormat("P = (%.0f, %.0f)", punto.x, punto.y), 40, 530, 20, BLACK);
        DrawText(TextFormat("v = (%.0f, %.0f)", desplazamiento.x, desplazamiento.y), 260, 530, 20, BLACK);
        DrawText(TextFormat("P' = (%.0f, %.0f)", puntoFinal.x, puntoFinal.y), 500, 530, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
