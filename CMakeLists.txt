cmake_minimum_required(VERSION 3.20)

project(YouOnlyLiveTwice
  VERSION 1.0
  DESCRIPTION "Game written in raylib"
  LANGUAGES CXX)

# find_package(raylib 5.0 QUIET)
# include(FetchContent)
# if (NOT raylib_FOUND)
#    FetchContent_Declare(
#        raylib
#       URL https://github.com/raysan5/raylib/archive/refs/tags/5.0.tar.gz
#    )
#   FetchContent_MakeAvailable(raylib)
# endif()
# set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_executable(game
  src/main.cpp
  src/flair.cpp
  src/game.cpp
  src/player.cpp
  src/TextureManager.cpp
  src/window.cpp
)

target_link_libraries(game raylib)
target_include_directories(game PUBLIC "${raylib_SOURCE_DIR}/src")
target_compile_options(game PRIVATE -Wall -Werror -Wextra -Wpedantic -O2)

