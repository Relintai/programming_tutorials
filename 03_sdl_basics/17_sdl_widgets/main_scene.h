#ifndef MAIN_SCENE_H
#define MAIN_SCENE_H

#include "scene.h"

#include "image.h"
#include "texture.h"
#include "sprite.h"
#include "camera.h"
#include "button.h"
#include "true_type_font.h"
#include "text_image.h"
#include "text_sprite.h"

class MainScene : public Scene {
public:
	void event(const SDL_Event &ev);
	void update(float delta);
	void render();

	MainScene();
	~MainScene();

	Camera *_camera;
	Image *_image;
	Texture *_texture;
	TrueTypeFont *_font;
	Image *_ii;
	Texture *_iit;
	Texture *_iit2;
	Sprite *_s;
	Sprite *_s2;
	TextImage *_teximg;
	
	TextSprite *_ts;

	Button *b1;
	Button *b2;
	Button *b3;
};

#endif