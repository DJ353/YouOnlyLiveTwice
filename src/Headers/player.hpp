#pragma once

#include "raylib.h"

class Player {
public:
  Player();
  void draw();
  void move();

  Vector2 get_position();

private:
  float speed;
  float gravity;
  bool mid_air;
  Vector2 position;
  Vector2 size;
};
