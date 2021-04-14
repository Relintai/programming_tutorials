#include "font.h"

int Font::get_style() {
	return TTF_GetFontStyle(_font);
}
void Font::set_style(const int style) {
	TTF_SetFontStyle(_font, style);
}

int Font::get_outline() {
	return TTF_GetFontOutline(_font);
}
void Font::set_outline(const int outline) {
	TTF_SetFontOutline(_font, outline);
}

int Font::get_hinting() {
	return TTF_GetFontHinting(_font);
}
void Font::set_hinting(const int hinting) {
	TTF_SetFontHinting(_font, hinting);
}

int Font::get_height() {
	return TTF_FontHeight(_font);
}
int Font::get_ascent() {
	return TTF_FontAscent(_font);
}
int Font::get_descent() {
	return TTF_FontDescent(_font);
}
int Font::get_line_skip() {
	return TTF_FontLineSkip(_font);
}

int Font::get_kerning() {
	return TTF_GetFontKerning(_font);
}
void Font::set_kerning(const int allowed) {
	TTF_SetFontKerning(_font, allowed);
}

long Font::get_faces() {
	return TTF_FontFaces(_font);
}

int Font::get_face_is_fixed_width() {
	return TTF_FontFaceIsFixedWidth(_font);
}
char *Font::get_face_family_name() {
	return TTF_FontFaceFamilyName(_font);
}
char *Font::get_font_face_style_name() {
	return TTF_FontFaceStyleName(_font);
}

bool Font::is_glyph_provided(Uint16 ch) {
	return TTF_GlyphIsProvided(_font, ch);
}

Font::GlyphMetric Font::glyph_metrics(Uint16 ch) {
	Font::GlyphMetric g;

	TTF_GlyphMetrics(_font, ch, &g.minx, &g.maxx, &g.miny, &g.maxy, &g.advance);

	return g;
}

Vector2 Font::get_size_text(const String &text) {
	int w;
	int h;

	TTF_SizeText(_font, text.c_str(), &w, &h);

	return Vector2(w, h);
}

Vector2 Font::get_size_utf8(const String &text) {
	int w;
	int h;

	TTF_SizeUTF8(_font, text.c_str(), &w, &h);

	return Vector2(w, h);
}

Image *Font::render_text_solid(const String &text, const Color &fg) {
	if (!_font) {
		return nullptr;
	}

	return new Image(TTF_RenderText_Solid(_font, text.c_str(), fg.to_sdl_color()));
}

Image *Font::render_utf8_solid(const String &text, const Color &fg) {
	if (!_font) {
		return nullptr;
	}

	return new Image(TTF_RenderUTF8_Solid(_font, text.c_str(), fg.to_sdl_color()));
}

Image *Font::render_glyph_solid(const Uint16 ch, const Color &fg) {
	if (!_font) {
		return nullptr;
	}

	return new Image(TTF_RenderGlyph_Solid(_font, ch, fg.to_sdl_color()));
}

Image *Font::render_text_shaded(const String &text, const Color &fg, const Color &bg) {
	if (!_font) {
		return nullptr;
	}

	return new Image(TTF_RenderText_Shaded(_font, text.c_str(), fg.to_sdl_color(), bg.to_sdl_color()));
}

Image *Font::render_utf8_shaded(const String &text, const Color &fg, const Color &bg) {
	if (!_font) {
		return nullptr;
	}

	return new Image(TTF_RenderUTF8_Shaded(_font, text.c_str(), fg.to_sdl_color(), bg.to_sdl_color()));
}

Image *Font::render_glyph_shaded(const Uint16 ch, const Color &fg, const Color &bg) {
	if (!_font) {
		return nullptr;
	}

	return new Image(TTF_RenderGlyph_Shaded(_font, ch, fg.to_sdl_color(), bg.to_sdl_color()));
}

Image *Font::render_text_blended(const String &text, const Color &fg) {
	if (!_font) {
		return nullptr;
	}

	return new Image(TTF_RenderText_Blended(_font, text.c_str(), fg.to_sdl_color()));
}

Image *Font::render_utf8_blended(const String &text, const Color &fg) {
	if (!_font) {
		return nullptr;
	}

	return new Image(TTF_RenderUTF8_Blended(_font, text.c_str(), fg.to_sdl_color()));
}

Image *Font::render_text_blended_wrapped(const String &text, const Color &fg, Uint32 wrap_length) {
	if (!_font) {
		return nullptr;
	}

	return new Image(TTF_RenderText_Blended_Wrapped(_font, text.c_str(), fg.to_sdl_color(), wrap_length));
}

Image *Font::render_utf8_blended_wrapped(const String &text, const Color &fg, Uint32 wrap_length) {
	if (!_font) {
		return nullptr;
	}

	return new Image(TTF_RenderUTF8_Blended_Wrapped(_font, text.c_str(), fg.to_sdl_color(), wrap_length));
}

Image *Font::render_glyph_blended(const Uint16 ch, const Color &fg) {
	if (!_font) {
		return nullptr;
	}

	return new Image(TTF_RenderGlyph_Blended(_font, ch, fg.to_sdl_color()));
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