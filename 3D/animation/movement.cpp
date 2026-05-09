#include "raylib.h"
#include <cmath>

int main()
{
    InitWindow(1300, 800, "Practica 5 - Movimientos Basicos en 3D");

    Camera3D camera = { 0 };
    camera.position = { 0.0f, 18.0f, 18.0f };
    camera.target = { 0.0f, 0.0f, 0.0f };
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetTargetFPS(60);

    float reboteY = 1.0f;
    float velocidadY = 0.08f;

    while (!WindowShouldClose())
    {
        UpdateCamera(&camera, CAMERA_ORBITAL);

        float t = (float)GetTime();

        float senoY = 2.0f + sinf(t * 2.0f) * 1.5f;

        reboteY += velocidadY;
        if (reboteY > 4.0f || reboteY < 1.0f)
        {
            velocidadY *= -1.0f;
        }

        float radio = 2.0f;
        float orbitaX = cosf(t) * radio;
        float orbitaZ = sinf(t) * radio;

        float trayectoriaX = -2.5f + fmodf(t * 1.5f, 5.0f);
        float trayectoriaZ = sinf(t * 3.0f) * 1.2f;

        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        DrawGrid(30, 1.0f);

        DrawCube({ -9.0f, 0.05f, 4.0f }, 5.0f, 0.1f, 5.0f, LIGHTGRAY);
        DrawCube({ -3.0f, 0.05f, 4.0f }, 5.0f, 0.1f, 5.0f, LIGHTGRAY);
        DrawCube({  3.0f, 0.05f, 4.0f }, 5.0f, 0.1f, 5.0f, LIGHTGRAY);
        DrawCube({  9.0f, 0.05f, 4.0f }, 5.0f, 0.1f, 5.0f, LIGHTGRAY);

        DrawSphere({ -9.0f, senoY, 4.0f }, 0.45f, BLUE);
        DrawLine3D({ -9.0f, 0.0f, 4.0f }, { -9.0f, 4.0f, 4.0f }, BLUE);
        DrawSphere({ -9.0f, 4.0f, 4.0f }, 0.12f, BLUE);
        DrawSphere({ -9.0f, 1.0f, 4.0f }, 0.12f, BLUE);

        DrawSphere({ -3.0f, reboteY, 4.0f }, 0.45f, RED);
        DrawCube({ -3.0f, 0.15f, 4.0f }, 2.0f, 0.3f, 2.0f, GRAY);
        DrawLine3D({ -3.0f, 0.3f, 4.0f }, { -3.0f, 4.0f, 4.0f }, RED);

        DrawSphere({ 3.0f + orbitaX, 1.0f, 4.0f + orbitaZ }, 0.45f, GREEN);
        DrawSphere({ 3.0f, 1.0f, 4.0f }, 0.2f, DARKGREEN);
        DrawSphereWires({ 3.0f, 1.0f, 4.0f }, radio, 24, 24, DARKGREEN);

        for (int i = 0; i < 80; i++)
        {
            float x1 = -2.5f + i * (5.0f / 80.0f);
            float x2 = -2.5f + (i + 1) * (5.0f / 80.0f);

            float z1 = sinf(x1 * 3.0f) * 1.2f;
            float z2 = sinf(x2 * 3.0f) * 1.2f;

            DrawLine3D(
                { 9.0f + x1, 1.0f, 4.0f + z1 },
                { 9.0f + x2, 1.0f, 4.0f + z2 },
                ORANGE
            );
        }

        DrawSphere({ 9.0f + trayectoriaX, 1.0f, 4.0f + trayectoriaZ }, 0.45f, ORANGE);

        EndMode3D();

        DrawText("Practica 5 - Movimiento en 3D", 20, 20, 30, DARKGRAY);

        DrawText("1. Movimiento senoidal", 120, 90, 22, BLUE);
        DrawText("Sube y baja suavemente", 120, 120, 18, DARKGRAY);

        DrawText("2. Rebote", 410, 90, 22, RED);
        DrawText("Cambia de direccion al tocar limites", 410, 120, 18, DARKGRAY);

        DrawText("3. Orbita", 690, 90, 22, GREEN);
        DrawText("Gira alrededor de un centro", 690, 120, 18, DARKGRAY);

        DrawText("4. Trayectoria", 970, 90, 22, ORANGE);
        DrawText("Sigue un camino ondulado", 970, 120, 18, DARKGRAY);

        DrawText("La escena esta dividida en cuatro zonas para comparar los movimientos.", 20, 730, 20, GRAY);
        DrawText("ESC para salir", 20, 760, 20, GRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
