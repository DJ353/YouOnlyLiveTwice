cmake_minimum_required(VERSION 3.20)

project(YouOnlyLiveTwice
  VERSION 1.0
  DESCRIPTION "Game written in raylib"
  LANGUAGES CXX)

add_executable(game
  src/main.cpp
  src/flair.cpp
  src/game.cpp
  src/player.cpp
  src/TextureManager.cpp
  src/window.cpp
)

target_link_libraries(game raylib)
target_compile_options(game PRIVATE -Wall -Werror -Wextra -Wpedantic -O2)

