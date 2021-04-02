#include <SDL.h>

#include "image.h"
#include "renderer.h"
#include "sprite.h"

#include <SDL.h>

int main(int argv, char **args) {
	Renderer r;

	Image i("ti.bmp");

	i.lock();
	i.set_pixel(i.get_height() - 1, i.get_width() - 1, Color(0, 0, 255, 255));
	i.unlock();

/* old
	SDL_Texture *t = SDL_CreateTextureFromSurface(r.get_renderer(), i.get_surface());
	r.set_draw_color(0, 0, 0, 255);
	r.clear();
	SDL_Rect rs;
	rs.x = 0;
	rs.y = 0;
	rs.w = i.get_width();
	rs.h = i.get_height();
	SDL_RenderCopy(r.get_renderer(), t, &rs, &rs);
	*/

	r.set_draw_color(0, 0, 0, 255);
	r.clear();

	Texture t(&i);
	Sprite s(&t);

	s.set_x(30);
	s.set_y(30);

	//r.draw_texture(t, Rect2(0, 0, t.get_width(), t.get_height()));

	r.draw_sprite(s);

	r.present();

	int rgb[] = {
		203, 203, 203, // Gray
		254, 254, 31, // Yellow
		0, 255, 255, // Cyan
		0, 254, 30, // Green
		255, 16, 253, // Magenta
		253, 3, 2, // Red
		18, 14, 252, // Blue
		0, 0, 0 // Black
	};

	Rect2 colorBar;
	colorBar.x = 0;
	colorBar.y = 0;
	colorBar.w = 90;
	colorBar.h = 480;

	// Render a new color bar every 0.5 seconds
	for (int i = 0; i != sizeof rgb / sizeof *rgb; i += 3, colorBar.x += 90) {
		r.set_draw_color(rgb[i], rgb[i + 1], rgb[i + 2], 255);
		r.draw_rect(colorBar);
		r.present();

		SDL_Delay(500);
	}

	//old
	//SDL_DestroyTexture(t);

	t.free();
	i.free();
	r.destroy();

	SDL_Quit();
}
