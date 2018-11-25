#include "Vec2f.h"

namespace liman {
	namespace maths {

		Vec2f::Vec2f() {
			x = 0.0f;
			y = 0.0f;
		}

		Vec2f::Vec2f(const float &x, const float &y) {
			this->x = x;
			this->y = y;
		}

		Vec2f::Vec2f(const Vec3f &vector) {
			this->x = vector.x;
			this->y = vector.y;
		}

		Vec2f &Vec2f::add(const Vec2f &other) {
			x += other.x;
			y += other.y;

			return *this;
		}

		Vec2f &Vec2f::subtract(const Vec2f &other) {
			x -= other.x;
			y -= other.y;

			return *this;
		}

		Vec2f &Vec2f::multiply(const Vec2f &other) {
			x *= other.x;
			y *= other.y;

			return *this;
		}

		Vec2f &Vec2f::divide(const Vec2f &other) {
			x /= other.x;
			y /= other.y;

			return *this;
		}

		Vec2f operator+(Vec2f left, const Vec2f &right) {
			return left.add(right);
		}

		Vec2f operator-(Vec2f left, const Vec2f &right) {
			return left.subtract(right);
		}

		Vec2f operator*(Vec2f left, const Vec2f &right) {
			return left.multiply(right);
		}

		Vec2f operator/(Vec2f left, const Vec2f &right) {
			return left.divide(right);
		}

		Vec2f operator+(Vec2f left, float value) {
			return Vec2f(left.x + value, left.y + value);
		}

		Vec2f operator*(Vec2f left, float value) {
			return Vec2f(left.x * value, left.y * value);
		}

		Vec2f &Vec2f::operator+=(const Vec2f &other) {
			return add(other);
		}

		Vec2f &Vec2f::operator-=(const Vec2f &other) {
			return subtract(other);
		}

		Vec2f &Vec2f::operator*=(const Vec2f &other) {
			return multiply(other);
		}

		Vec2f &Vec2f::operator/=(const Vec2f &other) {
			return divide(other);
		}

		bool Vec2f::operator==(const Vec2f &other) {
			return x == other.x && y == other.y;
		}

		bool Vec2f::operator!=(const Vec2f &other) {
			return !(*this == other);
		}

		float Vec2f::distance(const Vec2f &other) const {
			float a = x - other.x;
			float b = y - other.y;
			return sqrt(a * a + b * b);
		}

		float Vec2f::dot(const Vec2f &other) const {
			return x * other.x + y * other.y;
		}

		float Vec2f::magnitude() const {
			return sqrt(x * x + y * y);
		}

		Vec2f Vec2f::normalise() const {
			float length = magnitude();
			return Vec2f(x / length, y / length);
		}

		std::ostream &operator<<(std::ostream &stream, const Vec2f &vector) {
			stream << "Vec2f: (" << vector.x << ", " << vector.y << ")";
			return stream;
		}

	}
}