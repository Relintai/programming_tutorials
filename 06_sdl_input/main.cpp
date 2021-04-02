#include <SDL.h>

#include "image.h"
#include "renderer.h"
#include "sprite.h"

#include <SDL.h>

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

	SDL_Delay(500);

	t.free();
	i.free();
	r.destroy();

	SDL_Quit();
}
