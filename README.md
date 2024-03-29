# You only Live TWICE

<p align=center>
    <img src="./res/Assets/title_screen.png">
</p>

## Requirements:
The Raylib library has
to be installed and added to the system $PATH.

### Recommendation: use a package manager
For Debian/Ubuntu
```console
$ sudo apt install git build-essential cmake libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev
$ git clone https://github.com/raysan5/raylib.git
$ cd raylib
$ cmake -S . -B build
$ sudo cmake --build build --config Release --target install
```
For ArchLinux:
```console
$ sudo pacman -Syu
$ sudo pacman -S raylib
```
For other operating system see the raylib <a href="https://raylib.com/" target="_blank"> website </a>

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
---
## LICENSE
GNU General Public License
