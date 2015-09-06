#pragma once

const float MATHS_PI = 3.14159265358979f;
const float MATHS_2PI = 2 * MATHS_PI;

#define RADIANS_TO_DEGREES(x) ((x) * 180.0f / MATHS_PI)
#define DEGREES_TO_RADIANS(x) ((x) * MATHS_PI / 180.0f)

#include "Vec2f.h"
#include "Vec3f.h"