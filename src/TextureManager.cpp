#include "./Headers/TextureManager.hpp"


void TextureManager::load_textures() {
  textures["heart1"] = LoadTexture("../res/heart1.png");
  textures["heart2"] = LoadTexture("../res/heart2.png");
  textures["heart3"] = LoadTexture("../res/heart3.png");
  textures["heart4"] = LoadTexture("../res/heart4.png");
  textures["heart5"] = LoadTexture("../res/heart5.png");
}


void TextureManager::unload_textures() {
  for (auto &texture : textures) {
    UnloadTexture(texture.second);
  }
}
