#include "rect2.h"

#include "math.h"

float Rect2::get_area() const {
	return w * h;
}

bool Rect2::intersects(const Rect2 &b) const {
	if (x >= (b.x + b.w))
		return false;

	if ((x + w) <= b.x)
		return false;

	if (y >= (b.y + b.h))
		return false;

	if ((y + h) <= b.y)
		return false;

	return true;
}

bool Rect2::intersects_include_borders(const Rect2 &b) const {
	if (x > (b.x + b.w))
		return false;

	if ((x + w) < b.x)
		return false;

	if (y > (b.y + b.h))
		return false;

	if ((y + h) < b.y)
		return false;

	return true;
}

bool Rect2::encloses(const Rect2 &b) const {
	return (b.x >= x) && (b.y >= y) &&
		   ((b.x + b.w) <= (x + w)) &&
		   ((b.y + b.h) <= (y + h));
}

bool Rect2::has_no_area() const {
	if (w == 0 && h == 0) {
		return true;
	}

	return false;
}

bool Rect2::has_point(const float px, const float py) const {
	if (px > x && px < x + w && py > y && py < py + h) {
		return true;
	}

	return false;
}

bool Rect2::is_equal_approx(const Rect2 &b) const {
	if (x + EPSILON < b.x && x - EPSILON > b.x && y + EPSILON < b.y && y - EPSILON > b.y &&
			w + EPSILON < b.w && w - EPSILON > b.w && h + EPSILON < b.h && h - EPSILON > b.h) {
		return true;
	}

	return false;
}

void Rect2::grow(const float by) {
	x -= by;
	y -= by;
	h += by;
	w += by;
}

void Rect2::shrink(const float by) {
	x += by;
	y += by;
	h -= by;
	w -= by;
}

SDL_Rect Rect2::as_rect() const {
	SDL_Rect r;

	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;

	return r;
}

SDL_FRect Rect2::as_frect() const {
	SDL_FRect r;

	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;

	return r;
}

Rect2 &Rect2::operator+=(const Rect2 &b) {
    x += b.x;
	y += b.y;
	w += b.w;
	h += b.h;

    return *this;
}

Rect2 &Rect2::operator-=(const Rect2 &b) {
    x -= b.x;
	y -= b.y;
	w -= b.w;
	h -= b.h;

    return *this;
}

Rect2 operator+(Rect2 lhs, const Rect2 &rhs) {
    lhs.x += rhs.x;
	lhs.y += rhs.y;
	lhs.w += rhs.w;
	lhs.h += rhs.h;

    return lhs;
}

Rect2 operator-(Rect2 lhs, const Rect2 &rhs) {
    lhs.x -= rhs.x;
	lhs.y -= rhs.y;
	lhs.w -= rhs.w;
	lhs.h -= rhs.h;

    return lhs;
}

bool operator==(const Rect2 &a, const Rect2 &b) {
    return a.is_equal_approx(b);
}

bool operator!=(const Rect2 &a, const Rect2 &b) {
    return !a.is_equal_approx(b);
}

Rect2::Rect2() {
	x = 0;
	y = 0;
	w = 0;
	h = 0;
}

Rect2::Rect2(const Rect2 &b) {
	x = b.x;
	y = b.y;
	w = b.w;
	h = b.h;
}

Rect2::Rect2(const float rx, const float ry) {
	x = rx;
	y = ry;
	w = 0;
	h = 0;
}

Rect2::Rect2(const float rx, const float ry, const float rw, const float rh) {
	x = rx;
	y = ry;
	w = rw;
	h = rh;
}
