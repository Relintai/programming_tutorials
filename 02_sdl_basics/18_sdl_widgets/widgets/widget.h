
#ifndef WIDGET_H
#define WIDGET_H

#include <SDL.h>

#include "core/vector.h"

class Widget {
public:
	void event(const SDL_Event &ev);
	void update(float delta);
	void render();

    virtual void _event(const SDL_Event &ev);
	virtual void _update(float delta);
	virtual void _render();

    Widget();
    virtual ~Widget();

private:
    Vector<Widget *> _children;
};

#endif
