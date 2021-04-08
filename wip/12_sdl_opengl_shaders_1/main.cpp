#include <stdio.h>

#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>

#ifdef __unix__
#define GL_GLEXT_PROTOTYPES
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

bool shader_init = false;

GLuint vertex_shader;
GLuint fragment_shader;
GLuint shader_program;

void first_2d_triangle() {
    if (!shader_init) {
        shader_init = true;

        shader_program = glCreateProgram();

        vertex_shader = glCreateShader(GL_VERTEX_SHADER);

        const GLchar *vertex_shader_source[] = {
            "void main() { gl_Position = gl_Vertex; }"
        };

        glShaderSource(vertex_shader, 1, vertex_shader_source, NULL);
        glCompileShader(vertex_shader);
        glAttachShader(shader_program, vertex_shader);

        fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

        const GLchar *fragment_shader_source[] = {
            "void main() { gl_FragColor = vec4(1, 1, 0, 1); }"
        };

        glShaderSource(fragment_shader, 1, fragment_shader_source, NULL);
        glCompileShader(fragment_shader);
        glAttachShader(shader_program, fragment_shader);

        glLinkProgram(shader_program);
    }

    glUseProgram(shader_program);

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

GLint tri_color_uniform_location;
float color_count = 0;
void first_2d_triangle_uniforms() {
    if (!shader_init) {
        shader_init = true;

        shader_program = glCreateProgram();

        vertex_shader = glCreateShader(GL_VERTEX_SHADER);

        const GLchar *vertex_shader_source[] = {
            "void main() { gl_Position = gl_Vertex; }"
        };

        glShaderSource(vertex_shader, 1, vertex_shader_source, NULL);
        glCompileShader(vertex_shader);
        glAttachShader(shader_program, vertex_shader);

        fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

        const GLchar *fragment_shader_source[] = {
            "uniform vec4 fragment_color = vec4(1, 1, 1, 1);"
            ""
            "void main() { gl_FragColor = fragment_color; }"
        };

        glShaderSource(fragment_shader, 1, fragment_shader_source, NULL);
        glCompileShader(fragment_shader);
        glAttachShader(shader_program, fragment_shader);

        glLinkProgram(shader_program);

        //ha -1 akkor nem sikerült
        tri_color_uniform_location = glGetUniformLocation(shader_program, "fragment_color");
    }

    color_count += 0.01;

    if (color_count > 1)
        color_count = 0;

    glUseProgram(shader_program);
    glUniform4f(tri_color_uniform_location, color_count, 1, 1, 1 );

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

int current_demo = 1;

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

   if (shader_init) {
       printf("memleak\n");
   }

    SDL_DestroyWindow(window);

    window = nullptr;

    SDL_Quit();

    return 0;
}