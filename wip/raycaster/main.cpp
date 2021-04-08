
#define SDL_MAIN_HANDLED

#ifdef _MSC_VER

#define SDL_MAIN_HANDLED
#include <SDL.h>

#else

#ifdef __ANDROID__
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#endif

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#include <math.h>
#include <chrono>

int target_fps = 60;
float target_fpsf = 1 / target_fps;
float _delta = 0;

bool running = true;

SDL_Window *window;
SDL_Renderer *renderer;

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 640

//----------------------MAP----------------------
#define mapX 8 // map width
#define mapY 8 // map height
#define mapS 64 // map cube size
int map[] = {
	1, 1, 1, 1, 1, 1, 1, 1, //
	1, 0, 0, 0, 0, 0, 0, 0, //
	1, 0, 0, 0, 0, 1, 0, 1, //
	1, 0, 0, 1, 0, 0, 1, 1, //
	1, 0, 1, 0, 0, 0, 0, 1, //
	1, 0, 0, 1, 0, 0, 0, 1, //
	1, 0, 0, 0, 0, 0, 0, 1, //
	1, 1, 1, 0, 1, 1, 1, 1, //
};

void drawMap2D() {
	SDL_Rect colorBar;
	colorBar.x = 0;
	colorBar.y = 0;
	colorBar.w = mapS;
	colorBar.h = mapS;

	int x, y;
	for (y = 0; y < mapY; ++y) {
		for (x = 0; x < mapX; ++x) {
			if (map[y * mapX + x] == 1) {
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			} else {
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			}

			colorBar.x = x * mapS;
			colorBar.y = y * mapS;

			SDL_RenderFillRect(renderer, &colorBar);
		}
	}
}
//---------------------------------------------------------------------------

#define KEY_FORWARD SDL_SCANCODE_W
#define KEY_LEFT SDL_SCANCODE_A
#define KEY_RIGHT SDL_SCANCODE_D
#define KEY_BACK SDL_SCANCODE_S

#define KEY_INDEX_FORWARD 0
#define KEY_INDEX_LEFT 1
#define KEY_INDEX_RIGHT 2
#define KEY_INDEX_BACK 3

#define KEYS_MAX 4

bool keys[KEYS_MAX] = { false, false, false, false };

bool is_key_down(int index) {
	return keys[index];
}

void handle_keydown(SDL_Scancode scancode) {
	switch (scancode) {
		case KEY_FORWARD:
			keys[KEY_INDEX_FORWARD] = true;
			break;
		case KEY_LEFT:
			keys[KEY_INDEX_LEFT] = true;
			break;
		case KEY_RIGHT:
			keys[KEY_INDEX_RIGHT] = true;
			break;
		case KEY_BACK:
			keys[KEY_INDEX_BACK] = true;
			break;
	}
}

void handle_keyup(SDL_Scancode scancode) {
	switch (scancode) {
		case KEY_FORWARD:
			keys[KEY_INDEX_FORWARD] = false;
			break;
		case KEY_LEFT:
			keys[KEY_INDEX_LEFT] = false;
			break;
		case KEY_RIGHT:
			keys[KEY_INDEX_RIGHT] = false;
			break;
		case KEY_BACK:
			keys[KEY_INDEX_BACK] = false;
			break;
	}
}

void handle_input(float delta) {
	// handle input
	SDL_Event current_event;

	while (SDL_PollEvent(&current_event)) {
		switch (current_event.type) {
			case SDL_QUIT:
				running = false;
				break;

			case SDL_KEYDOWN:
				//if (current_event.key.repeat > 0)
				//  break;

				handle_keydown(current_event.key.keysym.scancode);

				break;
			case SDL_KEYUP:
				handle_keyup(current_event.key.keysym.scancode);

				break;
		}
	}
}

//------------------------PLAYER------------------------------------------------
#define PLAYER_SPEED 100.0
#define PLAYER_TURNING_SPEED 180.0

float degToRad(int a) {
	return a * M_PI / 180.0;
}
float FixAng(float a) {
	if (a >= 360) {
		a -= 360;
	}
	if (a < 0) {
		a += 360;
	}
	return a;
}

float px = 150;
float py = 150;
float pa = 90;
float pdx = cos(degToRad(pa));
float pdy = -sin(degToRad(pa));

void drawPlayer2D() {
	SDL_Rect colorBar;
	colorBar.x = 0;
	colorBar.y = 0;
	colorBar.w = 10;
	colorBar.h = 10;

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	colorBar.x = px - 5;
	colorBar.y = py - 5;

	SDL_RenderFillRect(renderer, &colorBar);

	SDL_RenderDrawLine(renderer, px, py, px + pdx * 20, py + pdy * 20);
}

void update_player(float delta) {
	if (is_key_down(KEY_INDEX_LEFT)) {
		pa += PLAYER_TURNING_SPEED * delta;
		pa = FixAng(pa);
		pdx = cos(degToRad(pa));
		pdy = -sin(degToRad(pa));
	}

	if (is_key_down(KEY_INDEX_RIGHT)) {
		pa -= PLAYER_TURNING_SPEED * delta;
		pa = FixAng(pa);
		pdx = cos(degToRad(pa));
		pdy = -sin(degToRad(pa));
	}

	if (is_key_down(KEY_INDEX_FORWARD)) {
		px += pdx * PLAYER_SPEED * delta;
		py += pdy * PLAYER_SPEED * delta;
	}

	if (is_key_down(KEY_INDEX_BACK)) {
		px -= pdx * PLAYER_SPEED * delta;
		py -= pdy * PLAYER_SPEED * delta;
	}
} //-----------------------------------------------------------------------------

//---------------------------Draw Rays and Walls--------------------------------
float distance(float ax, float ay, float bx, float by, float ang) {
	return cos(degToRad(ang)) * (bx - ax) - sin(degToRad(ang)) * (by - ay);
}

void drawRays2D() {
	int r, mx, my, mp, dof, side;
	float vx, vy, rx, ry, ra, xo, yo, disV, disH;

	ra = FixAng(pa + 30); //ray set back 30 degrees

	for (r = 0; r < 60; r++) {
		//---Vertical---
		dof = 0;
		side = 0;
		disV = 100000;
		float Tan = tan(degToRad(ra));
		if (cos(degToRad(ra)) > 0.001) {
			rx = (((int)px >> 6) << 6) + 64;
			ry = (px - rx) * Tan + py;
			xo = 64;
			yo = -xo * Tan;
		} //looking left
		else if (cos(degToRad(ra)) < -0.001) {
			rx = (((int)px >> 6) << 6) - 0.0001;
			ry = (px - rx) * Tan + py;
			xo = -64;
			yo = -xo * Tan;
		} //looking right
		else {
			rx = px;
			ry = py;
			dof = 8;
		} //looking up or down. no hit

		while (dof < 8) {
			mx = (int)(rx) >> 6;
			my = (int)(ry) >> 6;
			mp = my * mapX + mx;
			if (mp > 0 && mp < mapX * mapY && map[mp] == 1) {
				dof = 8;
				disV = cos(degToRad(ra)) * (rx - px) - sin(degToRad(ra)) * (ry - py);
			} //hit
			else {
				rx += xo;
				ry += yo;
				dof += 1;
			} //check next horizontal
		}
		vx = rx;
		vy = ry;

		//---Horizontal---
		dof = 0;
		disH = 100000;
		Tan = 1.0 / Tan;
		if (sin(degToRad(ra)) > 0.001) {
			ry = (((int)py >> 6) << 6) - 0.0001;
			rx = (py - ry) * Tan + px;
			yo = -64;
			xo = -yo * Tan;
		} //looking up
		else if (sin(degToRad(ra)) < -0.001) {
			ry = (((int)py >> 6) << 6) + 64;
			rx = (py - ry) * Tan + px;
			yo = 64;
			xo = -yo * Tan;
		} //looking down
		else {
			rx = px;
			ry = py;
			dof = 8;
		} //looking straight left or right

		while (dof < 8) {
			mx = (int)(rx) >> 6;
			my = (int)(ry) >> 6;
			mp = my * mapX + mx;
			if (mp > 0 && mp < mapX * mapY && map[mp] == 1) {
				dof = 8;
				disH = cos(degToRad(ra)) * (rx - px) - sin(degToRad(ra)) * (ry - py);
			} //hit
			else {
				rx += xo;
				ry += yo;
				dof += 1;
			} //check next horizontal
		}

        SDL_SetRenderDrawColor(renderer, 255, 200, 255, 255);
        if (disV < disH) {
			rx = vx;
			ry = vy;
			disH = disV;
			SDL_SetRenderDrawColor(renderer, 255, 160, 255, 255);
		} //horizontal hit first

       SDL_RenderDrawLine(renderer, px, py, rx, ry);

		int ca = FixAng(pa - ra);
		disH = disH * cos(degToRad(ca)); //fix fisheye
		int lineH = (mapS * 320) / (disH);
		if (lineH > 320) {
			lineH = 320;
		} //line height and limit
		int lineOff = 160 - (lineH >> 1); //line offset

        SDL_RenderDrawLine(renderer,r * 8 + 530,lineOff, r * 8 + 530, lineOff + lineH);

		ra = FixAng(ra - 1); //go to next ray
	}
} //-----------------------------------------------------------------------------

void update(float delta) {
	update_player(delta);
}

void render() {
	// Clear the window with a black background
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	drawMap2D();
	drawPlayer2D();
    drawRays2D();

	SDL_RenderPresent(renderer);
}

void iterate() {
	std::chrono::high_resolution_clock::time_point start =
			std::chrono::high_resolution_clock::now();

	handle_input(_delta);
	update(_delta);
	render();

	std::chrono::high_resolution_clock::time_point end =
			std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	double t = elapsed_seconds.count();

	double remaining = target_fpsf - t;

	if (remaining > 0) {
		Uint32 fms = static_cast<Uint32>(remaining * 1000.0);

		_delta = target_fpsf;

		SDL_Delay(fms);
	} else {
		_delta = t;
	}
}

int main(int argc, char *argv[]) {
	SDL_SetMainReady();
	int error = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

	if (error) {
		SDL_Log("SDL_Init Error!: %s", SDL_GetError());

		return 1;
	}

	error = SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT,
			SDL_WINDOW_SHOWN, &window, &renderer);

	if (error) {
		SDL_Log("SDL_Init Error!: %s", SDL_GetError());

		return 1;
	}

#ifdef __EMSCRIPTEN__

	emscripten_set_main_loop(iterate, 0, 1);

#else

	while (running) {
		iterate();
	}

#endif

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	window = nullptr;
	renderer = nullptr;

	SDL_Quit();

	return 0;
}
