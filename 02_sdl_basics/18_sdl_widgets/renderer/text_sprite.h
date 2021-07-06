#ifndef TEXT_SPRITE_H
#define TEXT_SPRITE_H

#include <SDL.h>

#include "sprite.h"

#include "core/color.h"
#include "image.h"
#include "core/string.h"
#include "true_type_font.h"
#include "core/vector2.h"
#include "text_image.h"

class TextSprite : public Sprite {
public:
	TextImage::TextType get_text_type();
	void set_text_type(const TextImage::TextType type);

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

	TextSprite();
	TextSprite(TrueTypeFont *font);
	TextSprite(TrueTypeFont *font, const String &text, const Color &fg = Color(), const Color &bg = Color());
	virtual ~TextSprite();

private:
    TextImage *_text_image;
    Texture *_tex;
};

#endif
