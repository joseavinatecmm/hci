#include "raylib.h"
#include <cmath>

Vector2 RotarConMatriz(Vector2 p, float theta)
{
    Vector2 r;

    r.x = p.x * cosf(theta) - p.y * sinf(theta);
    r.y = p.x * sinf(theta) + p.y * cosf(theta);

    return r;
}

void DibujarCuadradoRotado(Vector2 centro, float lado, float theta, Color color)
{
    Vector2 v1 = {-lado/2, -lado/2};
    Vector2 v2 = { lado/2, -lado/2};
    Vector2 v3 = { lado/2,  lado/2};
    Vector2 v4 = {-lado/2,  lado/2};

    v1 = RotarConMatriz(v1, theta);
    v2 = RotarConMatriz(v2, theta);
    v3 = RotarConMatriz(v3, theta);
    v4 = RotarConMatriz(v4, theta);

    v1.x += centro.x; v1.y += centro.y;
    v2.x += centro.x; v2.y += centro.y;
    v3.x += centro.x; v3.y += centro.y;
    v4.x += centro.x; v4.y += centro.y;

    DrawLineEx(v1, v2, 4, color);
    DrawLineEx(v2, v3, 4, color);
    DrawLineEx(v3, v4, 4, color);
    DrawLineEx(v4, v1, 4, color);

    DrawCircleV(centro, 5, BLACK);
}

int main()
{
    InitWindow(1000, 600, "Comparacion: rotacion por frame vs rotacion por tiempo");
    SetTargetFPS(60);

    Vector2 centroIzquierdo = {280, 300};
    Vector2 centroDerecho = {720, 300};

    float lado = 140.0f;

    float thetaPorFrame = 0.0f;
    float thetaPorTiempo = 0.0f;

    float incrementoPorFrame = 0.03f;
    float velocidadAngular = 1.8f; // radianes por segundo

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        // Método 1: depende del número de frames
        thetaPorFrame += incrementoPorFrame;

        // Método 2: depende del tiempo real transcurrido
        thetaPorTiempo += velocidadAngular * dt;

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Rotacion de un cuadrado usando matriz", 250, 25, 28, DARKBLUE);

        DrawText("Metodo A: incremento fijo por frame", 110, 90, 20, RED);
        DrawText("theta += 0.03", 175, 120, 20, RED);
        DrawText("Depende de los FPS", 170, 150, 20, MAROON);

        DrawText("Metodo B: incremento usando tiempo real", 560, 90, 20, BLUE);
        DrawText("theta += omega * GetFrameTime()", 560, 120, 20, BLUE);
        DrawText("No depende directamente de los FPS", 570, 150, 20, DARKBLUE);

        DibujarCuadradoRotado(centroIzquierdo, lado, thetaPorFrame, RED);
        DibujarCuadradoRotado(centroDerecho, lado, thetaPorTiempo, BLUE);

        DrawText("Matriz usada en ambos casos:", 330, 455, 22, BLACK);
        DrawText("[ cos(theta)  -sin(theta) ]", 330, 485, 22, DARKGREEN);
        DrawText("[ sin(theta)   cos(theta) ]", 330, 515, 22, DARKGREEN);

        DrawText(TextFormat("FPS: %d", GetFPS()), 40, 540, 20, BLACK);
        DrawText(TextFormat("dt: %.4f s", dt), 150, 540, 20, BLACK);

        DrawText(TextFormat("theta A: %.2f rad", thetaPorFrame), 40, 500, 20, RED);
        DrawText(TextFormat("theta B: %.2f rad", thetaPorTiempo), 760, 500, 20, BLUE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
