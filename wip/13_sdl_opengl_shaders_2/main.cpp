#include <stdio.h>
#include <vector>

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

GLint tri_position_uniform_location;
void first_2d_triangle_uniforms_moving() {
    if (!shader_init) {
        shader_init = true;

        shader_program = glCreateProgram();

        vertex_shader = glCreateShader(GL_VERTEX_SHADER);

        const GLchar *vertex_shader_source[] = {
            "#version 120\n"
            "uniform float positions_offset = 0;"
            "void main() { "
            "   vec4 p = gl_Vertex;"
            "   p.x += sin(positions_offset) * 0.5 * p.x;"
            "   p.y += cos(positions_offset) * 0.5 * p.y;"
            "   gl_Position = p;"
            "}"
        };

        glShaderSource(vertex_shader, 1, vertex_shader_source, NULL);
        glCompileShader(vertex_shader);
        glAttachShader(shader_program, vertex_shader);

        fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

        const GLchar *fragment_shader_source[] = {
            "void main() { gl_FragColor = vec4(1, 1, 1, 1); }"
        };

        glShaderSource(fragment_shader, 1, fragment_shader_source, NULL);
        glCompileShader(fragment_shader);
        glAttachShader(shader_program, fragment_shader);

        glLinkProgram(shader_program);

        //ha -1 akkor nem sikerült
        tri_position_uniform_location = glGetUniformLocation(shader_program, "positions_offset");
    }

    color_count += 0.01;

    glUseProgram(shader_program);
    glUniform1f(tri_position_uniform_location, color_count);

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


void first_2d_triangle_shader_errors() {
    if (!shader_init) {
        shader_init = true;

        shader_program = glCreateProgram();

        vertex_shader = glCreateShader(GL_VERTEX_SHADER);

        const GLchar *vertex_shader_source[] = {
            "#version 120\n"
            "uniform float positions_offset = 0;\n"
            "void main() { \n"
            "   gl_Position = gl_Verte;\n"
            "}"
        };

        glShaderSource(vertex_shader, 1, vertex_shader_source, NULL);
        glCompileShader(vertex_shader);
        glAttachShader(shader_program, vertex_shader);

        int max_length = 5000;
        std::vector<GLchar> error_log(max_length);
        glGetShaderInfoLog(vertex_shader, max_length, &max_length, &error_log[0]);
        printf("%s\n", &error_log[0]);

        fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

        const GLchar *fragment_shader_source[] = {
            "void main() { gl_FragColor = vec4(1, 0, 0, 1); }"
        };

        glShaderSource(fragment_shader, 1, fragment_shader_source, NULL);
        glCompileShader(fragment_shader);
        glAttachShader(shader_program, fragment_shader);

        glLinkProgram(shader_program);

        //ha -1 akkor nem sikerült
        tri_position_uniform_location = glGetUniformLocation(shader_program, "positions_offset");
    }

    color_count += 0.01;

    glUseProgram(shader_program);
    glUniform1f(tri_position_uniform_location, color_count);

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

void print_shader_error(GLuint shader) {
    int max_length = 5000;
    std::vector<GLchar> error_log(max_length);
    glGetShaderInfoLog(shader, max_length, &max_length, &error_log[0]);
    printf("%s\n", &error_log[0]);
}

void first_2d_triangle_error_checks() {
    if (!shader_init) {
        shader_init = true;

        shader_program = glCreateProgram();

        vertex_shader = glCreateShader(GL_VERTEX_SHADER);

        const GLchar *vertex_shader_source[] = {
            "void main() { gl_Position = gl_Verte; }"
        };

        glShaderSource(vertex_shader, 1, vertex_shader_source, NULL);
        glCompileShader(vertex_shader);

        GLint shader_compiled = GL_FALSE;
        glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &shader_compiled);
        if (shader_compiled != GL_TRUE) {
            printf("Unable to compile vertex shader!\n");
            print_shader_error(vertex_shader);
            return;
        }

        glAttachShader(shader_program, vertex_shader);

        fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

        const GLchar *fragment_shader_source[] = {
            "void main() { gl_FragColor = vec4(1, 1, 0, 1); }"
        };

        glShaderSource(fragment_shader, 1, fragment_shader_source, NULL);
        glCompileShader(fragment_shader);

        GLint fragment_shader_compiled = GL_FALSE;
        glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &fragment_shader_compiled);
        if (fragment_shader_compiled != GL_TRUE) {
            printf("Unable to compile vertex shader!\n");
            print_shader_error(fragment_shader);
            return;
        }

        glAttachShader(shader_program, fragment_shader);

        glLinkProgram(shader_program);

        GLint program_success = GL_TRUE;
        glGetProgramiv(shader_program, GL_LINK_STATUS, &program_success);
        if (program_success != GL_TRUE) {
            printf("Unable to link prigram!\n");
            print_shader_error(shader_program);
            return;
        }
    }

    glUseProgram(shader_program);

    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
        printf("glUseProgram error!\n");
        return;
    }

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

void first_2d_triangle_colors() {
    if (!shader_init) {
        shader_init = true;

        shader_program = glCreateProgram();

        vertex_shader = glCreateShader(GL_VERTEX_SHADER);

        const GLchar *vertex_shader_source[] = {
            "void main() { "
            "   gl_FrontColor = gl_Color;"
            "   gl_Position = gl_Vertex; "
            "}"
        };

        glShaderSource(vertex_shader, 1, vertex_shader_source, NULL);
        glCompileShader(vertex_shader);
        glAttachShader(shader_program, vertex_shader);

        fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

        const GLchar *fragment_shader_source[] = {
            "void main() { gl_FragColor = gl_Color; }"
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
        glColor3f(1, 0, 0);
        glVertex2f(0.0, 0.5);

        glColor3f(0, 1, 0);
        glVertex2f(0.5, -0.5);

        glColor3f(0, 0, 1);
        glVertex2f(-0.5, -0.5);
    glEnd();

    SDL_GL_SwapWindow(window);
}

float c3dc_rot = 0;
void first_3d_cone_perspective() {
    if (!shader_init) {
        shader_init = true;

        shader_program = glCreateProgram();

        vertex_shader = glCreateShader(GL_VERTEX_SHADER);

        const GLchar *vertex_shader_source[] = {
            "void main() { "
            "   gl_FrontColor = gl_Color;"
            //"   gl_Position = gl_Vertex; "
            "   gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex; "
            "}"
        };

        glShaderSource(vertex_shader, 1, vertex_shader_source, NULL);
        glCompileShader(vertex_shader);
        glAttachShader(shader_program, vertex_shader);

        fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

        const GLchar *fragment_shader_source[] = {
            "void main() { gl_FragColor = gl_Color; }"
        };

        glShaderSource(fragment_shader, 1, fragment_shader_source, NULL);
        glCompileShader(fragment_shader);
        glAttachShader(shader_program, fragment_shader);

        glLinkProgram(shader_program);
    }

    glUseProgram(shader_program);


    c3dc_rot += 1;

    //Ebben a példában a +z jön a kamera fele (alapbeállítás)

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //glFrustum(-1, 1, -1, 1, 1, 10);

    glFrustum(-1, 1, -0.75, 0.75, 1, 10);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0, 0, -2);
    glRotatef(c3dc_rot, 0, 1, 0);

    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);


    glBegin(GL_TRIANGLES);

    //eleje
    glColor3f(1, 0, 0);
    glVertex3f(0, 0.5, 0);

    glColor3f(1,0,0);
    glVertex3f(-0.5, -0.5, 0.5);

    glColor3f(1, 0, 0);
    glVertex3f(0.5, -0.5, 0.5);

    //bal
    glColor3f(0, 1, 0);
    glVertex3f(0, 0.5, 0);

    glColor3f(0, 1, 0);
    glVertex3f(-0.5, -0.5, -0.5);

    glColor3f(0, 1, 0);
    glVertex3f(-0.5, -0.5, 0.5);

    //jobb
    glColor3f(0, 0, 1);
    glVertex3f(0, 0.5, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0.5, -0.5, 0.5);

    glColor3f(0, 0, 1);
    glVertex3f(0.5, -0.5, -0.5);

    //hátulja
    glColor3f(1, 1, 0);
    glVertex3f(0, 0.5, 0);

    glColor3f(1, 1, 0);
    glVertex3f(0.5, -0.5, -0.5);

    glColor3f(1, 1, 0);
    glVertex3f(-0.5, -0.5, -0.5);

    glEnd();

    SDL_GL_SwapWindow(window);
}

bool texture_loaded = false;
GLuint texture;
void loadGLTextures(const char *file_name) {
    if (texture_loaded)
        return;

    texture_loaded = true;

    SDL_Surface *texture_image;
    texture_image = SDL_LoadBMP(file_name);

    if (!texture_image) {
        printf("Couldn't load %s.\n", file_name);
    } else {

        glGenTextures(1, &texture);

        glBindTexture(GL_TEXTURE_2D, texture);

        glTexImage2D(GL_TEXTURE_2D, 0, 3, texture_image->w, texture_image->h, 0, GL_RGB, GL_UNSIGNED_BYTE, texture_image->pixels);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        //(bi)linear filtering
        //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        SDL_FreeSurface(texture_image);
    }
}

void first_2d_triangle_uv() {
    loadGLTextures("img_forest.bmp");

    if (!shader_init) {
        shader_init = true;

        shader_program = glCreateProgram();

        vertex_shader = glCreateShader(GL_VERTEX_SHADER);

        const GLchar *vertex_shader_source[] = {
            "void main() { "
            "   gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex; "
            "}"
        };

        glShaderSource(vertex_shader, 1, vertex_shader_source, NULL);
        glCompileShader(vertex_shader);
        glAttachShader(shader_program, vertex_shader);

        fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

        const GLchar *fragment_shader_source[] = {
            "uniform sampler2D image;"
            "void main() {"
            "   gl_FragColor = texture(image, gl_MultiTexCoord0); "
            "}"
        };

        glShaderSource(fragment_shader, 1, fragment_shader_source, NULL);
        glCompileShader(fragment_shader);
        glAttachShader(shader_program, fragment_shader);

        glLinkProgram(shader_program);
    }

    glUseProgram(shader_program);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_TEXTURE_2D);

    //glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    //glUniform1i(glGetUniformLocation(fragment_shader, "image"), 0);

    //immediate mode
    glBegin(GL_TRIANGLES);
        glTexCoord2f(0.5, 0);
        glVertex2f(0.0, 0.5);

        glTexCoord2f(1, 1);
        glVertex2f(0.5, -0.5);

        glTexCoord2f(0, 1);
        glVertex2f(-0.5, -0.5);
    glEnd();

    SDL_GL_SwapWindow(window);
}

void first_2d_triangle_uv_varying() {
    loadGLTextures("img_forest.bmp");

    if (!shader_init) {
        shader_init = true;

        shader_program = glCreateProgram();

        vertex_shader = glCreateShader(GL_VERTEX_SHADER);

        const GLchar *vertex_shader_source[] = {
            "varying vec4 v_uv;"
            "void main() { "
            "   v_uv = gl_MultiTexCoord0;"
            "   gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex; "
            "}"
        };

        glShaderSource(vertex_shader, 1, vertex_shader_source, NULL);
        glCompileShader(vertex_shader);
        glAttachShader(shader_program, vertex_shader);

        fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

        const GLchar *fragment_shader_source[] = {
            "uniform sampler2D image;"
            "varying vec4 v_uv;"
            "void main() {"
            "   gl_FragColor = texture(image, v_uv); "
            "}"
        };

        glShaderSource(fragment_shader, 1, fragment_shader_source, NULL);
        glCompileShader(fragment_shader);
        glAttachShader(shader_program, fragment_shader);

        glLinkProgram(shader_program);
    }

    glUseProgram(shader_program);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_TEXTURE_2D);

    //glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    //glUniform1i(glGetUniformLocation(fragment_shader, "image"), 0);

    //immediate mode
    glBegin(GL_TRIANGLES);
        glTexCoord2f(0.5, 0);
        glVertex2f(0.0, 0.5);

        glTexCoord2f(1, 1);
        glVertex2f(0.5, -0.5);

        glTexCoord2f(0, 1);
        glVertex2f(-0.5, -0.5);
    glEnd();

    SDL_GL_SwapWindow(window);
}

GLint uniform_water_uv_offset;
float uv_offset = 0;
void first_2d_triangle_uv_varying_water() {
    loadGLTextures("img_forest.bmp");

    if (!shader_init) {
        shader_init = true;

        shader_program = glCreateProgram();

        vertex_shader = glCreateShader(GL_VERTEX_SHADER);

        const GLchar *vertex_shader_source[] = {
            "#version 120\n"
            "uniform float position_offset = 0;\n"
            "varying vec4 v_uv;\n"
            "void main() { \n"
            "   vec4 uvcoords = gl_MultiTexCoord0;\n"
            "   uvcoords.y -= position_offset;\n"
            "   v_uv = uvcoords;\n"
            "   gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;\n"
            "}"
        };

        glShaderSource(vertex_shader, 1, vertex_shader_source, NULL);
        glCompileShader(vertex_shader);

        print_shader_error(vertex_shader);

        glAttachShader(shader_program, vertex_shader);

        fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

        const GLchar *fragment_shader_source[] = {
            "uniform sampler2D image;"
            "varying vec4 v_uv;"
            "void main() {"
            "   gl_FragColor = texture(image, v_uv); "
            "}"
        };

        glShaderSource(fragment_shader, 1, fragment_shader_source, NULL);
        glCompileShader(fragment_shader);
        glAttachShader(shader_program, fragment_shader);

        glLinkProgram(shader_program);

        uniform_water_uv_offset = glGetUniformLocation(shader_program, "position_offset");
    }

    uv_offset += 0.01;

    if (uv_offset > 1)
        uv_offset = 0;

    glUseProgram(shader_program);
    glUniform1f(uniform_water_uv_offset, uv_offset);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_TEXTURE_2D);

    //glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    //glUniform1i(glGetUniformLocation(fragment_shader, "image"), 0);

    //immediate mode
    glBegin(GL_TRIANGLES);
        glTexCoord2f(0, 0);
        glVertex2f(-0.5, 0.5);

        glTexCoord2f(1, 1);
        glVertex2f(0.5, -0.5);

        glTexCoord2f(0, 1);
        glVertex2f(-0.5, -0.5);

        glTexCoord2f(0, 0);
        glVertex2f(-0.5, 0.5);

        glTexCoord2f(1, 1);
        glVertex2f(0.5, -0.5);

        glTexCoord2f(1, 0);
        glVertex2f(0.5, 0.5);
    glEnd();

    SDL_GL_SwapWindow(window);
}

GLint uniform_grass_offset;
float grass_displace = 0.5;
float grass_displace_val = 0.03;
void grass() {
    loadGLTextures("grass.bmp");

    if (!shader_init) {
        shader_init = true;

        shader_program = glCreateProgram();

        vertex_shader = glCreateShader(GL_VERTEX_SHADER);

        //cv.rgba
        //cv.ra
        //cv.rga
        //cv.yz
        //...
        //vec3 * cv.rgb
        //stpq

        const GLchar *vertex_shader_source[] = {
            "#version 120\n"
            "uniform float position_offset = 0;\n"
            "varying vec4 v_uv;\n"
            "void main() { \n"
            "   vec4 cv = gl_Color;"
            "   cv.xyz *= position_offset;"
            "   vec4 v = cv + gl_Vertex;"
            "   v_uv = gl_MultiTexCoord0;"
            "   gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * v;\n"
            "}"
        };

        glShaderSource(vertex_shader, 1, vertex_shader_source, NULL);
        glCompileShader(vertex_shader);

        print_shader_error(vertex_shader);

        glAttachShader(shader_program, vertex_shader);

        fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

        const GLchar *fragment_shader_source[] = {
            "uniform sampler2D image;"
            "varying vec4 v_uv;"
            "void main() {"
            "   gl_FragColor = texture(image, v_uv); "
            "}"
        };

        glShaderSource(fragment_shader, 1, fragment_shader_source, NULL);
        glCompileShader(fragment_shader);
        glAttachShader(shader_program, fragment_shader);

        glLinkProgram(shader_program);

        uniform_grass_offset = glGetUniformLocation(shader_program, "position_offset");
    }

    grass_displace += grass_displace_val;

    if (grass_displace > 0.5)
        grass_displace_val = -grass_displace_val;

    if (grass_displace < -0.5)
        grass_displace_val = -grass_displace_val;

    glUseProgram(shader_program);
    glUniform1f(uniform_grass_offset, grass_displace);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_TEXTURE_2D);

    //glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    //glUniform1i(glGetUniformLocation(fragment_shader, "image"), 0);

    //immediate mode
    glBegin(GL_TRIANGLES);
        glColor3f(0.3, 0.01, 0);
        glTexCoord2f(0, 0);
        glVertex2f(-0.5, 0.5);

        glColor3f(0, 0, 0);
        glTexCoord2f(1, 1);
        glVertex2f(0.5, -0.5);

        glColor3f(0, 0, 0);
        glTexCoord2f(0, 1);
        glVertex2f(-0.5, -0.5);

        glColor3f(0.3, 0.01, 0);
        glTexCoord2f(0, 0);
        glVertex2f(-0.5, 0.5);

        glColor3f(0, 0, 0);
        glTexCoord2f(1, 1);
        glVertex2f(0.5, -0.5);

        glColor3f(0.3, 0.01, 0);
        glTexCoord2f(1, 0);
        glVertex2f(0.5, 0.5);
    glEnd();

    SDL_GL_SwapWindow(window);
}

int current_demo = 10;

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
            first_2d_triangle_uniforms_moving();
            break;
        case 3:
            first_2d_triangle_shader_errors();
            break;
        case 4:
            first_2d_triangle_error_checks();
            break;
        case 5:
            first_2d_triangle_colors();
            break;
        case 6:
            first_3d_cone_perspective();
            break;
        case 7:
            first_2d_triangle_uv();
            break;
        case 8:
            first_2d_triangle_uv_varying();
            break;
        case 9:
            first_2d_triangle_uv_varying_water();
            break;
        case 10:
            grass();
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