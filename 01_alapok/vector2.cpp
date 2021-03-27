#include "vector2.h"

#include <cmath>

#define EPSILON 0.00001

Vector2 Vector2::abs() const {
	Vector2 b;

	b.x = x >= 0 ? x : -x;
	b.y = y >= 0 ? y : -y;

	return b;
}

float Vector2::angle() const {
	return atan2(x, y);
}

float Vector2::angle_to(const Vector2 &b) const {
	return atan2(cross(b), dot(b));
}

float Vector2::cross(const Vector2 &b) const {
	return x * b.y - y * b.x;
}

Vector2 Vector2::clamped(float len) const {
	return normalized() * len;
}

Vector2 Vector2::direction_to(const Vector2 &b) const {
	return (b - *this).normalized();
}

float Vector2::distance_to_squared(const Vector2 &b) const {
	return (x - b.x) * (x - b.x) + (y - b.y) * (y - b.y);
}

float Vector2::distance_to(const Vector2 &b) const {
	return sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
}

float Vector2::dot(const Vector2 &b) const {
	return x * b.x + y * b.y;
}

bool Vector2::is_equal_approx(const Vector2 &b) const {
	if (x + EPSILON < b.x && x - EPSILON > b.x && y + EPSILON < b.y && y - EPSILON > b.y) {
		return true;
	}

	return false;
}

float Vector2::length() const {
	return sqrt(x * x + y * y);
}

float Vector2::length_squared() const {
	return x * x + y * y;
}

Vector2 Vector2::lerp(const Vector2 &b, const float t) const {
	Vector2 v;

	v.x = x + (t * (b.x - x));
	v.y = y + (t * (b.y - y));

	return v;
}

Vector2 Vector2::normalized() const {
	Vector2 v;

	float l = length_squared();

	if (l != 0) {
		l = sqrt(l);

		v.x = x / l;
		v.y = y / l;
	}

	return v;
}

void Vector2::normalize() {
	float l = length_squared();

	if (l != 0) {
		l = sqrt(l);

		x = x / l;
		y = y / l;
	}
}

void Vector2::add(const Vector2 &b) {
	x += b.x;
	y += b.y;
}

void Vector2::sub(const Vector2 &b) {
	x -= b.x;
	y -= b.y;
}

Vector2::Vector2() {
	x = 0;
	y = 0;
}

Vector2::Vector2(const Vector2 &b) {
	x = b.x;
	y = b.y;
}

Vector2::Vector2(const float p_x, const float p_y) {
	x = p_x;
	y = p_y;
}

Vector2 &Vector2::operator+=(const Vector2 &b) {
	x += b.x;
	y += b.y;

	return *this;
}

Vector2 &Vector2::operator-=(const Vector2 &b) {
	x -= b.x;
	y -= b.y;

	return *this;
}

Vector2 &Vector2::operator*=(const float b) {
	x *= b;
	y *= b;

	return *this;
}

Vector2 operator*(Vector2 lhs, const float rhs) {
	lhs.x *= rhs;
	lhs.y *= rhs;

	return lhs;
}

Vector2 operator+(Vector2 lhs, const Vector2 &rhs) {
	lhs.x += rhs.x;
	lhs.y += rhs.y;

	return lhs;
}

Vector2 operator-(Vector2 lhs, const Vector2 &rhs) {
	lhs.x -= rhs.x;
	lhs.y -= rhs.y;

	return lhs;
}

bool operator==(const Vector2 &a, const Vector2 &b) {
	return a.is_equal_approx(b);
}

bool operator!=(const Vector2 &a, const Vector2 &b) {
	return !(a == b);
}
