#include "texture.h"

#include <stdio.h>

void Texture::load_image(const char* file_name) {
    if (image) {
        SDL_FreeSurface(image);
        glDeleteTextures(1, &texture);
    }

    image = SDL_LoadBMP(file_name);
    if (!image) {
        printf("Couldn't load %s.\n", file_name);
    } else {
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, image->w, image->h, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);

        apply_filer();
    }
}
void Texture::apply_filer() {
    GLint param = GL_NEAREST;

    if (filter == TEXTURE_FILTER_LINEAR)
        param = GL_LINEAR;

    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, param);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, param);
}

Texture::Texture() {
    filter = TEXTURE_FILTER_NEAREST;
    texture = 0;
    image = nullptr;
}
Texture::~Texture() {
    if (image) {
        SDL_FreeSurface(image);

        glDeleteTextures(1, &texture);
    }
}