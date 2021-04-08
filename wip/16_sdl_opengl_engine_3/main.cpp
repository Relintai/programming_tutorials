#include <stdio.h>
#include <vector>

#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>

#include "opengl.h"

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

//lemaradt azt órán:
#include <math.h>

SDL_Window *window;
SDL_GLContext context;

bool running = true;

#include "colored_material.h"
#include "color_material.h"
#include "texture_material.h"
#include "mesh.h"
#include "mesh_instance.h"
#include "mesh_utils.h"
#include "texture.h"

ColoredMaterial *colored_material = nullptr;
ColorMaterial *color_material = nullptr;
TextureMaterial *texture_material = nullptr;
Texture *texture = nullptr;
Mesh *mesh = nullptr;
MeshInstance *mi = nullptr;
MeshInstance *mic = nullptr;

void first_2d_triangle() {
    if (!colored_material) {
        colored_material = new ColoredMaterial();
        colored_material->color.r = 0;
    }

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    colored_material->bind();

    //immediate mode
    glBegin(GL_TRIANGLES);
        glVertex2f(0.0, 0.5);
        glVertex2f(0.5, -0.5);
        glVertex2f(-0.5, -0.5);
    glEnd();

    SDL_GL_SwapWindow(window);
}

float color_count = 0;
void first_2d_triangle_uniforms() {
    if (!colored_material) {
        colored_material = new ColoredMaterial();
        colored_material->color.r = 0;
    }

    if (!mesh) {
        /*
        //2d
        mesh = new Mesh(2);

        mesh->add_vertex2(-0.5, 0.5);
        mesh->add_vertex2(0.5, -0.5);
        mesh->add_vertex2(-0.5, -0.5);
        mesh->add_vertex2(0.5, 0.5);

        mesh->add_triangle(0, 1, 2);
        mesh->add_triangle(0, 1, 3);

        */

        //3d
        mesh = new Mesh();

        mesh->add_vertex3(-0.5, 0.5, 0);
        mesh->add_vertex3(0.5, -0.5, 0);
        mesh->add_vertex3(-0.5, -0.5, 0);
        mesh->add_vertex3(0.5, 0.5, 0);

        mesh->add_triangle(0, 1, 2);
        mesh->add_triangle(0, 1, 3);

        mesh->upload();
    }

    color_count += 0.01;

    if (color_count > 1)
        color_count = 0;

    colored_material->color.r = color_count;

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    colored_material->bind();

    mesh->render();

    SDL_GL_SwapWindow(window);
}

void first_2d_triangle_uniforms_mi() {
    if (!colored_material) {
        colored_material = new ColoredMaterial();
        colored_material->color.r = 0;
    }

    if (!mesh) {
        mesh = new Mesh();

        mesh->add_vertex3(-0.5, 0.5, 0);
        mesh->add_vertex3(0.5, -0.5, 0);
        mesh->add_vertex3(-0.5, -0.5, 0);
        mesh->add_vertex3(0.5, 0.5, 0);

        mesh->add_triangle(0, 1, 2);
        mesh->add_triangle(0, 1, 3);

        mesh->upload();

        mi = new MeshInstance();

        mi->material = colored_material;
        mi->mesh = mesh;
    }

    color_count += 0.01;

    if (color_count > 1)
        color_count = 0;

    mi->position.x = color_count;
    mi->rotation.z = color_count * 100;
    mi->scale.x = color_count;

    colored_material->color.r = color_count;

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    mi->render();

    SDL_GL_SwapWindow(window);
}

void first_2d_triangle_uniforms_mi_children() {
    if (!colored_material) {
        colored_material = new ColoredMaterial();
        colored_material->color.r = 0;
    }

    if (!mesh) {
        mesh = new Mesh();

        mesh->add_vertex3(-0.5, 0.5, 0);
        mesh->add_vertex3(0.5, -0.5, 0);
        mesh->add_vertex3(-0.5, -0.5, 0);
        mesh->add_vertex3(0.5, 0.5, 0);

        mesh->add_triangle(0, 1, 2);
        mesh->add_triangle(0, 1, 3);

        mesh->upload();

        mi = new MeshInstance();

        mi->material = colored_material;
        mi->mesh = mesh;

        mic = new MeshInstance();

        mic->material = colored_material;
        mic->mesh = mesh;
        mic->scale = glm::vec3(0.8, 0.8, 0.8);
        //mic->position.x = 0.5;

        mi->children.push_back(mic);
    }

    color_count += 0.01;

    if (color_count > 1)
        color_count = 0;

    //mi->position.x = color_count;
    //mi->rotation.z = color_count * 100;
    //mi->scale.x = color_count;

    mi->position.x = color_count;
    mic->position.x = sin(color_count);
    mic->position.y = cos(color_count);

    colored_material->color.r = color_count;

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    mi->render();

    SDL_GL_SwapWindow(window);
}

void cone_perspective() {
    if (!color_material) {
        color_material = new ColorMaterial();
       // color_material->color.r = 0;
    }

    if (!mesh) {
        mesh = new Mesh();

        MeshUtils::create_cone(mesh);

        mesh->upload();

        mi = new MeshInstance();

        mi->material = color_material;
        mi->mesh = mesh;
    }

    color_count += 0.01;

    if (color_count > 3)
        color_count = 0;

   // mi->position.x = color_count;
   //mi->rotation.x = 210;
    mi->rotation.y = color_count * 100;
   // mi->scale.x = color_count;

   // color_material->color.r = color_count;

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glFrustum(-1, 1, -0.75, 0.75, 1, 10);
    glTranslatef(0, 0, -2);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    mi->render();

    SDL_GL_SwapWindow(window);
}

void first_2d_triangle_uvs() {
    if (!texture) {
        texture = new Texture();
        texture->load_image("download.bmp");
    }

    if (!texture_material) {
        texture_material = new TextureMaterial();
        texture_material->texture = texture;
    }

    if (!mesh) {
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

        mi = new MeshInstance();

        mi->material = texture_material;
        mi->mesh = mesh;
    }

    color_count += 0.01;

    if (color_count > 1)
        color_count = 0;

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    mi->render();

    SDL_GL_SwapWindow(window);
}

int current_demo = 5;

//gameloop
void handle_frame() {
    //handle input
    SDL_Event current_evevnt;

    while(SDL_PollEvent(&current_evevnt)) {
        if (current_evevnt.type == SDL_QUIT) {
            running = false;
        }
    }

    //update world
    //most ez nem kell

    //render
    switch (current_demo) {
        case 0:
            first_2d_triangle();
            break;
        case 1:
            first_2d_triangle_uniforms();
            break;
        case 2:
            first_2d_triangle_uniforms_mi();
            break;
        case 3:
            first_2d_triangle_uniforms_mi_children();
            break;
        case 4:
            cone_perspective();
            break;
        case 5:
            first_2d_triangle_uvs();
            break;
    }
}

int main(int argc, char *argv[]) {

    SDL_SetMainReady();
    int error = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

    if (error) {
        SDL_Log("SDL_Init: %s", SDL_GetError());

        return 1;
    }

    //Use OpenGl 2.1
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    window = SDL_CreateWindow("SDL + OpenGL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    if (!window) {
        SDL_Log("SDL_CreateWindow: %s", SDL_GetError());

        return 1;
    }

    context = SDL_GL_CreateContext(window);

    #ifdef _WIN64
    gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);
    #endif

    #ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(handle_frame, 0, 1);
    #else

    while (running) {
        handle_frame();
    }
    #endif

    printf("%s\n", glGetString(GL_VERSION));

    //if (vbo_init) {
   //     glDeleteBuffers(1, &triange_VBO);
   // }

   if (colored_material) {
       delete colored_material;
   }

    SDL_DestroyWindow(window);

    window = nullptr;

    SDL_Quit();

    return 0;
}