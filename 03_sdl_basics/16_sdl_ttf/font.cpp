#include "font.h"


SDL_Surface *Font::render_blended(const String &text, const Color &color) {
	if (!_font) {
		return nullptr;
	}
 
    return TTF_RenderText_Blended(_font, text.c_str(), color.to_sdl_color());
}

void Font::load(const String &file_name, const int ptsize, const int index) {
	if (index == -1) {
		_font = TTF_OpenFont(file_name.c_str(), ptsize);
	} else {
		_font = TTF_OpenFontIndex(file_name.c_str(), ptsize, index);
	}
}

void Font::free() {
	if (_font) {
		TTF_CloseFont(_font);

		_font = nullptr;
	}
}

Font::Font() {
	_font = nullptr;
}

Font::Font(const String &file_name, const int ptsize, const int index) {
	_font = nullptr;

	load(file_name, ptsize, index);
}

Font::~Font() {
	free();
}