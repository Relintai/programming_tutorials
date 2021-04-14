#include "image.h"

#include <stdio.h>

void Image::create(const Uint32 flags, const int width, const int height) {
	if (_surface) {
		free();
	}

	//SDL_PIXELFORMAT_RGBA8888 SDL_pixels.h ból
	SDL_CreateRGBSurfaceWithFormat(flags, width, height, 32, SDL_PIXELFORMAT_RGBA8888);
}

void Image::enable_transparent_color(const Color &color) {
	if (!SDL_SetColorKey(_surface, 1, color.to_key())) {
		printf("enable_transparent_color error.\n");
	}
}

void Image::disable_transparent_color() {
	if (!SDL_SetColorKey(_surface, 0, 0)) {
		printf("disable_transparent_color error.\n");
	}
}

bool Image::has_transparent_color() {
	return SDL_HasColorKey(_surface);
}
Color Image::get_transparent_color() {
	uint32_t key;

	SDL_GetColorKey(_surface, &key);

	return Color(key);
}

Color Image::get_color_mod() {
	Uint8 r;
	Uint8 g;
	Uint8 b;

	SDL_GetSurfaceColorMod(_surface, &r, &g, &b);

	return Color(r, g, b);
}
void Image::set_color_mod(const Color &color) {
	SDL_SetSurfaceColorMod(_surface, color.r, color.g, color.b);
}

Color Image::get_alpha_mod() {
	Uint8 a;

	SDL_GetSurfaceAlphaMod(_surface, &a);

	return a;
}
void Image::set_alpha_mod(const Uint8 alpha) {
	SDL_SetSurfaceAlphaMod(_surface, alpha);
}

SDL_BlendMode Image::get_blend_mode() {
	SDL_BlendMode mode;

	SDL_GetSurfaceBlendMode(_surface, &mode);

	return mode;
}
void Image::set_blend_mode(const SDL_BlendMode mode) {
	SDL_SetSurfaceBlendMode(_surface, mode);
}

Rect2 Image::get_clip_rect() {
	SDL_Rect r;

	SDL_GetClipRect(_surface, &r);

	Rect2 rect;

	rect.x = r.x;
	rect.y = r.y;
	rect.w = r.w;
	rect.h = r.h;

	return rect;
}
void Image::set_clip_rect(const Rect2 &rect) {
	SDL_Rect r;

	r.x = rect.x;
	r.y = rect.y;
	r.w = rect.w;
	r.h = rect.h;

	SDL_SetClipRect(_surface, &r);
}

void Image::duplicate(Image *into) {
	if (into == nullptr) {
		return;
	}

	into->_surface = SDL_DuplicateSurface(_surface);
}

void Image::fill_rect(const Rect2 &rect, const Color &color) {
	SDL_Rect r;

	r.x = rect.x;
	r.y = rect.y;
	r.w = rect.w;
	r.h = rect.h;

	SDL_FillRect(_surface, &r, color.to_key());
}

void Image::fill_rects(const Vector<Rect2> &rects, const Color &color) {
	SDL_Rect *r = new SDL_Rect[rects.size()];

	for (int i = 0; i < rects.size(); ++i) {
		r[i].x = rects[i].x;
		r[i].y = rects[i].y;
		r[i].w = rects[i].w;
		r[i].h = rects[i].h;
	}

	SDL_FillRects(_surface, r, rects.size(), color.to_key());

	delete[] r;
}

void Image::set_pixel(const int x, const int y, const Color &color) {
	if (_surface == nullptr) {
		return;
	}

	Uint32 *p = reinterpret_cast<Uint32 *>(_surface->pixels);

	p[x * _surface->w + y] = color.to_key();
}

Color Image::get_pixel(const int x, const int y) {
	if (_surface == nullptr) {
		return Color();
	}

	Uint32 *p = reinterpret_cast<Uint32 *>(_surface->pixels);

	return Color(p[x * _surface->w + y]);
}

void Image::blit_surface(const Image &source, const Rect2 &srcrect, const Rect2 &dstrect) {
	SDL_Rect sr;

	sr.x = srcrect.x;
	sr.y = srcrect.y;
	sr.w = srcrect.w;
	sr.h = srcrect.h;

	SDL_Rect dr;

	dr.x = dstrect.x;
	dr.y = dstrect.y;
	dr.w = dstrect.w;
	dr.h = dstrect.h;

	SDL_BlitSurface(source._surface, &sr, _surface, &dr);
}

void Image::lock() {
	SDL_LockSurface(_surface);
}
void Image::unlock() {
	SDL_UnlockSurface(_surface);
}

void Image::free() {
	SDL_FreeSurface(_surface);

	_surface = nullptr;
}

void Image::load_bmp(const String &file_name) {
	if (_surface != nullptr) {
		free();
	}

	_surface = SDL_LoadBMP(file_name.c_str());

	if (_surface != nullptr && _surface->format->format != SDL_PIXELFORMAT_RGBA8888) {
		//Nem ARGB8888 as formátum, konvertáljuk át
		SDL_Surface *n = SDL_ConvertSurfaceFormat(_surface, SDL_PIXELFORMAT_RGBA8888, 0);

		free();

		_surface = n;
	}
}

void Image::save_bmp(const String &file_name) {
	SDL_SaveBMP(_surface, file_name.c_str());
}

Uint32 Image::get_width() const {
	if (_surface == nullptr) {
		return 0;
	}

	return _surface->w;
}
Uint32 Image::get_height() const {
	if (_surface == nullptr) {
		return 0;
	}

	return _surface->h;
}

SDL_Surface *Image::get_surface() {
	return _surface;
}

void Image::set_surface(SDL_Surface *surface) {
	_surface = surface;

	if (_surface != nullptr && _surface->format->format != SDL_PIXELFORMAT_RGBA8888) {
		//Nem ARGB8888 as formátum, konvertáljuk át
		SDL_Surface *n = SDL_ConvertSurfaceFormat(_surface, SDL_PIXELFORMAT_RGBA8888, 0);

		free();

		_surface = n;
	}
}

Image::Image() {
	_surface = nullptr;
}

Image::Image(const String &file_name) {
	_surface = nullptr;

	load_bmp(file_name);
}

Image::Image(SDL_Surface *surface) {
	_surface = surface;

	if (_surface != nullptr && _surface->format->format != SDL_PIXELFORMAT_RGBA8888) {
		//Nem ARGB8888 as formátum, konvertáljuk át
		SDL_Surface *n = SDL_ConvertSurfaceFormat(_surface, SDL_PIXELFORMAT_RGBA8888, 0);

		free();

		_surface = n;
	}
}

Image::~Image() {
	free();
}