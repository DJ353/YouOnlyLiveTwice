#include "raylib.h"
#include "./Headers/window.hpp"
#include "./Headers/Consts.hpp"

// TODO: implement flaires in intro
// TODO: integrate rlImGui or DearImGui for level editing
// TODO: refactor game.cpp

int main() {
    
  Display::Window window = Display::Window(
      Consts::screen_width,
      Consts::screen_height,
      "You Only Live Twice"
  );

  window.display();

  // cleanup
  CloseWindow();
  return 0;
}
