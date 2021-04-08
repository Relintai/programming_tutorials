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

void first_3d_triangle() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);

    glVertex3f(0, 0.5, 0);
    glVertex3f(0.5, -0.5, 0);
    glVertex3f(-0.5, -0.5, 0);

    glEnd();

    SDL_GL_SwapWindow(window);
}

void first_3d_triangle_color() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0.5, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0.5, -0.5, 0);

    glColor3f(0,0,1);
    glVertex3f(-0.5, -0.5, 0);

    glEnd();

    SDL_GL_SwapWindow(window);
}

float c3dc_rot = 0;
void first_3d_triangle_color_rotated() {
    c3dc_rot += 1;

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.5, 0, 0);
    glRotatef(c3dc_rot, 0, 1, 0);
   
    glBegin(GL_TRIANGLES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0.5, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0.5, -0.5, 0);

    glColor3f(0,0,1);
    glVertex3f(-0.5, -0.5, 0);

    glEnd();

    SDL_GL_SwapWindow(window);
}

void first_3d_triangle_color_rotated_face_culling() {
    c3dc_rot += 1;

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(c3dc_rot, 0, 1, 0);

    glEnable(GL_CULL_FACE);

    //alap
    //glCullFace(GL_BACK);
    //glCullFace(GL_FRONT);
    //glCullFace(GL_FRONT_AND_BACK);

    //Winding order
    //alap:
    //glFrontFace(GL_CCW);

    //glFrontFace(GL_CW);
   
    glBegin(GL_TRIANGLES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0.5, 0);

    glColor3f(0,0,1);
    glVertex3f(-0.5, -0.5, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0.5, -0.5, 0);

    glEnd();

    SDL_GL_SwapWindow(window);
}

void first_3d_cone() {
    c3dc_rot += 1;

    //Ebben a példában a -z jön a kamera fele (alapbeállítás)

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(c3dc_rot, 0, 1, 0);

    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);


    glBegin(GL_TRIANGLES);

    //eleje
    glColor3f(1, 0, 0);
    glVertex3f(0, 0.5, 0);

    glColor3f(1,0,0);
    glVertex3f(-0.5, -0.5, -0.5);

    glColor3f(1, 0, 0);
    glVertex3f(0.5, -0.5, -0.5);

    //bal
    glColor3f(0, 1, 0);
    glVertex3f(0, 0.5, 0);

    glColor3f(0, 1, 0);
    glVertex3f(-0.5, -0.5, 0.5);

    glColor3f(0, 1, 0);
    glVertex3f(-0.5, -0.5, -0.5);

    //jobb
    glColor3f(0, 0, 1);
    glVertex3f(0, 0.5, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0.5, -0.5, -0.5);

    glColor3f(0, 0, 1);
    glVertex3f(0.5, -0.5, 0.5);

    //hátulja
    glColor3f(1, 1, 0);
    glVertex3f(0, 0.5, 0);

    glColor3f(1, 1, 0);
    glVertex3f(0.5, -0.5, 0.5);

    glColor3f(1, 1, 0);
    glVertex3f(-0.5, -0.5, 0.5);

    glEnd();

    SDL_GL_SwapWindow(window);
}

void first_3d_cone_ortho() {
    c3dc_rot += 1;

    //Ebben a példában a -z jön a kamera fele (alapbeállítás)

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //alapbeállítás:
    //glOrtho(-1, 1, -1, 1, 1, -1);

   // glOrtho(-2, 2, -1, 1, 1, -1);
   // glOrtho(-1, 1, -2, 2, 1, -1);

    //glOrtho(-1, 1, -0.75, 0.75, 1, -1);

    //glTranslatef(0, 1, 0);
    //glTranslatef(1, 0, 0);
    glOrtho(-1.33, 1.33, -1, 1, 1, -1);
    
    //glOrtho(-1.33, 1.33, -1, 1, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(c3dc_rot, 0, 1, 0);

    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);


    glBegin(GL_TRIANGLES);

    //eleje
    glColor3f(1, 0, 0);
    glVertex3f(0, 0.5, 0);

    glColor3f(1,0,0);
    glVertex3f(-0.5, -0.5, -0.5);

    glColor3f(1, 0, 0);
    glVertex3f(0.5, -0.5, -0.5);

    //bal
    glColor3f(0, 1, 0);
    glVertex3f(0, 0.5, 0);

    glColor3f(0, 1, 0);
    glVertex3f(-0.5, -0.5, 0.5);

    glColor3f(0, 1, 0);
    glVertex3f(-0.5, -0.5, -0.5);

    //jobb
    glColor3f(0, 0, 1);
    glVertex3f(0, 0.5, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0.5, -0.5, -0.5);

    glColor3f(0, 0, 1);
    glVertex3f(0.5, -0.5, 0.5);

    //hátulja
    glColor3f(1, 1, 0);
    glVertex3f(0, 0.5, 0);

    glColor3f(1, 1, 0);
    glVertex3f(0.5, -0.5, 0.5);

    glColor3f(1, 1, 0);
    glVertex3f(-0.5, -0.5, 0.5);

    glEnd();

    SDL_GL_SwapWindow(window);
}

void first_3d_cone_perspective() {
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

float box_tris_rot = 0;
bool box_tris_rot_dir = false;
void box_tris() {
    if (box_tris_rot_dir)
        box_tris_rot += 0.5;
    else
        box_tris_rot -= 0.5;

    if (box_tris_rot > 90 || box_tris_rot < 0)
        box_tris_rot_dir = !box_tris_rot_dir;

    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //glFrustum(-1, 1, -0.75, 0.75, 1, 10);
    glTranslatef(0, 0.1, 0);
    glOrtho(-2, 2, -1.5, 1.5, -10, 10);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //glTranslatef(0, 0, -2);
    glRotatef(30, 1, 0, 0);
    glRotatef(box_tris_rot, 0, 1, 0);

    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);

    glBegin(GL_TRIANGLES);

        glColor3f(1, 0, 0);

        glVertex3f(-0.5, 0.5, 0.5);
        glVertex3f(-0.5, -0.5, 0.5);
        glVertex3f(0.5, -0.5, 0.5);

        glColor3f(0.5, 0, 0);

        glVertex3f(0.5, -0.5, 0.5);
        glVertex3f(0.5, 0.5, 0.5);
        glVertex3f(-0.5, 0.5, 0.5);

        glColor3f(0, 1, 0);

        glVertex3f(-0.5, 0.5, -0.5);
        glVertex3f(-0.5, -0.5, -0.5);
        glVertex3f(-0.5, 0.5, 0.5);

        glColor3f(0, 0.5, 0);

        glVertex3f(-0.5, 0.5, 0.5);
        glVertex3f(-0.5, -0.5, -0.5);
        glVertex3f(-0.5, -0.5, 0.5);

    glEnd();

    SDL_GL_SwapWindow(window);
}

void box_tris_lights() {
    if (box_tris_rot_dir)
        box_tris_rot += 0.5;
    else
        box_tris_rot -= 0.5;

    if (box_tris_rot > 90 || box_tris_rot < 0)
        box_tris_rot_dir = !box_tris_rot_dir;

    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_LIGHTING);

    glEnable(GL_LIGHT0);

    float light1_ambient[] = { 0, 0, 0, 1 };
    float light1_diffuse[] = { 1, 1, 1, 1 };
    float light1_specular[] = { 1, 1, 1, 1 };
    float light1_pos[] = { -0.5, 1, 2 };

    glLightfv(GL_LIGHT0, GL_AMBIENT, light1_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light1_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light1_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light1_pos);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //glFrustum(-1, 1, -0.75, 0.75, 1, 10);
    glTranslatef(0, 0.1, 0);
    glOrtho(-2, 2, -1.5, 1.5, -10, 10);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //glTranslatef(0, 0, -2);
    glRotatef(30, 1, 0, 0);
    glRotatef(box_tris_rot, 0, 1, 0);

    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);

    glBegin(GL_TRIANGLES);

        glColor3f(1, 0, 0);

        glNormal3f(0, 0, 1);
        glVertex3f(-0.5, 0.5, 0.5);
        glNormal3f(0, 0, 1);
        glVertex3f(-0.5, -0.5, 0.5);
        glNormal3f(0, 0, 1);
        glVertex3f(0.5, -0.5, 0.5);

        glColor3f(0.5, 0, 0);

        glNormal3f(0, 0, 1);
        glVertex3f(0.5, -0.5, 0.5);
        glNormal3f(0, 0, 1);
        glVertex3f(0.5, 0.5, 0.5);
        glNormal3f(0, 0, 1);
        glVertex3f(-0.5, 0.5, 0.5);

        glColor3f(0, 1, 0);

        glNormal3f(-1, 0, 0);
        glVertex3f(-0.5, 0.5, -0.5);
        glNormal3f(-1, 0, 0);
        glVertex3f(-0.5, -0.5, -0.5);
        glNormal3f(-1, 0, 0);
        glVertex3f(-0.5, 0.5, 0.5);

        glColor3f(0, 0.5, 0);

        glNormal3f(-1, 0, 0);
        glVertex3f(-0.5, 0.5, 0.5);
        glNormal3f(-1, 0, 0);
        glVertex3f(-0.5, -0.5, -0.5);
        glNormal3f(-1, 0, 0);
        glVertex3f(-0.5, -0.5, 0.5);

    glEnd();

    SDL_GL_SwapWindow(window);
}

int current_demo = 12;

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
        case 4:
            first_3d_triangle();
            break;
        case 5:
            first_3d_triangle_color();
            break;
        case 6:
            first_3d_triangle_color_rotated();
            break;
        case 7:
            first_3d_triangle_color_rotated_face_culling();
            break;
        case 8:
            first_3d_cone();
            break;
        case 9:
            first_3d_cone_ortho();
            break;
        case 10:
            first_3d_cone_perspective();
            break;
        case 11:
            box_tris();
            break;
        case 12:
            box_tris_lights();
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