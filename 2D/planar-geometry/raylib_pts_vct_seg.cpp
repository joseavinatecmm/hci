#include "raylib.h"
#include <cmath>

// Dibuja un vector 2D con punta de flecha
void DrawVector2D(Vector2 origin, Vector2 end, Color color)
{
    DrawLineV(origin, end, color);

    float dx = end.x - origin.x;
    float dy = end.y - origin.y;
    float angle = atan2f(dy, dx);

    float arrowSize = 15.0f;
    float arrowAngle = 0.5f;

    Vector2 left = {
        end.x - arrowSize * cosf(angle - arrowAngle),
        end.y - arrowSize * sinf(angle - arrowAngle)
    };

    Vector2 right = {
        end.x - arrowSize * cosf(angle + arrowAngle),
        end.y - arrowSize * sinf(angle + arrowAngle)
    };

    DrawLineV(end, left, color);
    DrawLineV(end, right, color);
}

int main()
{
    const int screenWidth = 950;
    const int screenHeight = 620;

    InitWindow(screenWidth, screenHeight, "Practica 02 - Puntos, vectores y segmentos");
    SetTargetFPS(60);

    Vector2 point = {160.0f, 130.0f};

    Vector2 segA = {120.0f, 360.0f};
    Vector2 segB = {360.0f, 360.0f};

    Vector2 vecOrigin = {560.0f, 430.0f};
    Vector2 vecEnd = {800.0f, 240.0f};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Practica 02: Punto, segmento y vector", 240, 18, 30, DARKBLUE);
        DrawText("Interpretacion geometrica de objetos basicos en 2D", 255, 52, 20, GRAY);

        // Punto
        DrawText("Punto P", 120, 82, 22, MAROON);
        DrawCircleV(point, 7.0f, RED);
        DrawText("P(160,130)", 180, 122, 20, MAROON);

        // Segmento
        DrawText("Segmento AB", 155, 290, 22, DARKGREEN);
        DrawLineEx(segA, segB, 3.0f, GREEN);
        DrawCircleV(segA, 5.0f, DARKGREEN);
        DrawCircleV(segB, 5.0f, DARKGREEN);
        DrawText("A", (int)segA.x - 18, (int)segA.y - 10, 20, DARKGREEN);
        DrawText("B", (int)segB.x + 8, (int)segB.y - 10, 20, DARKGREEN);

        // Vector
        DrawText("Vector v", 640, 190, 22, PURPLE);
        DrawVector2D(vecOrigin, vecEnd, PURPLE);
        DrawCircleV(vecOrigin, 5.0f, PURPLE);
        DrawText("Origen", (int)vecOrigin.x - 20, (int)vecOrigin.y + 12, 18, PURPLE);
        DrawText("Extremo", (int)vecEnd.x - 22, (int)vecEnd.y - 32, 18, PURPLE);

        // Componentes del vector
        float vx = vecEnd.x - vecOrigin.x;
        float vy = vecEnd.y - vecOrigin.y;
        DrawText(TextFormat("Componentes: (%.1f, %.1f)", vx, vy), 520, 500, 20, DARKPURPLE);

        // Ejes de referencia
        DrawLine(0, screenHeight/2, screenWidth, screenHeight/2, LIGHTGRAY);
        DrawLine(screenWidth/2, 0, screenWidth/2, screenHeight, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
