#include "raylib.h"
#include <cmath>

// Calcula la magnitud de un vector
float Magnitud(Vector2 v)
{
    return sqrtf(v.x * v.x + v.y * v.y);
}

// Convierte un vector en vector unitario
Vector2 Normalizar(Vector2 v)
{
    float m = Magnitud(v);

    if (m == 0.0f)
        return {0.0f, 0.0f};

    return {v.x / m, v.y / m};
}

int main()
{
    const int screenWidth = 1200;
    const int screenHeight = 700;

    InitWindow(screenWidth, screenHeight, "Normalizacion de vectores y velocidad");
    SetTargetFPS(60);

    Vector2 posRojo = {100.0f, 250.0f};
    Vector2 posAzul = {100.0f, 500.0f};

    float velocidad = 220.0f;

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        Vector2 direccion = {0.0f, 0.0f};

        if (IsKeyDown(KEY_RIGHT)) direccion.x += 1.0f;
        if (IsKeyDown(KEY_LEFT))  direccion.x -= 1.0f;
        if (IsKeyDown(KEY_DOWN))  direccion.y += 1.0f;
        if (IsKeyDown(KEY_UP))    direccion.y -= 1.0f;

        Vector2 direccionNormalizada = Normalizar(direccion);

        // Rojo: usa la dirección sin normalizar
        posRojo.x += direccion.x * velocidad * dt;
        posRojo.y += direccion.y * velocidad * dt;

        // Azul: usa dirección normalizada
        posAzul.x += direccionNormalizada.x * velocidad * dt;
        posAzul.y += direccionNormalizada.y * velocidad * dt;

        // Reiniciar posiciones con R
        if (IsKeyPressed(KEY_R))
        {
            posRojo = {100.0f, 250.0f};
            posAzul = {100.0f, 500.0f};
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Normalizacion: direccion vs velocidad", 330, 20, 28, DARKBLUE);
        DrawText("Usa flechas. Para diagonal presiona dos teclas: RIGHT + UP, RIGHT + DOWN, etc.", 170, 60, 20, DARKGRAY);
        DrawText("Presiona R para reiniciar.", 470, 90, 20, DARKGRAY);

        DrawLine(80, 250, 1100, 250, LIGHTGRAY);
        DrawLine(80, 500, 1100, 500, LIGHTGRAY);

        DrawText("SIN NORMALIZAR", 80, 190, 24, RED);
        DrawText("En diagonal usa (1,1), cuya magnitud es sqrt(2) = 1.41", 80, 220, 20, RED);

        DrawText("CON NORMALIZACION", 80, 440, 24, BLUE);
        DrawText("En diagonal usa (1/sqrt(2),1/sqrt(2)), cuya magnitud es 1", 80, 470, 20, BLUE);

        DrawCircleV(posRojo, 14, RED);
        DrawCircleV(posAzul, 14, BLUE);

        float magDir = Magnitud(direccion);
        float magNorm = Magnitud(direccionNormalizada);

        DrawText("Datos actuales:", 780, 160, 22, BLACK);
        DrawText(TextFormat("Direccion = (%.1f, %.1f)", direccion.x, direccion.y), 780, 195, 20, BLACK);
        DrawText(TextFormat("Magnitud sin normalizar = %.2f", magDir), 780, 225, 20, RED);
        DrawText(TextFormat("Magnitud normalizada = %.2f", magNorm), 780, 255, 20, BLUE);

        DrawText("Idea clave:", 780, 320, 22, BLACK);
        DrawText("Si el vector mide mas,", 780, 355, 20, BLACK);
        DrawText("el objeto se mueve mas rapido.", 780, 380, 20, BLACK);
        DrawText("Normalizar fija la magnitud en 1.", 780, 410, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
