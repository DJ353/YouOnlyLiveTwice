#include "./Headers/game.hpp"
#include "./Headers/Consts.hpp"
#include "./Headers/TextureManager.hpp"
#include "./Headers/flair.hpp"
#include "raylib.h"
#include <iostream>

extern TextureManager assets;

Game::Game()
  : player{}
{
  player.init_player();

  init_flaires();

  camera.rotation = 0;
  camera.zoom = 1;
  camera.offset = {Consts::screen_width / 2.f, Consts::screen_height / 2.f};
  camera.target = {0, 0};
}

static Rectangle fire_source_rec = {0, 0, 32, 32};
static Rectangle ice_source_rec = {0, 0, 32, 32};

static int frame_counter = 0;

void Game::draw_intro() {
  ClearBackground({210, 200, 230, 255});

  DrawTextEx(assets.get_fonts()["intro_font"], "You only live", {280, 100}, 70, 20, RED);
  DrawTextEx(assets.get_fonts()["intro_font"], "TWICE", {400, 230}, 70, 20, RED);

  // ---------------------------------------------------------------------------------------------------------
  // Draw black borders
  DrawRectangleRec({0, 0, Consts::screen_width, 30}, BLACK);
  DrawRectangleRec({0, 0, 30, Consts::screen_height}, BLACK);
  DrawRectangleRec({Consts::screen_width - 30, 0, 30, Consts::screen_height}, BLACK);
  DrawRectangleRec({0, Consts::screen_height - 30, Consts::screen_width, 30}, BLACK);


  // DrawRectangleGradientV(30, 30, Consts::screen_width - 60, 30, ORANGE, RED);
  // DrawRectangleGradientV(30, Consts::screen_height - 60, Consts::screen_width - 60, 30, DARKBLUE, SKYBLUE);

  DrawRectangleGradientH(30, 30, 30, Consts::screen_height - 60, ORANGE, RED);
  DrawRectangleGradientH(Consts::screen_width - 60, 30, 30, Consts::screen_height - 60, DARKBLUE, SKYBLUE);

  // ---------------------------------------------------------------------------------------------------------
  DrawTexturePro(assets.get_textures().at("fire_player"), fire_source_rec, {260, 220, 64, 64}, {0, 0}, 0, WHITE);
  DrawTexturePro(assets.get_textures().at("ice_player"), ice_source_rec, {700, 220, 64, 64}, {0, 0}, 0, WHITE);

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

  // TODO: implement flaires
  // draw_flaires();
}

void Game::draw_update() {
  ClearBackground(RAYWHITE);
  BeginMode2D(camera);
  player.draw_player();
  EndMode2D();
}

void Game::draw_end() {
  ClearBackground(RAYWHITE);
}
