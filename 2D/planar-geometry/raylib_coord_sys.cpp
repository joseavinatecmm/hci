#include "raylib.h"

int main()
{
    const int screenWidth = 900;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Sistema de coordenadas en pantalla");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // ---------------------------------------
        // TITULO
        // ---------------------------------------
        DrawText("Sistema de coordenadas en pantalla (raylib)", 150, 20, 26, DARKBLUE);

        // ---------------------------------------
        // EJES DE REFERENCIA
        // ---------------------------------------
        DrawLine(0, 0, screenWidth, 0, GRAY);             // eje superior
        DrawLine(0, 0, 0, screenHeight, GRAY);            // eje izquierdo

        DrawText("(0,0)", 5, 5, 18, BLACK);

        // ---------------------------------------
        // PUNTOS DE REFERENCIA IMPORTANTES
        // ---------------------------------------

        // Centro
        Vector2 centro = {screenWidth/2.0f, screenHeight/2.0f};
        DrawCircleV(centro, 6, RED);
        DrawText("Centro", centro.x + 10, centro.y, 18, RED);

        // Esquina inferior derecha
        Vector2 esquina = {screenWidth - 10, screenHeight - 10};
        DrawCircleV(esquina, 6, BLUE);
        DrawText("Esquina inferior derecha", esquina.x - 220, esquina.y - 20, 18, BLUE);

        // ---------------------------------------
        // CUADRANTES VISUALES (guia)
        // ---------------------------------------
        DrawLine(0, screenHeight/2, screenWidth, screenHeight/2, LIGHTGRAY);
        DrawLine(screenWidth/2, 0, screenWidth/2, screenHeight, LIGHTGRAY);

        DrawText("Q1", 700, 150, 30, LIGHTGRAY);
        DrawText("Q2", 150, 150, 30, LIGHTGRAY);
        DrawText("Q3", 150, 450, 30, LIGHTGRAY);
        DrawText("Q4", 700, 450, 30, LIGHTGRAY);

        // ---------------------------------------
        // PUNTOS EJEMPLO
        // ---------------------------------------

        // Punto rojo
        DrawCircle(100, 100, 5, RED);
        DrawText("(100,100)", 110, 95, 18, RED);

        // Punto verde
        DrawCircle(300, 200, 5, GREEN);
        DrawText("(300,200)", 310, 195, 18, GREEN);

        // Punto azul
        DrawCircle(600, 400, 5, BLUE);
        DrawText("(600,400)", 610, 395, 18, BLUE);

        // ---------------------------------------
        // LINEA DE REFERENCIA
        // ---------------------------------------
        DrawLine(0, 300, screenWidth, 300, ORANGE);
        DrawText("y = 300", 10, 305, 18, ORANGE);

        // ---------------------------------------
        // EXPLICACION VISUAL
        // ---------------------------------------
        DrawText("x aumenta hacia la derecha", 40, 520, 20, DARKGRAY);
        DrawText("y aumenta hacia abajo", 40, 550, 20, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
