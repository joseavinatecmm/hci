#include "raylib.h"

int main()
{
    InitWindow(800, 600, "Traslacion con teclado");
    SetTargetFPS(60);

    Vector2 posicion = {400, 300};
    float lado = 100;
    float velocidad = 300.0f;

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        if (IsKeyDown(KEY_RIGHT))
            posicion.x += velocidad * dt;

        if (IsKeyDown(KEY_LEFT))
            posicion.x -= velocidad * dt;

        if (IsKeyDown(KEY_UP))
            posicion.y -= velocidad * dt;

        if (IsKeyDown(KEY_DOWN))
            posicion.y += velocidad * dt;

        // Dibujo
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Mover con flechas", 320, 20, 20, DARKBLUE);

        DrawRectangle(
            posicion.x - lado/2,
            posicion.y - lado/2,
            lado,
            lado,
            BLUE
        );

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
