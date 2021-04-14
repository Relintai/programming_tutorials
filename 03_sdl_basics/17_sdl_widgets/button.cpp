#include "button.h"

#include "math.h"

void Button::event(const SDL_Event &ev) {
	if (state == BUTTON_STATE_OFF) {
		return;
	}

	switch (ev.type) {
		case SDL_MOUSEMOTION: {
			int x = ev.motion.x;
			int y = ev.motion.y;

			if (transform.x < x && transform.x + transform.w > x && transform.y < y && transform.y + transform.w > y) {
				state = BUTTON_STATE_HOVER;
			} else {
				state = BUTTON_STATE_UP;
			}

			break;
		}
		case SDL_MOUSEBUTTONDOWN: {
			int x = ev.motion.x;
			int y = ev.motion.y;

			if (transform.x < x && transform.x + transform.w > x && transform.y < y && transform.y + transform.w > y) {
				state = BUTTON_STATE_DOWN;
			}

			break;
		}
		case SDL_MOUSEBUTTONUP: {
			int x = ev.motion.x;
			int y = ev.motion.y;

			if (transform.x < x && transform.x + transform.w > x && transform.y < y && transform.y + transform.w > y) {
				state = BUTTON_STATE_HOVER;

				if (on_click) {
					on_click();
				}
			} else {
				state = BUTTON_STATE_UP;
			}

			break;
		}
	}
}

void Button::update(float delta) {
}

void Button::render() {
	if (state == BUTTON_STATE_UP) {
		if (up) {
			up->set_transform(transform);
			up->draw();
		}
	} else if (state == BUTTON_STATE_HOVER) {
		if (hover) {
			hover->set_transform(transform);
			hover->draw();
		}
	} else if (state == BUTTON_STATE_DOWN) {
		if (down) {
			down->set_transform(transform);
			down->draw();
		}
	} else if (state == BUTTON_STATE_OFF) {
		if (off) {
			off->set_transform(transform);
			off->draw();
		}
	}
}

Button::Button() {
	state = BUTTON_STATE_UP;

	up = nullptr;
	down = nullptr;
	hover = nullptr;
	off = nullptr;
}

Button::~Button() {
}
