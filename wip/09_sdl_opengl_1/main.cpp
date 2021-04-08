#include <stdio.h>

#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>

#ifdef __unix__
#include <GL/gl.h>
#endif

#ifdef _WIN64
#include <glad/glad.h>
#endif

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

SDL_Window *window;
SDL_GLContext context;

bool running = true;

void first_2d_triangle() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //immediate mode
    glBegin(GL_TRIANGLES);
        glVertex2f(0.0, 0.5);
        glVertex2f(0.5, -0.5);
        glVertex2f(-0.5, -0.5);
    glEnd();

    SDL_GL_SwapWindow(window);
}

void first_2d_triangle_colored() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //immediate mode
    glBegin(GL_TRIANGLES);
        glColor3f(1, 0, 0);
        glVertex2f(0.0, 0.5);

        glColor3f(0, 1, 0);
        glVertex2f(0.5, -0.5);

        glColor3f(0, 0, 1);
        glVertex2f(-0.5, -0.5);
    glEnd();

    SDL_GL_SwapWindow(window);
}

void first_2d_quad() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //immediate mode
    glBegin(GL_QUADS);
        glVertex2f(0.5, 0.5);
        glVertex2f(0.5, -0.5);
        glVertex2f(-0.5, -0.5);
        glVertex2f(-0.5, 0.5);
    glEnd();

    SDL_GL_SwapWindow(window);
}

void first_2d_quad_colored() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //immediate mode
    glBegin(GL_QUADS);
        glColor3f(1, 0, 0);
        glVertex2f(0.5, 0.5);

        glColor3f(0.5, 0.5, 0.5);
        glVertex2f(0.5, -0.5);

        glColor3f(0, 1, 0);
        glVertex2f(-0.5, -0.5);

        glColor3f(0, 0, 1);
        glVertex2f(-0.5, 0.5);
    glEnd();

    SDL_GL_SwapWindow(window);
}

int current_demo = 3;

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
            first_2d_triangle_colored();
            break;
        case 2:
            first_2d_quad();
            break;
        case 3:
            first_2d_quad_colored();
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

    SDL_DestroyWindow(window);

    window = nullptr;

    SDL_Quit();

    return 0;
}