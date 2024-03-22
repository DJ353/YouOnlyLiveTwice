#pragma once
#include <unordered_map>
#include "raylib.h"
#include <string>

class TextureManager {
  public:
    void load_textures();
    void unload_textures();
  private:
    std::unordered_map<std::string, Texture2D> textures;
};
