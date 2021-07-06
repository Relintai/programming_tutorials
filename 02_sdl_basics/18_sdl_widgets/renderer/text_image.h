#ifndef TEXT_IMAGE_H
#define TEXT_IMAGE_H

#include <SDL.h>

#include "core/color.h"
#include "image.h"
#include "core/string.h"
#include "true_type_font.h"
#include "core/vector2.h"

class TextImage {
public:
	enum TextType {
		SOLID,
		SHADED,
		BLENDED,
		BLENDED_WRAPPED
	};

	TextType get_text_type();
	void set_text_type(const TextType type);

	TrueTypeFont *get_font();
	void set_font(TrueTypeFont *font);

	String get_text();
	void set_text(const String &text);

	Color get_fg_color();
	void get_fg_color(const Color &color);

	Color get_bg_color();
	void get_bg_color(const Color &color);

	Image *get_image();

	int get_width();
	int get_height();

	void render_image();

	TextImage();
	TextImage(TrueTypeFont *font);
	TextImage(TrueTypeFont *font, const String &text, const Color &fg = Color(), const Color &bg = Color());
	virtual ~TextImage();

private:
	TrueTypeFont *_font;
	String _text;
	Image *_image;
	TextType _text_type;
	Color _fg;
	Color _bg;
};

#endif