/**
 * @file Vec2f.h
 * @author matthewpoletin
 */

#pragma once

#include <iostream>
#include <math.h>

#include "Vec3f.h"

namespace liman {
	namespace maths {

		struct Vec2f {
			float x, y;

			Vec2f();

			Vec2f(const float &x, const float &y);

			Vec2f(const Vec3f &vector);

			Vec2f &add(const Vec2f &other);

			Vec2f &subtract(const Vec2f &other);

			Vec2f &multiply(const Vec2f &other);

			Vec2f &divide(const Vec2f &other);

			friend Vec2f operator+(Vec2f left, const Vec2f &right);

			friend Vec2f operator-(Vec2f left, const Vec2f &right);

			friend Vec2f operator*(Vec2f left, const Vec2f &right);

			friend Vec2f operator/(Vec2f left, const Vec2f &right);

			friend Vec2f operator+(Vec2f left, float value);

			friend Vec2f operator*(Vec2f left, float value);

			bool operator==(const Vec2f &other);

			bool operator!=(const Vec2f &other);

			Vec2f &operator+=(const Vec2f &other);

			Vec2f &operator-=(const Vec2f &other);

			Vec2f &operator*=(const Vec2f &other);

			Vec2f &operator/=(const Vec2f &other);

			float magnitude() const;

			Vec2f normalise() const;

			float distance(const Vec2f &other) const;

			float dot(const Vec2f &other) const;

			friend std::ostream &operator<<(std::ostream &stream, const Vec2f &vector);
		};

	}
}