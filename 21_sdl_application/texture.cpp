#include "texture.h"

#include "renderer.h"

Color Texture::get_color_mod() const {
	Uint8 r;
	Uint8 g;
	Uint8 b;
	Uint8 a;

	SDL_GetTextureColorMod(_texture, &r, &g, &b);
	SDL_GetTextureAlphaMod(_texture, &a);

	return Color(r, g, b, a);
}
void Texture::set_color_mod(const Color &color) {
	SDL_SetTextureColorMod(_texture, color.r, color.g, color.b);
	SDL_SetTextureAlphaMod(_texture, color.a);
}

SDL_BlendMode Texture::get_blend_mode() const {
	SDL_BlendMode blendMode;

	SDL_GetTextureBlendMode(_texture, &blendMode);

	return blendMode;
}
void Texture::set_blend_mode(const SDL_BlendMode blend_mode) {
	SDL_SetTextureBlendMode(_texture, blend_mode);
}

SDL_ScaleMode Texture::get_texture_scale_mode() const {
	SDL_ScaleMode scale_mode;

	SDL_GetTextureScaleMode(_texture, &scale_mode);

	return scale_mode;
}
void Texture::set_texture_scale_mode(const SDL_ScaleMode scale_mode) {
	SDL_SetTextureScaleMode(_texture, scale_mode);
}

Image *Texture::get_image() {
	return _image;
}
void Texture::set_image(Image *image) {
	if (_texture) {
		free();
	}

	_image = image;

	refresh();
}

int Texture::get_width() const {
	Uint32 format;
	int access;
	int w;
	int h;

	if (SDL_QueryTexture(_texture, &format, &access, &w, &h)) {
		return 0;
	}

	return w;
}
int Texture::get_height() const {
	Uint32 format;
	int access;
	int w;
	int h;

	if (SDL_QueryTexture(_texture, &format, &access, &w, &h)) {
		return 0;
	}

	return h;
}
Uint32 Texture::get_format() const {
	Uint32 format;
	int access;
	int w;
	int h;

	if (SDL_QueryTexture(_texture, &format, &access, &w, &h)) {
		return 0;
	}

	return format;
}
int Texture::get_access() const {
	Uint32 format;
	int access;
	int w;
	int h;

	if (SDL_QueryTexture(_texture, &format, &access, &w, &h)) {
		return 0;
	}

	return access;
}

void Texture::create(int access, int w, int h) {
	if (_texture) {
		free();
	}

	_image = nullptr;

	_texture = SDL_CreateTexture(Renderer::get_singleton()->get_renderer(), SDL_PIXELFORMAT_RGBA8888, access, w, h);
}
void Texture::refresh() {
	if (_image == nullptr) {
		return;
	}

	if (_image->get_surface() == nullptr) {
		return;
	}

	if (_texture) {
		free();
	}

	_texture = SDL_CreateTextureFromSurface(Renderer::get_singleton()->get_renderer(), _image->get_surface());
}
void Texture::free() {
    if (_texture) {
        SDL_DestroyTexture(_texture);

		_texture = nullptr;
    }
}

SDL_Texture *Texture::get_texture() {
    return _texture;
}
SDL_Texture *Texture::get_texture() const {
	return _texture;
}

bool Texture::is_render_target() {
	if (_texture == Renderer::get_singleton()->get_render_target()) {
		return true;
	}

	return false;
}

Texture::Texture() {
	_image = nullptr;
	_texture = nullptr;
}
Texture::Texture(Image *image) {
	_image = nullptr;
	_texture = nullptr;

	set_image(image);
}
Texture::~Texture() {
	if (_texture) {
		free();
	}
}