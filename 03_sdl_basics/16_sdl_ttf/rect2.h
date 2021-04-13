#ifndef RECT2_H
#define RECT2_H

#include <SDL.h>

class Rect2 {
public:
	float get_area() const;
	bool intersects(const Rect2 &b) const;
	bool intersects_include_borders(const Rect2 &b) const;
	bool encloses(const Rect2 &b) const;
	bool has_no_area() const;
	bool has_point(const float px, const float py) const;
	bool is_equal_approx(const Rect2 &b) const;

	void grow(const float by);
	void shrink(const float by);

	SDL_Rect as_rect() const;
	SDL_FRect as_frect() const;

	Rect2 &operator+=(const Rect2 &b);
	Rect2 &operator-=(const Rect2 &b);

	friend Rect2 operator+(Rect2 lhs, const Rect2 &rhs);
	friend Rect2 operator-(Rect2 lhs, const Rect2 &rhs);

	friend bool operator==(const Rect2 &a, const Rect2 &b);
	friend bool operator!=(const Rect2 &a, const Rect2 &b);

	Rect2();
	Rect2(const Rect2 &b);
	Rect2(const float rx, const float ry);
	Rect2(const float rx, const float ry, const float rw, const float rh);

	float x;
	float y;
	float w;
	float h;
};

#endif