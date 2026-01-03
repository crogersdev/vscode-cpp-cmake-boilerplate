#include <iostream>

#include "raylib.h"

const bool DEBUG_GAME = false;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main(void) {

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Game!");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();
        std::cout << "Delta time: " << dt << "\n";

        BeginDrawing();
            ClearBackground(BLACK);
            DrawRectangle(100, 100, 200, 300, BLUE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
