
#if __ANDROID__
#include <SDL.h>
#else
//ezt kellett volna rakni az application.h ból ide
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#endif


