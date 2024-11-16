#pragma once

struct Vector2 {
	int x;
	int y;

	Vector2 static Zero() {
		return Vector2(0, 0);
	}

	Vector2() : x(0), y(0) {}
	Vector2(int x, int y) : x(x), y(y) {}

	Vector2 operator+(const Vector2& other) const {
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 operator-(const Vector2& other) const {
		return Vector2(x - other.x, y - other.y);
	}

	Vector2 operator*(int scalar) const {
		return Vector2(x * scalar, y * scalar);
	}

	Vector2 operator/(int scalar) const {
		return Vector2(x / scalar, y / scalar);
	}

	bool operator==(const Vector2& other) const {
		return x == other.x && y == other.y;
	}

	bool operator!=(const Vector2& other) const {
		return !(*this == other);
	}

	Vector2& operator+=(const Vector2& other) {
		x += other.x;
		y += other.y;
		return *this;
	}

	Vector2& operator-=(const Vector2& other) {
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Vector2& operator*=(int scalar) {
		x *= scalar;
		y *= scalar;
		return *this;
	}

	Vector2& operator/=(int scalar) {
		x /= scalar;
		y /= scalar;
		return *this;
	}

	Vector2 operator-() const {
		return Vector2(-x, -y);
	}

	Vector2 operator+(int scalar) const {
		return Vector2(x + scalar, y + scalar);
	}

	Vector2 operator-(int scalar) const {
		return Vector2(x - scalar, y - scalar);
	}

	Vector2 operator*(const Vector2& other) const {
		return Vector2(x * other.x, y * other.y);
	}

	Vector2 operator/(const Vector2& other) const {
		return Vector2(x / other.x, y / other.y);
	}

	Vector2& operator+=(int scalar) {
		x += scalar;
		y += scalar;
		return *this;
	}

	Vector2& operator-=(int scalar) {
		x -= scalar;
		y -= scalar;
		return *this;
	}

	Vector2& operator*=(const Vector2& other) {
		x *= other.x;
		y *= other.y;
		return *this;
	}

	Vector2& operator/=(const Vector2& other) {
		x /= other.x;
		y /= other.y;
		return *this;
	}
};