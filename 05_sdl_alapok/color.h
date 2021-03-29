#ifndef COLOR_H
#define COLOR_H

#include <inttypes.h>

class Color {
public:
    Color();
    Color(uint8_t p_r, uint8_t p_g, uint8_t p_b, uint8_t p_a = 255);
    virtual ~Color();

    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
};

#endif