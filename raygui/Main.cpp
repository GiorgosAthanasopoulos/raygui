#include <raylib.h>

#include "Button.hpp"
#include "Utils.hpp"

int main()
{
    Vector2 winSize = { 1280, 720 };
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(winSize.x, winSize.y, "RayGUI");
    // InitAudioDevice
    // SetTargetFPS
    // SetExitKey

    Button button;

    while (!WindowShouldClose())
    {
        Vector2 newWinSize = {(float)GetRenderWidth(), (float)GetRenderHeight()};
        if (newWinSize.x != winSize.x || newWinSize.y != winSize.y)
        {
            button.Resize(winSize, newWinSize);
            winSize = newWinSize;
        }

        button.Update();

        BeginDrawing();
        ClearBackground(BLACK);
        button.Draw();
        EndDrawing();
    }

    // CloseAudioDevice
    CloseWindow();
    return 0;
}