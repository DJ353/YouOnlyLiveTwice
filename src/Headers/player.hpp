#pragma once

#include "raylib.h"
#include "TextureManager.hpp"

class Player {
public:
  Player();
  void init_player();
  void draw_player();

private:
  float   m_speed;
  Vector2 m_position;
  Vector2 m_size;

  Texture2D m_texture;
  TextureManager texture_manager;
};
