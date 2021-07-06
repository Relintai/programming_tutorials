#ifndef TURE_TYPE_FONT_H
#define TURE_TYPE_FONT_H

#include <SDL.h>
#include <SDL_ttf.h>

#include "core/color.h"
#include "core/string.h"
#include "core/vector2.h"
#include "image.h"

class TrueTypeFont {
public:
	struct GlyphMetric {
		int minx;
		int maxx;
		int miny;
		int maxy;
		int advance;
	};

	int get_style();
	void set_style(const int style);

	int get_outline();
	void set_outline(const int outline);

	int get_hinting();
	void set_hinting(const int hinting);

	int get_height();
	int get_ascent();
	int get_descent();
	int get_line_skip();

	int get_kerning();
	void set_kerning(const int allowed);

	long get_faces();

	int get_face_is_fixed_width();
	char *get_face_family_name();
	char *get_face_style_name();

	bool is_glyph_provided(Uint16 ch);

	GlyphMetric glyph_metrics(Uint16 ch);

	Vector2 get_size_text(const String &text);
	Vector2 get_size_utf8(const String &text);
	Vector2 get_size_unicode(const String &text);

	Image *render_text_solid(const String &text, const Color &fg, Image *img = nullptr);
	Image *render_utf8_solid(const String &text, const Color &fg, Image *img = nullptr);
    Image *render_glyph_solid(const Uint16 ch, const Color &fg, Image *img = nullptr);

	Image *render_text_shaded(const String &text, const Color &fg, const Color &bg, Image *img = nullptr);
	Image *render_utf8_shaded(const String &text, const Color &fg, const Color &bg, Image *img = nullptr);
	Image *render_glyph_shaded(const Uint16 ch, const Color &fg, const Color &bg, Image *img = nullptr);

	Image *render_text_blended(const String &text, const Color &fg, Image *img = nullptr);
	Image *render_utf8_blended(const String &text, const Color &fg, Image *img = nullptr);

	Image *render_text_blended_wrapped(const String &text, const Color &fg, Uint32 wrap_length, Image *img = nullptr);
	Image *render_utf8_blended_wrapped(const String &text, const Color &fg, Uint32 wrap_length, Image *img = nullptr);

	Image *render_glyph_blended(const Uint16 ch, const Color &fg, Image *img = nullptr);

	void load(const String &file_name, const int ptsize, const int index = -1);
	void free();

	TrueTypeFont();
	TrueTypeFont(const String &file_name, const int ptsize, const int index = -1);
	~TrueTypeFont();

private:
	TTF_Font *_font;
};

#endif