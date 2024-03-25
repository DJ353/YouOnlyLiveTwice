#include "./Headers/player.hpp"
#include "./Headers/TextureManager.hpp"
#include "./Headers/Consts.hpp"
#include <raylib.h>

extern TextureManager assets;

Player::Player() {
  init_player();
}

void Player::init_player() {
  position = {
    -300,
    0,
  };
  size = {32, 32};
  speed = 150.f;
}

static Rectangle fire_source_rec = {0, 0, 32, 32};
static Rectangle ice_source_rec = {0, 0, 32, 32};

static int frame_counter = 0;

void Player::draw_player() {

  // move the player in x-direction if proper buttons have been pressed
  if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))  position.x -= speed * GetFrameTime();
  if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) position.x += speed * GetFrameTime();

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

  DrawTexturePro(assets.get_textures().at("fire_player"), fire_source_rec, {position.x, position.y, 64, 64}, {0, 0}, 0, WHITE);
}
