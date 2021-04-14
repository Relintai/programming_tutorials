#include "application.h"

#include "renderer/renderer.h"

Application* Application::_instance = nullptr;

#include <chrono>

void Application::event(const SDL_Event &current_event) {
	switch (current_event.type) {
		case SDL_QUIT:
			running = false;
			break;
	}
    
    scene->event(current_event);
}

void Application::update(float delta) {
    scene->update(delta);
}
void Application::render() {
    scene->render();

	Renderer::get_singleton()->present();
}

void Application::main_loop() {
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

	//handle input
	SDL_Event current_event;
	while (SDL_PollEvent(&current_event)) {
		event(current_event);
	}

	update(frame_delta);
	render();

	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	double t = elapsed_seconds.count();

	double tfps = 1.0 / static_cast<double>(target_fps);

	double remaining = tfps - t;

	if (remaining > 0) {
		Uint32 fms = static_cast<Uint32>(remaining * 1000.0);

		frame_delta = tfps;

		SDL_Delay(fms);
	} else {
		frame_delta = t;
	}
}

Application::Application() {
    running = true;
    target_fps = 60;

    scene = nullptr;
    _instance = this;
}
Application::~Application() {
    _instance = nullptr;
}

Application* Application::get_singleton() {
    return _instance;
}
