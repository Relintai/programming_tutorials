#include "color.h"

uint32_t Color::to_key() const {
	uint32_t val = 0;

	//<< = left shift int típusoknál -> azaz az intek bitjeit eltolja eggyel balra:
	//pl.: 001010101 ből lesz: 010101010, aztán 101010100, aztán 010101000 etc

	//az r az uint8_t, azaz egy 8 bites int (unsigned byte típus pl java/c#-ban)
	//tehát alakítsuk át 32 bites uint-é: static_cast<uint32_t>(r)
	//Ez az új c++-os castolás, lehetne így is: (uint32_t) r
	//De, nem ajánlják már, mert ez 4-5 ilyen static_cast, dynamic_cast etc függvényt
	//próbál végig, megadott sorrendben, és csak kiírtam a megfelelőt expliciten.

	//static_cast<uint32_t>(r) << 24: (8db 0) (8db 0) (8db 0) (r száma) Ez lessz: (r száma) (8db 0) (8db 0) (8db 0)
	//static_cast<uint32_t>(g) << 24: (8db 0) (8db 0) (8db 0) (g száma) Ez lessz: (8db 0) (g száma) (8db 0) (8db 0)
	//static_cast<uint32_t>(b) << 24: (8db 0) (8db 0) (8db 0) (b száma) Ez lessz: (8db 0) (8db 0) (b száma) (8db 0)
	//static_cast<uint32_t>(a) << 24: (8db 0) (8db 0) (8db 0) (a száma) Ez lessz: (8db 0) (8db 0) (8db 0) (a száma)

	//| a bináris vagy -> a számok birtjeit össze bináris vagyolja -> azaz ahol valaho 1 van, ott az eredmény be egy lesz: 00100 | 00010 -> 00110
	//|= -> bináris vagy egyenlő

	val |= static_cast<uint32_t>(r) << 24;
	val |= static_cast<uint32_t>(g) << 16;
	val |= static_cast<uint32_t>(b) << 8;
	val |= static_cast<uint32_t>(a) << 0;

	//azaz a végeredmény:
	//1 uint32t, aminek a bitjei: (r száma) (g száma) (b száma) (a száma)

	return val;
}

void Color::from_key(const uint32_t key) {
	//A to_key függvény megfordítása.

	//& itt a bináris és.
	//azok a bitek lesznek 1ek, amik mindkét operandusba 1-ek: 001010 & 111110 -> 001010

	//A 16-os számrendszerbeli számokat 0x<valami> formában lehet megadni.

	//Azért használtam 16os számrendszerbeli számokat, mert itt sokkal szemléletesebbek.
	//Ugyanis-> 0xF = 1111
	//Azaz minden F 4db 1es bitet jelöl.
	//Így már biztosan látszik, hogy mit csinálunk

	//key & 0xFF000000 kiszedjük a legelől levő 8 bitet (Minden más bit biztosan 0 lesz.), etc

	r = (key & 0xFF000000) >> 24;
	g = (key & 0x00FF0000) >> 16;
	b = (key & 0x0000FF00) >> 8;
	a = (key & 0x000000FF) >> 0;

	//>> az itt a right shift, ugyan az mint a left shift, csak itt a biteket jobbra mozgatjuk

	//Nyilván, egyéb módon is meg lehet csinálni ezt a függvényt.
	//pl csak right shiftelgetni, és castolni uint8_t-vé az eredményt, etc.

	//Azért cisnáltam így, mert szerintem ezt a módszert a leghasznosabb látni hosszú távon.
	//Pl. ugyan így lehet hálózati csomagokat méretre optimalizálni.
}

SDL_Color Color::to_sdl_color() const {
    SDL_Color c;

    c.r = r;
    c.g = g;
    c.b = b;
    c.a = a;

    return c;
}

void Color::from_sdl_color(const SDL_Color &key) {
    r = key.r;
    g = key.g;
    b = key.b;
    a = key.a;
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