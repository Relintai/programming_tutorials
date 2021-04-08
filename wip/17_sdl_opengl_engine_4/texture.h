#ifndef TEXTURE_H
#define TEXTURE_H

#include "opengl.h"
#include <SDL2/SDL.h>

class Texture {
public:
    enum TextureFilter {
        TEXTURE_FILTER_NEAREST = 0,
        TEXTURE_FILTER_LINEAR,
    };

    void load_image(const char* file_name);
    void apply_filer();

    TextureFilter filter;
    GLuint texture;
    SDL_Surface *image;

    Texture();
    virtual ~Texture();
};

#endif