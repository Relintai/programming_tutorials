#include "game_scene.h"

void GameScene::event(const SDL_Event &ev) {
}

void GameScene::update(float delta) {
}

void GameScene::render() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	camera->bind();
	mesh_instace->render();
}

GameScene::GameScene() {
	camera = new PerspectiveCamera();
	camera->position.z = -2;

	texture = new Texture();
	texture->load_image("download.bmp");

	material = new TextureMaterial();
	material->texture = texture;

	mesh = new Mesh();

	mesh->add_uv(0, 0);
	mesh->add_vertex3(-0.5, 0.5, 0);
	mesh->add_uv(1, 1);
	mesh->add_vertex3(0.5, -0.5, 0);
	mesh->add_uv(0, 1);
	mesh->add_vertex3(-0.5, -0.5, 0);
	mesh->add_uv(1, 0);
	mesh->add_vertex3(0.5, 0.5, 0);

	mesh->add_triangle(0, 1, 2);
	mesh->add_triangle(0, 1, 3);

	mesh->upload();

	mesh_instace = new MeshInstance();

	mesh_instace->material = material;
	mesh_instace->mesh = mesh;
}

GameScene::~GameScene() {
    delete camera;
    delete texture;
    delete material;
    delete mesh;
    delete mesh_instace;
}
