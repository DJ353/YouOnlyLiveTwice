#pragma once

#include "raylib.h"
#include <string>

namespace Display {
  class Window {
    public:

      Window(int w, int h, std::string title);

      void init_window();
      void display();
      void run();
    private:
      int width, height;
      std::string title;
  };
} // namespace Display

