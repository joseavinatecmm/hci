#include "raylib.h"

int main()
{
    const int screenWidth = 900;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Practica: Teclado y Mouse");

    SetTargetFPS(60);

    // Posición del objeto (círculo)
    Vector2 position = {450, 300};
    float speed = 5.0f;

    while (!WindowShouldClose())
    {
        // -------------------------
        // ENTRADA POR TECLADO
        // -------------------------

        if (IsKeyDown(KEY_RIGHT)) position.x += speed;
        if (IsKeyDown(KEY_LEFT))  position.x -= speed;
        if (IsKeyDown(KEY_UP))    position.y -= speed;
        if (IsKeyDown(KEY_DOWN))  position.y += speed;

        // -------------------------
        // ENTRADA POR MOUSE
        // -------------------------

        Vector2 mousePos = GetMousePosition();

        // Si se hace clic izquierdo, mover el círculo al mouse
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            position = mousePos;
        }

        // -------------------------
        // DIBUJO
        // -------------------------

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Eventos de teclado y mouse", 230, 20, 24, DARKBLUE);

        DrawText("Flechas: mover el circulo", 20, 60, 20, BLACK);
        DrawText("Click izquierdo: mover al mouse", 20, 90, 20, BLACK);

        // Dibujar círculo controlado
        DrawCircleV(position, 15, RED);

        // Dibujar posición del mouse
        DrawCircleV(mousePos, 5, BLUE);

        DrawText(TextFormat("Mouse: (%.0f, %.0f)", mousePos.x, mousePos.y), 20, 130, 20, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
