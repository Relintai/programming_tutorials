#include <SDL.h>

#include "image.h"
#include "renderer.h"
#include "sprite.h"

#include <SDL.h>

void main_loop_1() {
	bool quit = false;
	SDL_Event e;

	while (!quit) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}

			if (e.type == SDL_KEYDOWN) {
				printf("keydown\n");
			}

			if (e.type == SDL_KEYUP) {
				printf("keyup\n");
			}
		}
	}
}

int main(int argv, char **args) {
	Renderer r;

	Image i("ti.bmp");

	r.set_draw_color(0, 0, 0, 255);
	r.clear();

	Texture t(&i);
	Sprite s(&t);

	s.set_x(30);
	s.set_y(30);

	r.draw_sprite(s);
	r.present();

	main_loop_1();

	t.free();
	i.free();
	r.destroy();

	SDL_Quit();
}
