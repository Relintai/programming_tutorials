
#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>

#include "core/rect2.h"
#include "sprite.h"

#include <functional>

class Button {
public:
    enum ButtonState {
        BUTTON_STATE_UP,
        BUTTON_STATE_HOVER,
        BUTTON_STATE_DOWN,
        BUTTON_STATE_OFF,
    };

	void event(const SDL_Event &ev);
	void update(float delta);
	void render();

    std::function<void(void)> on_click;

    Button();
    virtual ~Button();

    ButtonState state;

	Rect2 transform;

    Sprite *up;
    Sprite *down;
    Sprite *hover;
    Sprite *off;
};

#endif
