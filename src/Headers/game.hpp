#pragma once
#include "raylib.h"
#include "TextureManager.hpp"

class Game {
public:
  Game();

  void draw_intro();
  void draw_update();
  void draw_end();

private:
  Camera2D camera;
};
