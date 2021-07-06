#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>

#include "core/rect2.h"
#include "texture.h"
#include "core/color.h"

class Sprite {
public:
	Rect2 get_texture_clip_rect() const;
	void set_texture_clip_rect(const Rect2 &rect);

	Rect2 get_transform() const;
	void set_transform(const Rect2 &rect);

	float get_x() const;
	void set_x(const float val);

	float get_y() const;
	void set_y(const float val);

	float get_w() const;
	void set_w(const float val);

	float get_h() const;
	void set_h(const float val);

	double get_angle() const;
	void set_angle(const double val);

	float get_anchor_x() const;
	void set_anchor_x(const float val);

	float get_anchor_y() const;
	void set_anchor_y(const float val);

	void set_anchor(const float x, const float y);

	SDL_RendererFlip get_flip() const;
	void set_flip(const SDL_RendererFlip val);

	Color get_color_mod() const;
	void set_color_mod(const Color &color);

	Texture *get_texture();
	Texture *get_texture() const;
	void set_texture(Texture *texture);

	void draw();

	Sprite();
	Sprite(Texture *texture);
	Sprite(Texture *texture, const Color &color_mod);
	Sprite(Texture *texture, const float x, const float y, const double angle = 0);
	Sprite(Texture *texture, const float x, const float y, const Rect2 &texture_clip_rect, const double angle = 0);
	Sprite(Texture *texture, const Rect2 &transform, const Rect2 &texture_clip_rect, const double angle = 0);
	Sprite(Texture *texture, const float x, const float y, const float w, const float h, const double angle = 0);
	virtual ~Sprite();

private:
	Rect2 _texture_clip_rect;
	Rect2 _transform;
	double _angle;

	float _anchor_x;
	float _anchor_y;

	SDL_RendererFlip _flip;

	Color _color_mod;

	Texture *_texture;
};

#endif