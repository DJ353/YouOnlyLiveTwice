#include "./Headers/window.hpp"
#include "./Headers/Consts.hpp"
#include "./Headers/TextureManager.hpp"

#include "raylib.h"
#include <stdexcept>

TextureManager assets;

Display::Window::Window(int w, int h, std::string game_title)
  : width{w}, height{h}, title{game_title}, game{}
{
  // load all textures and fonts for the game
  init_window();
}

Display::Window::~Window() {
  assets.unload_textures();
  assets.unload_fonts();
}

void Display::Window::init_window() {
  InitWindow(width, height, title.c_str());
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  SetConfigFlags(FLAG_MSAA_4X_HINT); // enable anti-aliasing
  SetTargetFPS(60); // Set our game to run at 60 frames-per-second

  // -----------------------------------------------------------------------------
  // load all assets for the game
  // -----------------------------------------------------------------------------
  assets.load_textures();
  assets.load_fonts();
  // -----------------------------------------------------------------------------
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
      game.draw_intro();
      if (IsKeyPressed(KEY_ENTER))
        current_state = States::GAME;
      break;
    case States::GAME:
      game.draw_update();

      if (IsKeyPressed(KEY_ENTER))
        current_state = States::END;
      break;
    case States::END:
      game.draw_end();
      break;
    default:
      break;
  }
}
