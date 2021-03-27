#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2 {
public:
    Vector2 abs();
    float angle();
    float angle_to(const Vector2 &b);
    float cross();
    Vector2 clamped(float len);
    Vector2 direction_to(const Vector2 &b);
    float distance_to_squared(const Vector2 &b);
    float distance_to(const Vector2 &b);
    float dot(const Vector2 &b);
    bool is_equal_approx(const Vector2 &b);

    float length();
    float lenght_squared();

    float lerp(const Vector2 &b, const float t);

    Vector2 normalized();
    void normalize();

    void add(const Vector2 &b);
    void sub(const Vector2 &b);

    Vector2();
    Vector2(const Vector2 &b);
    Vector2(const float x, const float y);

    Vector2& operator+=(const Vector2& b);
    Vector2& operator-=(const Vector2& b);

    friend Vector2 operator+(Vector2 lhs, const Vector2 &rhs);
    friend Vector2 operator-(Vector2 lhs, const Vector2 &rhs);

    friend bool operator==(const Vector2& a, const Vector2& b);
    friend bool operator!=(const Vector2& a, const Vector2& b);

    float x;
    float y;
};

#endif
