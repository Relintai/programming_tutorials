#include "sprite.h"

#include "renderer.h"

Rect2 Sprite::get_texture_clip_rect() const {
	return _texture_clip_rect;
}
void Sprite::set_texture_clip_rect(const Rect2 &rect) {
	_texture_clip_rect = rect;
}

Rect2 Sprite::get_transform() const {
	return _transform;
}
void Sprite::set_transform(const Rect2 &rect) {
	_transform = rect;
}

float Sprite::get_x() const {
	return _transform.x;
}
void Sprite::set_x(const float val) {
	_transform.x = val;
}

float Sprite::get_y() const {
	return _transform.y;
}
void Sprite::set_y(const float val) {
	_transform.y = val;
}

float Sprite::get_w() const {
	return _transform.w;
}
void Sprite::set_w(const float val) {
	_transform.w = val;
}

float Sprite::get_h() const {
	return _transform.h;
}
void Sprite::set_h(const float val) {
	_transform.h = val;
}

double Sprite::get_angle() const {
	return _angle;
}
void Sprite::set_angle(const double val) {
	_angle = val;
}

float Sprite::get_anchor_x() const {
	return _anchor_x;
}
void Sprite::set_anchor_x(const float val) {
	_anchor_x = val;
}

float Sprite::get_anchor_y() const {
	return _anchor_y;
}
void Sprite::set_anchor_y(const float val) {
	_anchor_y = val;
}

void Sprite::set_anchor(const float x, const float y) {
	_anchor_x = x;
	_anchor_y = y;
}

SDL_RendererFlip Sprite::get_flip() const {
	return _flip;
}
void Sprite::set_flip(const SDL_RendererFlip val) {
	_flip = val;
}

Color Sprite::get_color_mod() const {
	return _color_mod;
}
void Sprite::set_color_mod(const Color &color) {
	_color_mod = color;
}

Texture *Sprite::get_texture() {
	return _texture;
}
Texture *Sprite::get_texture() const {
	return _texture;
}
void Sprite::set_texture(Texture *texture) {
	_texture = texture;
}

void Sprite::draw() {
	Renderer::get_singleton()->draw_sprite(this);
}

Sprite::Sprite() {
	_angle = 0;

	_anchor_x = 0;
	_anchor_y = 0;

	_flip = SDL_FLIP_NONE;

	_texture = nullptr;

	_color_mod = Color(255, 255, 255, 255);
}
Sprite::Sprite(Texture *texture) {
	_angle = 0;

	_anchor_x = 0;
	_anchor_y = 0;

	_flip = SDL_FLIP_NONE;

	_texture = texture;

	if (_texture != nullptr) {
		_texture_clip_rect.w = texture->get_width();
		_texture_clip_rect.h = texture->get_height();

		_transform.w = texture->get_width();
		_transform.h = texture->get_height();
	}

	_color_mod = Color(255, 255, 255, 255);
}

Sprite::Sprite(Texture *texture, const Color &color_mod) {
		_angle = 0;

	_anchor_x = 0;
	_anchor_y = 0;

	_flip = SDL_FLIP_NONE;

	_texture = texture;

	if (_texture != nullptr) {
		_texture_clip_rect.w = texture->get_width();
		_texture_clip_rect.h = texture->get_height();

		_transform.w = texture->get_width();
		_transform.h = texture->get_height();
	}

	_color_mod = color_mod;
}

Sprite::Sprite(Texture *texture, const float x, const float y, const double angle) {
	_angle = angle;

	_anchor_x = 0;
	_anchor_y = 0;

	_flip = SDL_FLIP_NONE;

	_texture = texture;

	_transform.x = x;
	_transform.y = y;

	if (_texture != nullptr) {
		_texture_clip_rect.w = texture->get_width();
		_texture_clip_rect.h = texture->get_height();

		_transform.w = texture->get_width();
		_transform.h = texture->get_height();
	}

	_color_mod = Color(255, 255, 255, 255);
}
Sprite::Sprite(Texture *texture, const float x, const float y, const Rect2 &texture_clip_rect, const double angle) {
	_angle = angle;

	_anchor_x = 0;
	_anchor_y = 0;

	_flip = SDL_FLIP_NONE;

	_texture = texture;

	_transform.x = x;
	_transform.y = y;

	if (_texture != nullptr) {
		_transform.w = texture->get_width();
		_transform.h = texture->get_height();
	}

	_texture_clip_rect = texture_clip_rect;

	_color_mod = Color(255, 255, 255, 255);
}
Sprite::Sprite(Texture *texture, const Rect2 &transform, const Rect2 &texture_clip_rect, const double angle) {
	_angle = angle;

	_anchor_x = 0;
	_anchor_y = 0;

	_flip = SDL_FLIP_NONE;

	_texture = texture;

	_transform = transform;
	_texture_clip_rect = texture_clip_rect;

	_color_mod = Color(255, 255, 255, 255);
}
Sprite::Sprite(Texture *texture, const float x, const float y, const float w, const float h, const double angle) {
	_angle = angle;

	_anchor_x = 0;
	_anchor_y = 0;

	_flip = SDL_FLIP_NONE;

	_texture = texture;

	_transform.x = x;
	_transform.y = y;
	_transform.w = w;
	_transform.h = h;

	if (_texture != nullptr) {
		_texture_clip_rect.w = texture->get_width();
		_texture_clip_rect.h = texture->get_height();
	}

	_color_mod = Color(255, 255, 255, 255);
}
Sprite::~Sprite() {
}