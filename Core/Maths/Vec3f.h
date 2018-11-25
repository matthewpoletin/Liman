/**
 * @file Vec3f.h
 * @author matthewpoletin
 */

#pragma once

#include <iostream>

namespace liman {
	namespace maths {

		struct Vec3f {
			float x, y, z;

			Vec3f();

			Vec3f(const float &x, const float &y, const float &z);

			Vec3f &add(const Vec3f &other);

			Vec3f &subtract(const Vec3f &other);

			Vec3f &multiply(const Vec3f &other);

			Vec3f &divide(const Vec3f &other);

			friend Vec3f operator+(Vec3f left, const Vec3f &right);

			friend Vec3f operator-(Vec3f left, const Vec3f &right);

			friend Vec3f operator*(Vec3f left, const Vec3f &right);

			friend Vec3f operator/(Vec3f left, const Vec3f &right);

			bool operator==(const Vec3f &other);

			bool operator!=(const Vec3f &other);

			Vec3f &operator+=(const Vec3f &other);

			Vec3f &operator-=(const Vec3f &other);

			Vec3f &operator*=(const Vec3f &other);

			Vec3f &operator/=(const Vec3f &other);

			friend std::ostream &operator<<(std::ostream &stream, const Vec3f &vector);
		};

	}
}