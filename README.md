# You only Live TWICE

<p align=center>
    <img src="./res/Assets/title_screen.png">
</p>
---
## Requirements:
The <a href="https://raylib.com/" target="_blank">Raylib</a> library has
to be installed and added to the system $PATH.

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
