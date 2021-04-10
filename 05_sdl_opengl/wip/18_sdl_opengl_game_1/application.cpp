#include "application.h"

#include <chrono>

Application *Application::_instance = nullptr;

void Application::event(const SDL_Event &ev) {
	if (ev.type == SDL_QUIT) {
		running = false;
	}

    scene->event(ev);
}

void Application::update(float delta) {
    scene->update(delta);
}

void Application::render() {
    scene->render();

    SDL_GL_SwapWindow(window);
}

void Application::main_loop() {
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

	//handle input
	SDL_Event current_event;

	while (SDL_PollEvent(&current_event)) {
		event(current_event);
	}

	//update world
	update(frame_delta);

	//render
	render();

    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    double t = elapsed_seconds.count();
    double tfps = 1.0 / static_cast<float>(target_fps);
    double remaining = tfps - t;

    if (remaining > 0) {
        Uint32 fms = static_cast<Uint32>(remaining * 1000.0);

        frame_delta = tfps;

        SDL_Delay(fms);
    } else {
        frame_delta = t;
    }
}

Application *Application::get_singleton() {
	return _instance;
}

Application::Application() {
	_instance = this;

	running = true;
	target_fps = 60;

	scene = nullptr;

	frame_delta = 0;

	SDL_SetMainReady();
	int error = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

	if (error) {
		SDL_Log("SDL_Init: %s", SDL_GetError());

		running = false;
		return;
	}

#if _WIN64
	//Use OpenGl 2.1
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
#else
	//Use OpenGl ES 2.0
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
#endif

	window = SDL_CreateWindow("SDL + OpenGL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	if (!window) {
		SDL_Log("SDL_CreateWindow: %s", SDL_GetError());

		running = false;
		return;
	}

	context = SDL_GL_CreateContext(window);

#ifdef _WIN64
	gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);
#endif
}

Application::~Application() {
	SDL_DestroyWindow(window);

	window = nullptr;

	SDL_Quit();
}
