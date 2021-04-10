#include "game_scene.h"

#include "application.h"

void GameScene::event(const SDL_Event &ev) {
	switch (ev.type) {
		case SDL_WINDOWEVENT: {
			switch (ev.window.event) {
				case SDL_WINDOWEVENT_SIZE_CHANGED: {
					int width = ev.window.data1;
					int height = ev.window.data2;

					float ar = static_cast<float>(width) / static_cast<float>(height);

					camera->width = camera->height * ar;

					glViewport(0, 0, width, height);

					break;
				}
			}

			break;
		}
	}
}

void GameScene::update(float delta) {
}

void GameScene::render() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	camera->bind();

	tile_map->render();

	//mesh_instace->render();
}

GameScene::GameScene() {
	camera = new OrthographicCamera();
	camera->width = 10;
	camera->height = 10;
	//camera->position.z = -2;

	int w;
	int h;
	SDL_GetWindowSize(Application::get_singleton()->window, &w, &h);

	float ar = static_cast<float>(w) / static_cast<float>(h);
	camera->width = camera->height * ar;

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

	tile_map = new TileMap();
	tile_map->material = material;
	tile_map->atlas_size_x = 16;
	tile_map->atlas_size_y = 16;

	tile_map->allocate_data();

	tile_map->set_data(0, 0, 2);
	tile_map->set_data(0, 1, 1);

	tile_map->build_mesh();
}

GameScene::~GameScene() {
	delete camera;
	delete texture;
	delete material;
	delete mesh;
	delete mesh_instace;
	delete tile_map;
}
