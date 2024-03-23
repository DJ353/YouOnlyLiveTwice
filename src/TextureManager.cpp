// Font has been taken from:
// https://github.com/raysan5/raylib/tree/master/examples/text/resources/fonts

#include "./Headers/TextureManager.hpp"
#include "raylib.h"


void TextureManager::load_textures() {
  textures["heart1"] = LoadTexture("../res/Assets/heart1.png");
  textures["heart2"] = LoadTexture("../res/Assets/heart2.png");
  textures["heart3"] = LoadTexture("../res/Assets/heart3.png");
  textures["heart4"] = LoadTexture("../res/Assets/heart4.png");
  textures["heart5"] = LoadTexture("../res/Assets/heart5.png");

  // player sprites
  // -------------------------------------------------------------------------------------
  textures["fire_player"] = LoadTexture("../res/Assets/fire_player.png");
  textures["ice_player"] = LoadTexture("../res/Assets/ice_player.png");
  // -------------------------------------------------------------------------------------
}

void TextureManager::unload_textures() {
  for (auto &texture : textures)
  {
    UnloadTexture(texture.second);
  }
}

void TextureManager::load_fonts() {
  fonts["intro_font"] = LoadFont("../res/Fonts/jupiter_crash.png");
}


void TextureManager::unload_fonts() {
  for (auto &font : fonts)
  {
    UnloadFont(font.second);
  }
}

std::unordered_map<std::string, Texture2D> TextureManager::get_textures() {
  return this->textures;
}

std::unordered_map<std::string, Font> TextureManager::get_fonts() {
  return this->fonts;
}
