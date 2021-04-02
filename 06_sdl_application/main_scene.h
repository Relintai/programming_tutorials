#ifndef MAIN_SCENE_H
#define MAIN_SCENE_H

#include "scene.h"

#include "image.h"
#include "texture.h"
#include "sprite.h"

class MainScene : public Scene {
public:
	void event(const SDL_Event &ev);
	void update(float delta);
	void render();

	MainScene();
	~MainScene();

	Image *_image;
	Texture *_texture;
	Sprite *_sprite;
};

#endif