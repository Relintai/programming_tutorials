#include "vector2.h"

#include <cmath>

/*
| + abs() : Vector2                             |  -> visszaadja egy új vektorba ennek a vektornak az abszolút értékét. (x, y abszolút értékét veszi)
| + angle() float                               |  -> atan2(x, y)
| + angle_to(b : Vector2) : float               |  -> atan2(cross(b), dot(b));
| + cross(b : Vector2) : float                  |  -> Cross product -> x * b.y - y * b.x;
| + clamped(len : float) : Vector2              |  -> normalized() * len
| + direction_to(b : Vector2) : Vector2         |  -> Visszaad egy normalizált vektort ami ebből b be mutat. (A képlet: (b - a).normalized()) (operator-)
| + distance_to_squared(b : Vector2) : float    |  -> (x - b.x) * (x - b.x) + (y - b.y) * (y - b.y);
| + distance_to(b : Vector2) : float            |  -> sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
| + dot(b : Vector2) : float                    |  -> dot product -> Ha a 2 vektor 90 fokosz szöget zár be, akkor 0.
|                                               |         Pozitív, ha a 2 vektor által bezárt szög kisebb mint 90 fok, negatív, ha nagyobb.
|                                               |         képlet: x * b.x + y * b.
| + is_equal_approx(b : Vector2) : bool         |  -> nagyjából egyenlőek-e a vektorok. A max különbség legyen 0.00001 (Epszilon).
| + length() : float                            |
| + lenght_squared() : float                    |  -> A hossz a gyökvonás nélkül. (A gyökvonás relatíve lassú, és ha csak össze kell 
|                                               |                         hasonlítani hosszakat, akkor elég így)
| + lerp(b : Vector2, t : float) : Vector2      |  -> Linear interpolate -> a jelenlegi vektor és b közötti átmenetvektort adja vissza t paraméter felhasználásával.
|                                               |     A t 0 és 1 közötti. Képlet: newx = x + (t * (b.x - x)); és newy = y + (t * (b.y - y));
| + normalized() : Vector2                      |  -> A vektor normalizálva. Normalizált vektor = a hossza 1. 
|                                               |     float l = lenght_squared(); ha nem 0, gyököt kell vonni belőle, és le kell osztani x, y-t is vele
| + normalize()                                 |  -> Maga a vektor normalizálódik.
| + add(b: Vector2)                             |  -> x += b.x, y += b.y
| + sub(b: Vector2)                             |  -> x -= b.x, y -= b.y
| + operator+=(b: Vector2)                      |     etc
| + operator-=(b: Vector2)                      |
| + operator+(a: Vector2, b: Vector2) : Vector2 |
| + operator-(a: Vector2, b: Vector2) : Vector2 |
| + operator==(b: Vector2) : bool               |
| + operator!=(b: Vector2) : bool               |
| + Vector2()                                   |
| + Vector2(b : Vector2)                        |
| + Vector2(x : float, y : float)               |
*/

Vector2 Vector2::abs() {
    Vector2 b;

    b.x = abs(x);
    b.y = abs(y);

    return b;
}

float Vector2::angle() {
}

float Vector2::angle_to(const Vector2 &b) {
}

float Vector2::cross() {
}

Vector2 Vector2::clamped(float len) {
}

Vector2 Vector2::direction_to(const Vector2 &b) {
}

float Vector2::distance_to_squared(const Vector2 &b) {
}

float Vector2::distance_to(const Vector2 &b) {
}

float Vector2::dot(const Vector2 &b) {
}

bool Vector2::is_equal_approx(const Vector2 &b) {
}

float Vector2::length() {
}

float Vector2::lenght_squared() {
}

float Vector2::lerp(const Vector2 &b, const float t) {
}

Vector2 Vector2::normalized() {
}

void Vector2::normalize() {
}

void Vector2::add(const Vector2 &b) {
}

void Vector2::sub(const Vector2 &b) {
}

Vector2::Vector2() {
}

Vector2::Vector2(const Vector2 &b) {
}

Vector2::Vector2(const float x, const float y) {
}

Vector2 &Vector2::operator+=(const Vector2 &b) {
}

Vector2 &Vector2::operator-=(const Vector2 &b) {
}

Vector2 operator+(Vector2 lhs, const Vector2 &rhs) {
}

Vector2 operator-(Vector2 lhs, const Vector2 &rhs) {
}

bool operator==(const Vector2 &a, const Vector2 &b) {
}

bool operator!=(const Vector2 &a, const Vector2 &b) {
}
