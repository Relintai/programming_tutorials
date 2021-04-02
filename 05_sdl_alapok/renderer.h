#ifndef RENDERER_H
#define RENDERER_H

#include "color.h"
#include "rect2.h"
#include "texture.h"
#include "sprite.h"

#include <SDL.h>

class Renderer {
public:
	void present();
	void set_draw_color(const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a);
	void set_draw_color(const Color &color);
	void clear();

	void draw_rect(const SDL_Rect &rect);
	void draw_rect(const Rect2 &rect);

	void draw_texture(const Texture &texture, const Rect2 &dst_rect);
	void draw_texture(const Texture &texture, const Rect2 &src_rect, const Rect2 &dst_rect);
	void draw_texture(const Texture &texture, const Rect2 &src_rect, const Rect2 &dst_rect, const double angle, const float cx = 0, const float cy = 0, const SDL_RendererFlip flip = SDL_FLIP_NONE);

	void draw_sprite(const Sprite &sprite);

	int get_dpi() const;
	int get_size_w() const;
	int get_size_h() const;
	void get_size(int *w, int *h) const;

	void initialize();
	void destroy();

	SDL_Window *get_window();
	SDL_Renderer *get_renderer();

	Renderer();
	Renderer(unsigned int flags, unsigned int window_flags, int window_width = 640, int window_height = 480);
	virtual ~Renderer();

	static Renderer *get_singleton();

private:
	int _initial_window_width;
	int _initial_window_height;

	unsigned int _flags;
	unsigned int _window_flags;

	SDL_Window *_window;
	SDL_Renderer *_renderer;

	int _window_display_index;

	static Renderer *_singleton;
};

#endif