#include <raylib.h>
#include <iostream>

int main() {
    int screenWidth = 1920;
    int screenHeight = 1080;
    
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "You Only Live Twice");
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }
}