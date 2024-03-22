#include "raylib.h"
#include "window.hpp"

int main() {

  constexpr int screenWidth = 1920;
  constexpr int screenHeight = 1080;
    
  Display::Window window = Display::Window(screenWidth, screenHeight, "You Only Live Twice");
  window.run();

  return 0;
}
