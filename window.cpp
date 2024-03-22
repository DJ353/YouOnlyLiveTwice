#include "window.hpp"
#include "raylib.h"

Display::Window::Window(int w, int h, std::string game_title)
  : width{w}, height{h}, title{game_title}
{
  init_window();
}

void Display::Window::init_window() {
  InitWindow(width, height, title.c_str());
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  SetTargetFPS(60); // Set our game to run at 60 frames-per-second
}

void Display::Window::display() {
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    EndDrawing();
  }
}

void Display::Window::run() {
}
