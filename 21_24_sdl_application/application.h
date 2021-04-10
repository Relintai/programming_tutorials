#ifndef APPLICATION_H
#define APPLICATION_H

#include <SDL.h>

#include "scene.h"

class Application {
public:
    bool running;
    int target_fps;

    virtual void event(const SDL_Event &current_event);
    virtual void update(float delta);
    virtual void render();

    void main_loop();

    Application();
    virtual ~Application();

    Scene *scene;

    static Application* get_singleton();

    double frame_delta = 0;

protected:
    static Application* _instance;
};

#endif