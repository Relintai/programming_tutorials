#include "main_scene.h"

#include "core/rect2.h"
#include "renderer/renderer.h"

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

	_ts->draw();
}

MainScene::MainScene() {
	_camera = new Camera();
	_image = new Image("ti.bmp");
	_texture = new Texture(_image);
	_font = new TrueTypeFont("./DejaVuSans.ttf", 36);
	_ii = _font->render_text_blended("Adsdsda", Color(255, 0, 0, 255));
	_iit = new Texture(_ii);
	_s = new Sprite(_iit);

	_teximg = new TextImage(_font, "daDAdadad");
	_iit2 = new Texture(_teximg->get_image());
	_s2 = new Sprite(_iit2);

	_ts = new TextSprite(_font, "Aqqqqqqq", Color(255, 0, 0));
	_ts->set_y(50);

	b1 = new Button();
	b1->transform = Rect2(0, 0, 100, 100);
	b1->up = new Sprite(_texture);
	b1->down = new Sprite(_texture, Color(100, 100, 100));
	b1->hover = new Sprite(_texture, Color(200, 200, 200));

	//b1->on_click = [this]() -> void { this->member_print(); };

	b2 = new Button();
	b2->transform = Rect2(0, 110, 100, 100);
	b2->off = new Sprite(_texture, Color(50, 50, 50));
	b2->state = Button::BUTTON_STATE_OFF;

	b3 = new Button();
	b3->transform = Rect2(0, 220, 100, 100);
	b3->up = new Sprite(_texture);
	b3->down = new Sprite(_texture, Color(100, 100, 100));
	b3->hover = new Sprite(_texture, Color(200, 200, 200));
}

MainScene::~MainScene() {
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

	delete _s;
	delete _iit;
	delete _ii;

	delete _teximg;
	delete _s2;
	delete _iit2;

	delete _ts;

	delete _font;
	delete _texture;
	delete _image;
	delete _camera;
}
