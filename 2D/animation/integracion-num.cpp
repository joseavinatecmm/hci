#include "raylib.h"

int main()
{
    InitWindow(900, 600, "Integracion numerica (Euler)");
    SetTargetFPS(60);

    float x = 100.0f;          // posicion inicial
    float y = 300.0f;

    float v = 200.0f;          // velocidad (pixeles/segundo)

    float acumulado = 0.0f;    // suma de desplazamientos
    int pasos = 0;             // numero de frames

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        // incremento por frame
        float dx = v * dt;

        // integración numérica
        x += dx;

        // acumulación explícita
        acumulado += dx;
        pasos++;

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("INTEGRACION NUMERICA: x = x + v * dt", 180, 30, 26, DARKBLUE);

        // línea base
        DrawLine(50, y, 850, y, LIGHTGRAY);

        // punto en movimiento
        DrawCircle((int)x, y, 12, RED);

        // punto inicial
        DrawCircle(100, y, 6, DARKGRAY);
        DrawText("x0", 90, y + 20, 20, DARKGRAY);

        // información numérica
        DrawText("Datos:", 50, 120, 22, BLACK);

        DrawText(TextFormat("dt = %.4f", dt), 50, 160, 20, BLACK);
        DrawText(TextFormat("dx = v * dt = %.2f", dx), 50, 190, 20, RED);
        DrawText(TextFormat("pasos = %d", pasos), 50, 220, 20, BLACK);

        DrawText(TextFormat("posicion actual x = %.2f", x), 50, 260, 20, BLUE);

        DrawText("Interpretacion:", 50, 320, 22, BLACK);

        DrawText("Cada frame suma un pequeno desplazamiento", 50, 350, 20, BLACK);
        DrawText("x = x0 + sumatoria(dx)", 50, 380, 20, DARKGREEN);

        DrawText(TextFormat("suma dx = %.2f", acumulado), 50, 410, 20, DARKGREEN);

        DrawText("Modelo continuo:", 550, 150, 22, BLACK);
        DrawText("x(t) = x0 + v*t", 550, 190, 22, DARKBLUE);

        DrawText("Aproximacion discreta:", 550, 240, 22, BLACK);
        DrawText("x = x + v*dt", 550, 280, 22, RED);

        DrawText("Observa: el movimiento es acumulativo", 550, 350, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
