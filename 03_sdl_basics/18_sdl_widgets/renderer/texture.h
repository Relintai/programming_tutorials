#ifndef TEXTURE_H
#define TEXTURE_H

#include "image.h"
#include <SDL.h>

class Texture {
public:
    Color get_color_mod() const;
    void set_color_mod(const Color &color);

    SDL_BlendMode get_blend_mode() const;
    void set_blend_mode(const SDL_BlendMode blend_mode);

    SDL_ScaleMode get_texture_scale_mode() const;
    void set_texture_scale_mode(const SDL_ScaleMode scale_mode);

    Image *get_image();
    void set_image(Image *image);

    int get_width() const;
    int get_height() const;
    Uint32 get_format() const;
    int get_access() const;

    void create(const int access, const int w, const int h);
    void refresh();
    void free();

    SDL_Texture *get_texture();
    SDL_Texture *get_texture() const;

    bool is_render_target();

    Texture();
    Texture(Image *image);
    virtual ~Texture();

private:
    Image *_image;
    SDL_Texture *_texture;
};

#endif