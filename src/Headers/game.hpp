#pragma once
#include "raylib.h"
#include "TextureManager.hpp"
#include "player.hpp"
#include <vector>

class Game {
public:
  Game();

  void draw_intro();
  void draw_update();
  void draw_end();

private:
  Camera2D camera;
  Player player;
  std::vector<Rectangle> map;
};
