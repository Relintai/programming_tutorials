#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#include "application.h"

#include "game_application.h"
#define APPLICATION_CLASS GameApplication

Application *application = nullptr;

void handle_frame() {
    application->main_loop();
}

int main(int argc, char *argv[]) {
    application = new APPLICATION_CLASS();

    #ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(handle_frame, 0, 1);
    #else

    while (application->running) {
        application->main_loop();
    }
    #endif

    delete application;

    return 0;
}