#include <iostream>
#include "simulation3d.hpp"
#include <raylib.h>

const int screenWidth = 1200;
const int screenHeight = 800;
int field = 50;
const int cellSize = 2;
int FPS = 120;

int main()
{
    InitWindow(screenWidth, screenHeight, "Game Of Life");
    Camera3D camera = { 0 };
    camera.position = { 100.0f, 100.0f, 100.0f };
    camera.target =  { (float)field/2, (float)field / 2, (float)field / 2 };
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetTargetFPS(FPS);

    Simulation simulation{ field, field, field, cellSize};

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_ENTER))
        {
            simulation.Start();
            SetWindowTitle("Game Of Life is running...");
        }
        else if (IsKeyPressed(KEY_SPACE))
        {
            simulation.Stop();
            SetWindowTitle("Game Of Life stopped...");
        }
        else if (IsKeyDown(KEY_F))
        {
            FPS += 2;
            SetTargetFPS(FPS);
        }
        else if (IsKeyDown(KEY_S))
        {
            if (FPS > 5)
            {
                FPS -= 2;
                SetTargetFPS(FPS);
            }
        }
        else if (IsKeyPressed(KEY_R))
        {
            simulation.CreateRandomnState();
        }
        else if (IsKeyPressed(KEY_C))
        {
            simulation.ClearGrid();
        }
        UpdateCamera(&camera, CAMERA_ORBITAL);
        simulation.Update();
        BeginDrawing();
        DrawFPS(10, 10);
        ClearBackground({ 128,128,128,225 });
        BeginMode3D(camera); 
        simulation.Draw();
        EndMode3D();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}