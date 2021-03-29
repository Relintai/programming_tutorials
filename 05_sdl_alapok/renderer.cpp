#include "renderer.h"

#include <cstdio>

void Renderer::present() {
	SDL_RenderPresent(_renderer);
}

void Renderer::set_draw_color(const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a) {
	SDL_SetRenderDrawColor(_renderer, r, g, b, a);
}

void Renderer::set_draw_color(const Color &color) {
    SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, color.a);
}

void Renderer::clear() {
	SDL_RenderClear(_renderer);
}

void Renderer::draw_rect(const SDL_Rect &rect) {
    SDL_RenderFillRect(_renderer, &rect);
}
void Renderer::draw_rect(const Rect2 &rect) {
    SDL_Rect r;
	r.x = rect.x;
	r.y = rect.y;
	r.w = rect.w;
	r.h = rect.h;

    SDL_RenderFillRect(_renderer, &r);
}

void Renderer::initialize() {
	if (SDL_Init(_flags) != 0) {
		printf("SDL_Init() hiba!\n");

		return;
	}

	if (SDL_CreateWindowAndRenderer(640, 480, _window_flags, &_window, &_renderer) != 0) {
		printf("SDL_CreateWindowAndRenderer() hiba!\n");

		return;
	}
}

void Renderer::destroy() {
    if (_window)
	    SDL_DestroyWindow(_window);

    if (_renderer)
	    SDL_DestroyRenderer(_renderer);

    _window = nullptr;
    _renderer = nullptr;
}

Renderer::Renderer() {
	if (_singleton) {
		printf("Renderer::Renderer(): _singleton is not null!\n");
	}

	_singleton = this;

	_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER;
	_window_flags = SDL_WINDOW_SHOWN;

	initialize();
}

Renderer::Renderer(unsigned int flags, unsigned int window_flags) {
	if (_singleton) {
		printf("Renderer::Renderer(flags): _singleton is not null!\n");
	}

	_singleton = this;

	_flags = flags;
	_window_flags = window_flags;

	initialize();
}

Renderer::~Renderer() {
	if (_singleton != this) {
		printf("Renderer::~Renderer(): _singleton is not this!\n");
	}

	_singleton = nullptr;

	destroy();
}

Renderer *Renderer::get_singleton() {
	return _singleton;
}

Renderer *Renderer::_singleton = nullptr;