#include "color.h"

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

Color::~Color() {
}