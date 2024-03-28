# You only Live TWICE

<p align=center>
    <img src="./res/Assets/title_screen.png">
</p>

## Requirements:
[raylib]("https://www.raylib.com/") has to be installed

## Quick Start
### Compile manually:
```console
$ cd src
$ g++ main.cpp player.cpp TextureManager.cpp window.cpp flair.cpp game.cpp -lraylib -o main -O2 -Werror -Wall -lm
$ ./main
```

### How to build with CMake (VERSION >= 3.20 required):
```console
$ mkdir build && cd build
$ cmake ..
$ make
$ ./game
```
