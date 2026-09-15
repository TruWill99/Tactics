#pragma once

#include <cmath>
#include <ostream>

namespace Tactics::Math {
class Vec2 {
  private:
	float x, y;

  public:
	// Default constructor
	Vec2() : x(0.0f), y(0.0f) {}

	// Parameterised constructor
	Vec2(float x, float y) : x(x), y(y) {}

	// Getters
	float getX() const { return x; }
	float getY() const { return y; }

	// --- Member Operators ---
	Vec2 operator+(const Vec2& other) const { return Vec2(x + other.x, y + other.y); }

	Vec2 operator-(const Vec2& other) const { return Vec2(x - other.x, y - other.y); }

	Vec2 operator*(float scalar) const { return Vec2(x * scalar, y * scalar); }

	Vec2 operator-() const { return Vec2(-x, -y); }

	float dot(const Vec2& other) const { return (x * other.x + y * other.y); }

	float cross(const Vec2& other) const { return (x * other.y - y * other.x); }

	// --- Utility Methods ---
	float length() const { return std::sqrt(x * x + y * y); }

	Vec2 normalise() const {
		float len = length();
		if (len == 0.0f)
			return Vec2(0.0f, 0.0f);
		return Vec2(x / len, y / len);
	}

	// --- Friend Declarations ---
	friend std::ostream& operator<<(std::ostream& os, const Vec2& v);
};

// --- Free Operators ---
inline std::ostream& operator<<(std::ostream& os, const Vec2& v) {
	os << "( " << v.x << ", " << v.y << " )";
	return os;
}

} // namespace Tactics::Math
