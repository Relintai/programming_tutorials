#include "main_scene.h"

#include "renderer.h"


void MainScene::event(const SDL_Event &ev) {
}

void MainScene::update(float delta) {
}

void MainScene::render() {
	Renderer::get_singleton()->clear();

	_camera->viewport.x += _dir;

	if (_camera->viewport.x <= -100)
		_dir = 1;
	else if (_camera->viewport.x >= 100)
		_dir = -1;

	_camera->bind();

	_sprite->draw();
}

MainScene::MainScene() {
	_camera =  new Camera();
	_image = new Image("ti.bmp");
	_texture = new Texture(_image);
	_sprite = new Sprite(_texture);

	_sprite->set_x(30);
	_sprite->set_y(30);

	_dir = 1;
}

MainScene::~MainScene() {
	_texture->free();
	_image->free();

	delete _sprite;
	delete _texture;
	delete _image;
	delete _camera;
}
