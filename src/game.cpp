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
  init_flares();

  camera.rotation = 0;
  camera.zoom = 1;
  camera.offset = {Consts::screen_width / 2.f, Consts::screen_height / 2.f};
  camera.target = {0, 0};

  map = {
    {400, 100, 100, 50},
    {600, 200, 100, 50},
    {200, 200, 300, 50},
    {1200, 100, 200, 50},
    {800, 50, 150, 50},
  };
}

static Rectangle fire_source_rec = {0, 0, 32, 32};
static Rectangle ice_source_rec = {0, 0, 32, 32};

static int frame_counter = 0;

void Game::draw_intro() {

  ClearBackground({220, 210, 230, 255});

  draw_flares();

  DrawTextEx(assets.get_fonts()["intro_font"], "You only live", {280, 100}, 70, 20, RED);
  DrawTextEx(assets.get_fonts()["intro_font"], "TWICE", {400, 230}, 70, 20, RED);

  // ---------------------------------------------------------------------------------------------------------
  // DrawRectangleGradientV(30, 30, Consts::screen_width - 60, 30, ORANGE, RED);
  // DrawRectangleGradientV(30, Consts::screen_height - 60, Consts::screen_width - 60, 30, DARKBLUE, SKYBLUE);

  DrawRectangleGradientH(0, 0, 50, Consts::screen_height, ORANGE, RED);
  DrawRectangleGradientH(Consts::screen_width - 50, 0, 50, Consts::screen_height, DARKBLUE, SKYBLUE);

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
  if (frame_counter >= 30)
    DrawText("[PRESS ENTER TO PLAY]", 200, 350, 50, GRAY);
  if (frame_counter > 60)
    frame_counter = 0;
  frame_counter++;
}

void Game::draw_update() {
  ClearBackground(RAYWHITE);
  BeginMode2D(camera);

  if (player.get_position().x > -16) {
    camera.target = {player.get_position().x + 32, 0};
  }
  for (auto &rec : map) {
    DrawRectangleRec(rec, RED);
  }

  player.draw();
  player.move();


  EndMode2D();
}

void Game::draw_end() {
  ClearBackground(RAYWHITE);
}
