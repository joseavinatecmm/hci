#include "raylib.h"

int main()
{
    const int screenWidth = 1000;
    const int screenHeight = 500;

    InitWindow(screenWidth, screenHeight, "FPS, velocidad y rebote");
    SetTargetFPS(60);

    float radio = 30.0f;
    Vector2 posicion = {120.0f, screenHeight / 2.0f};

    // Rapidez: siempre positiva
    float rapidez = 250.0f;

    // Dirección: +1 derecha, -1 izquierda
    int direccion = 1;

    float rapidezMin = 50.0f;
    float rapidezMax = 800.0f;
    float incremento = 50.0f;

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        // Cambiar solo la rapidez, no la dirección
        if (IsKeyPressed(KEY_UP))
        {
            rapidez += incremento;
            if (rapidez > rapidezMax)
                rapidez = rapidezMax;
        }

        if (IsKeyPressed(KEY_DOWN))
        {
            rapidez -= incremento;
            if (rapidez < rapidezMin)
                rapidez = rapidezMin;
        }

        // Velocidad efectiva
        float velocidadX = direccion * rapidez;

        // Actualizar posición
        posicion.x += velocidadX * dt;

        // Rebote en borde derecho
        if (posicion.x >= screenWidth - radio)
        {
            posicion.x = screenWidth - radio;
            direccion = -1;
        }

        // Rebote en borde izquierdo
        if (posicion.x <= radio)
        {
            posicion.x = radio;
            direccion = 1;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Circulo en movimiento sobre el eje X", 290, 20, 28, DARKBLUE);
        DrawText("UP: aumentar rapidez", 40, 70, 22, DARKGREEN);
        DrawText("DOWN: disminuir rapidez", 40, 100, 22, MAROON);

        DrawLine(0, screenHeight / 2, screenWidth, screenHeight / 2, LIGHTGRAY);

        DrawCircleV(posicion, radio, ORANGE);

        DrawText(TextFormat("FPS actuales: %d", GetFPS()), 40, 160, 24, BLACK);
        DrawText(TextFormat("dt: %.4f segundos", dt), 40, 195, 24, BLACK);
        DrawText(TextFormat("Rapidez: %.2f pixeles/segundo", rapidez), 40, 230, 24, BLACK);
        DrawText(TextFormat("Direccion: %s", (direccion == 1 ? "Derecha" : "Izquierda")), 40, 265, 24, BLACK);
        DrawText(TextFormat("Velocidad X: %.2f", velocidadX), 40, 300, 24, BLACK);
        DrawText(TextFormat("Posicion X: %.2f", posicion.x), 40, 335, 24, BLACK);

        DrawText("Ecuacion usada: x = x + (direccion * rapidez) * dt", 40, 390, 24, DARKBLUE);
        DrawText("Las flechas solo cambian la rapidez; el rumbo cambia solo al rebotar.", 40, 425, 24, DARKBLUE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
