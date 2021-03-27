#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2 {
public:
	Vector2 abs() const;
	float angle() const;
	float angle_to(const Vector2 &b) const;
	float cross(const Vector2 &b) const;
	Vector2 clamped(float len) const;
	Vector2 direction_to(const Vector2 &b) const;
	float distance_to_squared(const Vector2 &b) const;
	float distance_to(const Vector2 &b) const;
	float dot(const Vector2 &b) const;
	bool is_equal_approx(const Vector2 &b) const;

	float length() const;
	float length_squared() const;

	Vector2 lerp(const Vector2 &b, const float t) const;

	Vector2 normalized() const;
	void normalize();

	void add(const Vector2 &b);
	void sub(const Vector2 &b);

	Vector2();
	Vector2(const Vector2 &b);
	Vector2(const float p_x, const float p_y);

	Vector2 &operator+=(const Vector2 &b);
	Vector2 &operator-=(const Vector2 &b);

	friend Vector2 operator+(Vector2 lhs, const Vector2 &rhs);
	friend Vector2 operator-(Vector2 lhs, const Vector2 &rhs);

	Vector2 &operator*=(const float b);
	friend Vector2 operator*(Vector2 lhs, const float rhs);

	friend bool operator==(const Vector2 &a, const Vector2 &b);
	friend bool operator!=(const Vector2 &a, const Vector2 &b);

	float x;
	float y;
};

#endif
