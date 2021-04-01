#ifndef IMAGE_H
#define IMAGE_H

#include "color.h"
#include "rect2.h"
#include "string.h"
#include "vector.h"
#include <SDL.h>

class Image {
public:
	void create(const Uint32 flags, const int width, const int height);

	void enable_transparent_color(const Color &color);
	void disable_transparent_color();
	bool has_transparent_color();
	Color get_transparent_color();

	Color get_color_mod();
	void set_color_mod(const Color &color);

	Color get_alpha_mod();
	void set_alpha_mod(const Uint8 alpha);

	SDL_BlendMode get_blend_mode();
	void set_blend_mode(const SDL_BlendMode mode);

	Rect2 get_clip_rect();
	void set_clip_rect(const Rect2 &rect);

	void duplicate(Image *into);

	void fill_rect(const Rect2 &rect, const Color &color);
	void fill_rects(const Vector<Rect2> &rects, const Color &color);
	void set_pixel(const int x, const int y, const Color &color);
	Color get_pixel(const int x, const int y);

	void blit_surface(const Image &source, const Rect2 &srcrect, const Rect2 &dstrect);

	void lock();
	void unlock();

	void free();

	void load_bmp(const String &file_name);
	void save_bmp(const String &file_name);

	Uint32 get_width() const;
	Uint32 get_height() const;

	SDL_Surface *get_surface();

	Image();
	Image(const String &file_name);
	virtual ~Image();

private:
	SDL_Surface *_surface;
};

#endif