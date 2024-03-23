#pragma once
#include <unordered_map>
#include "raylib.h"
#include <string>

class TextureManager {
  public:
    void load_textures();
    void unload_textures();
    void load_fonts();
    void unload_fonts();

    std::unordered_map<std::string, Texture2D> get_textures();
    std::unordered_map<std::string, Font> get_fonts();

  private:
    std::unordered_map<std::string, Texture2D> textures;
    std::unordered_map<std::string, Font> fonts;
};
