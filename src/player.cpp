#include "./Headers/player.hpp"
#include "./Headers/TextureManager.hpp"
#include "./Headers/Consts.hpp"
#include <raylib.h>

Player::Player() {
  init_player();
}

void Player::init_player() {
  m_position = {
    Consts::screen_width / 2.f - 30,
    Consts::screen_height / 2.f - 60,
  };
  m_size = {32, 32};
  m_speed = 150.f;

  m_texture = texture_manager.get_textures()["fire_player.png"];
}

void Player::draw_player() {

  // move the player in x-direction if proper buttons have been pressed
  if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))  m_position.x -= m_speed * GetFrameTime();
  if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) m_position.x += m_speed * GetFrameTime();

  DrawTextureEx(m_texture, m_position, 0, 0, WHITE);
}
