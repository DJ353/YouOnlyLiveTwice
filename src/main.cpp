#include "raylib.h"
#include "./Headers/window.hpp"
#include "./Headers/Consts.hpp"


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
