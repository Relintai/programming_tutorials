#include "main_scene.h"

#include "rect2.h"
#include "renderer.h"

#include <SDL.h>

#include <stdio.h>

void MainScene::event(const SDL_Event &ev) {
	b1->event(ev);
	b2->event(ev);
	b3->event(ev);
}

void MainScene::update(float delta) {
}

void MainScene::render() {
	Renderer::get_singleton()->clear();

	_camera->bind();

	b1->render();
	b2->render();
	b3->render();
}

void MainScene::on_first_button_clicked() {
	printf("Click!\n");
}

void MainScene::on_first_button_clicked_member(void* cls) {
	if (cls) {
		reinterpret_cast<MainScene*>(cls)->member_print();
	}
}
void MainScene::member_print() {
	printf("Click Member!\n");
}

MainScene::MainScene() {
	_camera = new Camera();
	_image = new Image("ti.bmp");
	_texture = new Texture(_image);

	b1 = new Button();
	b1->transform = Rect2(0, 0, 100, 100);
	b1->up = new Sprite(_texture);
	b1->down = new Sprite(_texture, Color(100, 100, 100));
	b1->hover = new Sprite(_texture, Color(200, 200, 200));
	b1->on_click = MainScene::on_first_button_clicked;

	b2 = new Button();
	b2->transform = Rect2(0, 110, 100, 100);
	b2->off = new Sprite(_texture, Color(50, 50, 50));
	b2->state = Button::BUTTON_STATE_OFF;

	b3 = new Button();
	b3->transform = Rect2(0, 220, 100, 100);
	b3->up = new Sprite(_texture);
	b3->down = new Sprite(_texture, Color(100, 100, 100));
	b3->hover = new Sprite(_texture, Color(200, 200, 200));
	b3->cls = this;
	b3->on_click_member = MainScene::on_first_button_clicked_member;
}

MainScene::~MainScene() {
	_texture->free();
	_image->free();

	delete b1->up;
	delete b1->down;
	delete b1->hover;
	delete b1;

	delete b2->off;
	delete b2;

	delete b3->up;
	delete b3->down;
	delete b3->hover;
	delete b3;

	delete _texture;
	delete _image;
	delete _camera;
}
