#include "text_image.h"

TextImage::TextType TextImage::get_text_type() {
	return _text_type;
}
void TextImage::set_text_type(const TextImage::TextType type) {
	_text_type = type;
}

TrueTypeFont *TextImage::get_font() {
	return _font;
}
void TextImage::set_font(TrueTypeFont *font) {
	_font = font;
}

String TextImage::get_text() {
	return _text;
}
void TextImage::set_text(const String &text) {
	_text = text;

	render_image();
}

Color TextImage::get_fg_color() {
	return _fg;
}
void TextImage::get_fg_color(const Color &color) {
	_fg = color;
}

Color TextImage::get_bg_color() {
	return _bg;
}
void TextImage::get_bg_color(const Color &color) {
	_bg = color;
}

Image *TextImage::get_image() {
	return _image;
}

int TextImage::get_width() {
	return _image->get_width();
}
int TextImage::get_height() {
	return _image->get_height();
}

void TextImage::render_image() {
	_image->free();

	if (!_font) {
		return;
	}

	switch (_text_type) {
		case SOLID:
			_font->render_text_solid(_text, _fg, _image);
			break;
		case SHADED:
			_font->render_text_shaded(_text, _fg, _bg, _image);
			break;
		case BLENDED:
			_font->render_text_blended(_text, _fg, _image);
			break;
		case BLENDED_WRAPPED:
			_font->render_text_blended_wrapped(_text, _fg, 100, _image);
			break;

		default:
			break;
	}
}

TextImage::TextImage() {
	_font = nullptr;
	_text_type = BLENDED;
	_image = new Image();
}
TextImage::TextImage(TrueTypeFont *font) {
	_font = font;
	_text_type = BLENDED;
	_image = new Image();
}
TextImage::TextImage(TrueTypeFont *font, const String &text, const Color &fg, const Color &bg) {
	_bg = bg;
	_fg = fg;
	_font = font;
	_text_type = BLENDED;
	_text = text;
	_image = new Image();

	render_image();
}
TextImage::~TextImage() {
	delete _image;
}
