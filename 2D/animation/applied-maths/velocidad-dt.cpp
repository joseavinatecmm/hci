#include "raylib.h"

int main()
{
    InitWindow(1100, 650, "Velocidad y dt con limites");
    
    int fps = 60;
    SetTargetFPS(fps);

    float velocidad = 200.0f;

    float posSinDT = 100.0f;
    float posConDT = 100.0f;

    float dirSinDT = 1.0f;
    float dirConDT = 1.0f;

    int limiteIzq = 80;
    int limiteDer = 1050;

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        // Cambiar FPS
        if (IsKeyPressed(KEY_ONE))  { fps = 30; SetTargetFPS(fps); }
        if (IsKeyPressed(KEY_TWO))  { fps = 60; SetTargetFPS(fps); }
        if (IsKeyPressed(KEY_THREE)){ fps = 120; SetTargetFPS(fps); }

        // 🔴 SIN dt
        posSinDT += dirSinDT * velocidad * 0.016f;

        // 🔵 CON dt
        posConDT += dirConDT * velocidad * dt;

        // Rebote rojo
        if (posSinDT >= limiteDer || posSinDT <= limiteIzq)
            dirSinDT *= -1;

        // Rebote azul
        if (posConDT >= limiteDer || posConDT <= limiteIzq)
            dirConDT *= -1;

        // Reiniciar
        if (IsKeyPressed(KEY_R))
        {
            posSinDT = 100;
            posConDT = 100;
            dirSinDT = 1;
            dirConDT = 1;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Velocidad y dt (con limites)", 320, 20, 28, DARKBLUE);

        DrawText("1:30 FPS  2:60 FPS  3:120 FPS   R: reiniciar", 260, 60, 20, DARKGRAY);

        DrawLine(limiteIzq, 250, limiteDer, 250, LIGHTGRAY);
        DrawLine(limiteIzq, 450, limiteDer, 450, LIGHTGRAY);

        DrawText("SIN dt (ERROR)", limiteIzq, 210, 24, RED);
        DrawText("Depende de FPS", limiteIzq, 235, 20, RED);

        DrawCircle((int)posSinDT, 250, 12, RED);

        DrawText("CON dt (CORRECTO)", limiteIzq, 410, 24, BLUE);
        DrawText("Velocidad constante", limiteIzq, 435, 20, BLUE);

        DrawCircle((int)posConDT, 450, 12, BLUE);

        DrawText("Datos:", 750, 200, 24, BLACK);

        DrawText(TextFormat("FPS = %d", fps), 750, 240, 20, BLACK);
        DrawText(TextFormat("dt = %.4f", dt), 750, 270, 20, BLACK);

        DrawText("Modelo:", 750, 320, 22, BLACK);
        DrawText("pos = pos + v * constante", 750, 380, 20, RED);
        DrawText("pos = pos + v * dt", 750, 350, 20, BLUE);

        DrawText("Observa:", 750, 430, 22, BLACK);
        DrawText("- Cambia FPS", 750, 460, 20, BLACK);
        DrawText("- El rojo cambia velocidad", 750, 485, 20, RED);
        DrawText("- El azul NO", 750, 510, 20, BLUE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
