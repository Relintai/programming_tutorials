
#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

SDL_Window *window;
SDL_Renderer *renderer;


int rgb[] = {
    203, 203, 203,
    244, 131, 123,
    23, 32, 41,
    220, 10, 120,
    13, 33, 230,
    11, 66, 44,
    78, 34, 135,
    185, 111, 55
};


bool running = true;

int current_start_index = 0;
int framecounter = 0;


//gameloop
void handle_frame() {
    //handle input
    SDL_Event current_evevnt;

    while(SDL_PollEvent(&current_evevnt)) {
        if (current_evevnt.type == SDL_QUIT) {
            running = false;
        }
    }

    //update world
    //most ez nem kell

    //render
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);


    SDL_Rect colorBar;
    colorBar.x = 0;
    colorBar.y = 0;
    colorBar.w = 90;
    colorBar.h = 480;

    for (int i = current_start_index; i != sizeof rgb / sizeof *rgb; i += 3, colorBar.x += 90) {
        SDL_SetRenderDrawColor(renderer, rgb[i], rgb[i + 1],rgb[i + 2], 255);
        SDL_RenderFillRect(renderer, &colorBar);
    }

    ++framecounter;

    if (framecounter == 600) {
        framecounter = 0;
        current_start_index += 3;

        if (current_start_index == sizeof rgb / sizeof *rgb)
            current_start_index = 0;
    }


    SDL_RenderPresent(renderer);
}


int main(int argc, char *argv[]) {

    SDL_SetMainReady();
    int error = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

    if (error) {
        SDL_Log("SDL_Init: %s", SDL_GetError());

        return 1;
    }

    error = SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_SHOWN, &window, &renderer);

    if (error) {
        SDL_Log("SDL_CreateWindowAndRenderer: %s", SDL_GetError());

        return 1;
    }

    #ifdef __EMSCRIPTEN__

    emscripten_set_main_loop(handle_frame, 0, 1);

    #else

    while (running) {
        handle_frame();
    }
    #endif

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    window = nullptr;
    renderer = nullptr;

    SDL_Quit();

    return 0;
}