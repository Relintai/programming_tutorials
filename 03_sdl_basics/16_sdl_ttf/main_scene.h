#ifndef MAIN_SCENE_H
#define MAIN_SCENE_H

#include "scene.h"

#include "image.h"
#include "texture.h"
#include "sprite.h"
#include "camera.h"
#include "button.h"
#include "font.h"

class MainScene : public Scene {
public:
	void event(const SDL_Event &ev);
	void update(float delta);
	void render();

	//ver a
	static void on_first_button_clicked();

	//ver b
	static void on_first_button_clicked_member(void* cls);
	void member_print();

	MainScene();
	~MainScene();

	Camera *_camera;
	Image *_image;
	Texture *_texture;
	Font *_font;
	Image *_ii;
	Texture *_iit;
	Sprite *_s;

	Button *b1;
	Button *b2;
	Button *b3;
};

#endif