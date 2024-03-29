#include "Headers/flair.hpp"
#include "Headers/Consts.hpp"
#include "raylib.h"
#include "raymath.h"
#include <cmath>
#include <vector>

static constexpr size_t MAX_FLARES = 300;

// Flare structure
typedef struct Flare
{
  Vector2 position;
  Vector2 velocity;
  float   radius;
  bool    shrinking;
  bool fade;
  float fade_speed;
  Color color;
  Color center_color;
} Flare;

static std::vector<Flare> flares;

void generate_flare(Flare& flare)
{
    flare.radius = GetRandomValue(15, 21);
    flare.fade = false;
    flare.fade_speed = GetRandomValue(1, 3);

    flare.position = {
      float(GetRandomValue(flare.radius, Consts::screen_width - flare.radius)),
      float(GetRandomValue(GetScreenHeight(), Consts::screen_height + 500))
    };

    flare.velocity.x = GetRandomValue(-100, 100);
    flare.velocity.y = -GetRandomValue(100, 500);

    // flip a coin
    if (GetRandomValue(0, 1) % 2 == 0 ? true : false) {
      flare.color = ColorFromHSV(GetRandomValue(30, 40), 1.0, 0.9);
    } else {
      flare.color = ColorFromHSV(GetRandomValue(210, 250), 1.0, 0.9);
    }

    // flare.center_color.r = std::fminf(flare.color.r * 1.25f, 255);
    // flare.center_color.g = std::fminf(flare.color.g * 1.25f, 255);
    // flare.center_color.b = std::fminf(flare.color.b * 1.25f, 255);
    // flare.center_color = RED;

    // flip coin to determine if flare should shrink
    flare.shrinking = GetRandomValue(0, 1) % 2 == 0 ? true : false;
}

void init_flares()
{
    flares.resize(MAX_FLARES);
    for (auto& flare : flares)
        generate_flare(flare);
}

void draw_flares()
{
    for (auto& flare : flares)
    {

        flare.position = Vector2Add(flare.position, Vector2Scale(flare.velocity, GetFrameTime()));

	// don't draw flares and shrink if not on screen
	if (flare.position.y > Consts::screen_height) continue;

	// -------------------------------------------------------------------------------------------
	// handle fading of flares
        if (flare.position.y < Consts::screen_height * 9 / 10.f)
          flare.fade = true;

        if (flare.fade)
          flare.color = Fade(flare.color, 1 - flare.fade_speed / 100);

	flare.fade_speed += 1;
	// -------------------------------------------------------------------------------------------

        DrawCircleV(flare.position, flare.radius, flare.color);
        DrawCircleV(flare.position, flare.radius  / 2, flare.center_color);

	if (flare.shrinking) flare.radius -= 0.05;
        if (flare.position.y < -flare.radius
	    || flare.position.x < flare.radius
	    || flare.position.x > Consts::screen_width - flare.radius)
	  generate_flare(flare);
    }
}
