#include <SDL.h>

#include "renderer.h"



int main(int argv, char** args) {
    Renderer r;

    r.set_draw_color(0, 0, 0, 255);
    r.clear();
    r.present();

    int rgb[] = { 203, 203, 203, // Gray
                  254, 254,  31, // Yellow
                  0, 255, 255, // Cyan
                  0, 254,  30, // Green
                  255,  16, 253, // Magenta
                  253,   3,   2, // Red
                  18,  14, 252, // Blue
                  0,   0,   0  // Black
                };

    SDL_Rect colorBar;
    colorBar.x = 0;
    colorBar.y = 0;
    colorBar.w = 90;
    colorBar.h = 480;

    // Render a new color bar every 0.5 seconds
    for ( int i = 0; i != sizeof rgb / sizeof *rgb; i += 3, colorBar.x += 90)
    {
        r.set_draw_color(rgb[i], rgb[i + 1], rgb[i + 2], 255);
        r.draw_rect(colorBar);
        r.present();

        SDL_Delay(500);
    }

    r.destroy();
    
    SDL_Quit();
}
