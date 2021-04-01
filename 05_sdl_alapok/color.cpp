#include "color.h"

uint32_t Color::to_key() const {
	uint32_t val = 0;

	val |= static_cast<uint32_t>(r) << 24;
	val |= static_cast<uint32_t>(g) << 16;
	val |= static_cast<uint32_t>(b) << 8;
	val |= static_cast<uint32_t>(a) << 0;

	return val;
}

void Color::from_key(const uint32_t key) {
	r = key & 0xFFFF000000000000;
	g = key & 0x0000FFFF00000000;
	b = key & 0x00000000FFFF0000;
	a = key & 0x000000000000FFFF;
}

Color::Color() {
	r = 0;
	g = 0;
	b = 0;
	a = 255;
}

Color::Color(uint8_t p_r, uint8_t p_g, uint8_t p_b, uint8_t p_a) {
	r = p_r;
	g = p_g;
	b = p_b;
	a = p_a;
}

Color::Color(const uint32_t key) {
	from_key(key);
}

Color::~Color() {
}