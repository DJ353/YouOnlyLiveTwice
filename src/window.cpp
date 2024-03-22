#include "./Headers/window.hpp"
#include "./Headers/Consts.hpp"

#include "raylib.h"
#include <stdexcept>

static void intro();
static void update();
static void end();

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

  // -----------------------------------------------------------------------------
  // Main game loop
  while (!WindowShouldClose()) {
    BeginDrawing();
    run();
    EndDrawing();
  }
  // -----------------------------------------------------------------------------
}


// Define Game States
enum class States {
  INTRO,
  GAME,
  END,
};

// set current state
static States current_state = States::INTRO;

void Display::Window::run() {

  switch (current_state) {
    case States::INTRO:
      // display the intro screen
      intro();
      if (IsKeyPressed(KEY_ENTER))
        current_state = States::GAME;
      break;
    case States::GAME:
      update();

      if (IsKeyPressed(KEY_ENTER))
        current_state = States::END;
      break;
    case States::END:
      end();
      break;
    default:
      break;
  }
}


void intro() {
  ClearBackground({218, 224, 234, 255});
  DrawCircle(
      Consts::screen_width / 2.f,
      Consts::screen_height / 2.f + 60,
      150, // radius of circle
      {179, 185, 209, 255} // color
  );
  DrawText("You only live", 300, 200, 50, RED);
  DrawText("TWICE", 300, 250, 50, RED);
}

void update() {
  ClearBackground(RAYWHITE);
}

void end() {
  ClearBackground(RAYWHITE);
}


