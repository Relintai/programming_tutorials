#include "text_sprite.h"

TextImage::TextType TextSprite::get_text_type() {
	return _text_image->get_text_type();
}
void TextSprite::set_text_type(const TextImage::TextType type) {
	_text_image->set_text_type(type);
}

TrueTypeFont *TextSprite::get_font() {
	return _text_image->get_font();
}
void TextSprite::set_font(TrueTypeFont *font) {
	_text_image->set_font(font);
}

String TextSprite::get_text() {
	return _text_image->get_text();
}
void TextSprite::set_text(const String &text) {
	_text_image->set_text(text);

	render_image();
}

Color TextSprite::get_fg_color() {
	return _text_image->get_fg_color();
}
void TextSprite::get_fg_color(const Color &color) {
	_text_image->get_fg_color(color);
}

Color TextSprite::get_bg_color() {
	return _text_image->get_bg_color();
}
void TextSprite::get_bg_color(const Color &color) {
	_text_image->get_bg_color(color);
}

Image *TextSprite::get_image() {
	return _text_image->get_image();
}

int TextSprite::get_width() {
	return _text_image->get_width();
}
int TextSprite::get_height() {
	return _text_image->get_height();
}

void TextSprite::render_image() {
    _text_image->render_image();

	Image *img = _text_image->get_image();

	_tex->set_image(img);

	set_w(img->get_width());
	set_h(img->get_height());

	set_texture_clip_rect(Rect2(0, 0, img->get_width(), img->get_height()));
}

TextSprite::TextSprite() {
	_text_image = new TextImage();
	_tex = new Texture();

	set_texture(_tex);
}
TextSprite::TextSprite(TrueTypeFont *font) {
	_text_image = new TextImage(font);
	_tex = new Texture();

	set_texture(_tex);
}
TextSprite::TextSprite(TrueTypeFont *font, const String &text, const Color &fg, const Color &bg) {
	_text_image = new TextImage(font, text, fg, bg);
	_tex = new Texture();

	set_texture(_tex);

    render_image();
}
TextSprite::~TextSprite() {
	delete _text_image;
}
