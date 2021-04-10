
#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>

#include "rect2.h"
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

    //ver a: (Csak statikus fv állítható be rá)
    std::function<void(void)> on_click;

    //ver b: (Képes osztályok függvényeit is meghívni)
    //Meg lehet oldani sokféleképp, egyik sem annyira szép sajnos
    //mindneképp érdemes lenne setter mögé rejteni ezeket
    void* cls;
    std::function<void(void*)> on_click_member;

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
