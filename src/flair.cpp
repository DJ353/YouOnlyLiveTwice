#include "Headers/flair.hpp"
#include "Headers/Consts.hpp"
#include "raylib.h"
#include <vector>
#include <random>

#define MAX_FLAIRES 100

typedef struct Flair {
  Vector2 position;
  Vector2 velocity;
  float radius;
  Color color;
  bool bubbling; // indicates if flair is growing
  bool active;
} Flair;

static std::vector<Flair> right_flairs;
static std::vector<Flair> left_flairs;

static std::mt19937 mersenne_twister {std::random_device{}()}; // mersenne_twister_engine seeded with random_device()
static std::uniform_int_distribution<int> left_flair_distrib{Consts::screen_width - 200, Consts::screen_width};
static std::uniform_int_distribution<int> right_flair_distrib{0, 200};

void init_flaires() {
  for (int i = 0; i < MAX_FLAIRES; ++i) {

    Flair left_flair;

    left_flair.active = true;
    left_flair.bubbling = true;
    left_flair.color = RED;
    left_flair.position = {
      static_cast<float>(left_flair_distrib(mersenne_twister)),
      10
    };
    left_flair.radius = 5;
    left_flair.velocity = {};

    left_flairs.emplace_back(left_flair);

    Flair right_flair;
    right_flair.active = true;
    right_flair.bubbling = true;
    right_flair.color = BLUE;
    right_flair.position = {};
    right_flair.radius = 5;
    right_flair.velocity = {};

    right_flairs.emplace_back(right_flair);
  }
}

void draw_flaires() {
  for (int i = 0; i < MAX_FLAIRES; ++i) {

    if (right_flairs[i].active)
      DrawCircleV(right_flairs[i].position, right_flairs[i].radius, right_flairs[i].color);

    if (left_flairs[i].active)
      DrawCircleV(left_flairs[i].position, right_flairs[i].radius, right_flairs[i].color);

    // update flaires
  }
}
