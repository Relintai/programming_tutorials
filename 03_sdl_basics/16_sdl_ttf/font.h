#ifndef FONT_H
#define FONT_H

#include <SDL.h>
#include <SDL_ttf.h>

#include "string.h"
#include "color.h"

class Font {
public:
    //extern DECLSPEC int SDLCALL TTF_GetFontStyle(const TTF_Font *font);
    //extern DECLSPEC void SDLCALL TTF_SetFontStyle(TTF_Font *font, int style);
    //extern DECLSPEC int SDLCALL TTF_GetFontOutline(const TTF_Font *font);
   // extern DECLSPEC void SDLCALL TTF_SetFontOutline(TTF_Font *font, int outline);

   //extern DECLSPEC int SDLCALL TTF_GetFontHinting(const TTF_Font *font);
    //extern DECLSPEC void SDLCALL TTF_SetFontHinting(TTF_Font *font, int hinting);

    //extern DECLSPEC int SDLCALL TTF_FontHeight(const TTF_Font *font);
/*
    extern DECLSPEC int SDLCALL TTF_FontAscent(const TTF_Font *font);

    extern DECLSPEC int SDLCALL TTF_FontDescent(const TTF_Font *font);

    extern DECLSPEC int SDLCALL TTF_FontLineSkip(const TTF_Font *font);

    extern DECLSPEC int SDLCALL TTF_GetFontKerning(const TTF_Font *font);
    extern DECLSPEC void SDLCALL TTF_SetFontKerning(TTF_Font *font, int allowed);

    extern DECLSPEC long SDLCALL TTF_FontFaces(const TTF_Font *font);

    extern DECLSPEC int SDLCALL TTF_FontFaceIsFixedWidth(const TTF_Font *font);
    extern DECLSPEC char * SDLCALL TTF_FontFaceFamilyName(const TTF_Font *font);
    extern DECLSPEC char * SDLCALL TTF_FontFaceStyleName(const TTF_Font *font);

    extern DECLSPEC int SDLCALL TTF_GlyphIsProvided(const TTF_Font *font, Uint16 ch);

    extern DECLSPEC int SDLCALL TTF_GlyphMetrics(TTF_Font *font, Uint16 ch,int *minx, int *maxx,int *miny, int *maxy, int *advance);

    extern DECLSPEC int SDLCALL TTF_SizeText(TTF_Font *font, const char *text, int *w, int *h);
    extern DECLSPEC int SDLCALL TTF_SizeUTF8(TTF_Font *font, const char *text, int *w, int *h);
    extern DECLSPEC int SDLCALL TTF_SizeUNICODE(TTF_Font *font, const Uint16 *text, int *w, int *h);

    extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderText_Solid(TTF_Font *font,const char *text, SDL_Color fg);
    extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderUTF8_Solid(TTF_Font *font,const char *text, SDL_Color fg);
    extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderUNICODE_Solid(TTF_Font *font, const Uint16 *text, SDL_Color fg);

    extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderGlyph_Solid(TTF_Font *font, Uint16 ch, SDL_Color fg);

    extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderText_Shaded(TTF_Font *font,const char *text, SDL_Color fg, SDL_Color bg);
    extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderUTF8_Shaded(TTF_Font *font,const char *text, SDL_Color fg, SDL_Color bg);
    extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderUNICODE_Shaded(TTF_Font *font,const Uint16 *text, SDL_Color fg, SDL_Color bg);

    extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderGlyph_Shaded(TTF_Font *font, Uint16 ch, SDL_Color fg, SDL_Color bg);

    extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderText_Blended(TTF_Font *font, const char *text, SDL_Color fg);
    extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderUTF8_Blended(TTF_Font *font,const char *text, SDL_Color fg);
    extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderUNICODE_Blended(TTF_Font *font, const Uint16 *text, SDL_Color fg);


    extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderText_Blended_Wrapped(TTF_Font *font,const char *text, SDL_Color fg, Uint32 wrapLength);
    extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderUTF8_Blended_Wrapped(TTF_Font *font,const char *text, SDL_Color fg, Uint32 wrapLength);
    extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderUNICODE_Blended_Wrapped(TTF_Font *font,const Uint16 *text, SDL_Color fg, Uint32 wrapLength);

    extern DECLSPEC SDL_Surface * SDLCALL TTF_RenderGlyph_Blended(TTF_Font *font, Uint16 ch, SDL_Color fg);
    */

    SDL_Surface *render_blended(const String &text, const Color &color);

    void load(const String &file_name, const int ptsize, const int index = -1);
    void free();

	Font();
    Font(const String &file_name, const int ptsize, const int index = -1);
    ~Font();

private:
	TTF_Font *_font;
};

#endif