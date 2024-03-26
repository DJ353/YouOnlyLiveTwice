#include "./Headers/player.hpp"
#include "./Headers/TextureManager.hpp"
#include "./Headers/Consts.hpp"
#include <raylib.h>

extern TextureManager assets;

Player::Player()
  : speed{350},
  gravity{200},
  mid_air{false},
  position{-400, 200}, size{32, 32}
{
}

Vector2 Player::get_position() { return this->position; }

static Rectangle fire_source_rec = {0, 0, 32, 32};
static Rectangle ice_source_rec = {0, 0, 32, 32};

static int frame_counter = 0;

void Player::draw() {
  DrawTexturePro(assets.get_textures().at("fire_player"), fire_source_rec, {position.x, position.y, 64, 64}, {0, 0}, 0, WHITE);
}

void Player::move() {
  // move the player in x-direction if proper buttons have been pressed
  if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))  position.x -= speed * GetFrameTime();
  if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) position.x += speed * GetFrameTime();

  // update the player animation using a frame-counter
  // ----------------------------------------------------------------------------------
  if (fire_source_rec.x >= 96) fire_source_rec.x = 0;
  if (ice_source_rec.x >= 96)
    ice_source_rec.x = 0;

  if (frame_counter % 5 == 0) {
    fire_source_rec.x += 32;
    ice_source_rec.x += 32;
  }
  if (frame_counter > 20)
    frame_counter = 0;
  frame_counter++;
  // ----------------------------------------------------------------------------------

  // ----------------------------------------------------------------------------------
  // gravity for the player

  if (IsKeyPressed(KEY_SPACE))
    mid_air = true;

  if (mid_air) {
    position.y -= gravity * GetFrameTime();
    gravity -= 300 * GetFrameTime();
  }

  if (position.y > 200) {
    mid_air = false;
    gravity = 200;
  }
  // ----------------------------------------------------------------------------------
}
