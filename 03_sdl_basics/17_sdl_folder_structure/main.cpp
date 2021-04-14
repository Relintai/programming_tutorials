#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#include <SDL_ttf.h>

#include "application.h"
#include "renderer/renderer.h"

#include "impl_application.h"
#define APPLICATION_CLASS ImplApplication

Renderer *renderer = nullptr;
Application *application = nullptr;

void handle_frame() {
	application->main_loop();
}

int main(int argc, char *argv[]) {
	TTF_Init();

	renderer = new Renderer();
	application = new APPLICATION_CLASS();

#ifdef __EMSCRIPTEN__
	emscripten_set_main_loop(handle_frame, 0, 1);
#else
	while (application->running) {
		application->main_loop();
	}
#endif

	delete application;
	delete renderer;

	TTF_Quit();

	return 0;
}