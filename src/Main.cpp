#include <raylib.h>

#include "Button.hpp"
#include <iostream>

int main()
{
    int w = 1280, h = 720;
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(w, h, "RayGUI");

    Button button(
        Rectangle{(float)w / 2, (float)h / 2, 150, 75}, "Click me!", []() {}, DefaultButtonConfig);

    while (!WindowShouldClose())
    {
        Vector2 oldWinSize = {(float)w, (float)h};
        Vector2 newWinSize = {(float)GetRenderWidth(), (float)GetRenderHeight()};
        if (oldWinSize.x != newWinSize.x || oldWinSize.y != newWinSize.y)
        {
            button.Resize(oldWinSize, newWinSize);
        }

        button.Update();

        BeginDrawing();
        ClearBackground(BLACK);
        button.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}