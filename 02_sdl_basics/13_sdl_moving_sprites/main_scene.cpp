#include "main_scene.h"

#include "renderer.h"
#include "rect2.h"

#include <SDL.h>

void MainScene::event(const SDL_Event &ev) {
	switch (ev.type) {
		case SDL_WINDOWEVENT: {
			switch (ev.window.event) {
				case SDL_WINDOWEVENT_SIZE_CHANGED: {
					int width = ev.window.data1;
					int height = ev.window.data2;

					_camera->viewport = Rect2(0, 0, width, height);

					break;
				}
			}

			break;
		}
		case SDL_KEYDOWN: {

			if (ev.key.keysym.scancode == SDL_SCANCODE_A) {
				_left = true;
			} else if (ev.key.keysym.scancode == SDL_SCANCODE_W) {
				_up = true;
			} else if (ev.key.keysym.scancode == SDL_SCANCODE_S) {
				_down = true;
			} else if (ev.key.keysym.scancode == SDL_SCANCODE_D) {
				_right = true;
			}

			break;
		}
		case SDL_KEYUP: {

			if (ev.key.keysym.scancode == SDL_SCANCODE_A) {
				_left = false;
			} else if (ev.key.keysym.scancode == SDL_SCANCODE_W) {
				_up = false;
			} else if (ev.key.keysym.scancode == SDL_SCANCODE_S) {
				_down = false;
			} else if (ev.key.keysym.scancode == SDL_SCANCODE_D) {
				_right = false;
			}

			break;
		}
	}
}

void MainScene::update(float delta) {
	if (_up) {
		_sprite->set_y(_sprite->get_y() - 50 * delta);
	}

	if (_down) {
		_sprite->set_y(_sprite->get_y() + 50 * delta);
	}

	if (_left) {
		_sprite->set_x(_sprite->get_x() - 50 * delta);
	}

	if (_right) {
		_sprite->set_x(_sprite->get_x() + 50 * delta);
	}
}

void MainScene::render() {
	Renderer::get_singleton()->clear();

	_camera->bind();

	Renderer::get_singleton()->draw_sprite(_sprite);
}

MainScene::MainScene() {
	_camera = new Camera();
	_image = new Image("ti.bmp");
	_texture = new Texture(_image);
	_sprite = new Sprite(_texture);

    _up = false;
    _down = false;
	_left = false;
	_right = false;
}

MainScene::~MainScene() {
	_texture->free();
	_image->free();

	delete _sprite;
	delete _texture;
	delete _image;
	delete _camera;
}
