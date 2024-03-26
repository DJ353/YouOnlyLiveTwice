#pragma once

#include "raylib.h"
#include "game.hpp"
#include "TextureManager.hpp"
#include <string>

namespace Display {
  class Window {
    public:

      Window(int w, int h, std::string title);
      ~Window();

      void init_window();
      void display();
      void run();

    private:
      int width, height;
      std::string title;
      Game game;
  };
} // namespace Display

