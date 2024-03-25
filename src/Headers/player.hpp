#pragma once

#include "raylib.h"

class Player {
public:
  Player();
  void init_player();
  void draw_player();

private:
  float   speed;
  Vector2 position;
  Vector2 size;
};
