#ifndef RENDERER_H
#define RENDERER_H

#include "rect2.h"
#include "color.h"

#include <SDL.h>

class Renderer {
public:
    void present();
    void set_draw_color(const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a);
    void set_draw_color(const Color &color);
    void clear();

    void draw_rect(const SDL_Rect &rect);
    void draw_rect(const Rect2 &rect);

	void initialize();
	void destroy();

	Renderer();
	Renderer(unsigned int flags, unsigned int window_flags);
	virtual ~Renderer();

	static Renderer *get_singleton();

private:
	unsigned int _flags;
	unsigned int _window_flags;

	SDL_Window *_window;
	SDL_Renderer *_renderer;

	static Renderer *_singleton;
};

#endif