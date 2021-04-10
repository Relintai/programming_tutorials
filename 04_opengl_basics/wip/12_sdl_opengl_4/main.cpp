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
    float light1_pos[] = { -2, 1, 1 };

    glLightfv(GL_LIGHT0, GL_AMBIENT, light1_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light1_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light1_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light1_pos);

    glEnable(GL_LIGHT1);

    float light2_ambient[] = { 0, 0, 0, 1 };
    float light2_diffuse[] = { 1, 0, 0, 1 };
    float light2_specular[] = { 1, 1, 1, 1 };
    float light2_pos[] = { 1, 1, 2 };

    glLightfv(GL_LIGHT1, GL_AMBIENT, light2_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light2_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light2_specular);
    glLightfv(GL_LIGHT1, GL_POSITION, light2_pos);

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

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, texture);

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

void first_2d_triangle_quad_uv() {
    loadGLTextures("img_forest.bmp");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, texture);

    //immediate mode
    glBegin(GL_TRIANGLES);
        glTexCoord2f(0, 0);
        glVertex2f(-0.5, 0.5);

        glTexCoord2f(1, 1);
        glVertex2f(0.5, -0.5);

        glTexCoord2f(0, 1);
        glVertex2f(-0.5, -0.5);


        glTexCoord2f(1, 1);
        glVertex2f(0.5, -0.5);

        glTexCoord2f(0, 0);
        glVertex2f(-0.5, 0.5);

        glTexCoord2f(1, 0);
        glVertex2f(0.5, 0.5);
    glEnd();

    SDL_GL_SwapWindow(window);
}

void box_tris_lights_uv() {
    loadGLTextures("img_forest.bmp");

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
    float light1_pos[] = { -2, 1, 1 };

    glLightfv(GL_LIGHT0, GL_AMBIENT, light1_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light1_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light1_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light1_pos);

    glEnable(GL_LIGHT1);

    float light2_ambient[] = { 0, 0, 0, 1 };
    float light2_diffuse[] = { 1, 0, 0, 1 };
    float light2_specular[] = { 1, 1, 1, 1 };
    float light2_pos[] = { 1, 1, 2 };

    glLightfv(GL_LIGHT1, GL_AMBIENT, light2_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light2_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light2_specular);
    glLightfv(GL_LIGHT1, GL_POSITION, light2_pos);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);

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

        //glColor3f(1, 0, 0);
        glTexCoord2f(0, 0);
        glNormal3f(0, 0, 1);
        glVertex3f(-0.5, 0.5, 0.5);

        glTexCoord2f(0, 1);
        glNormal3f(0, 0, 1);
        glVertex3f(-0.5, -0.5, 0.5);

        glTexCoord2f(1, 1);
        glNormal3f(0, 0, 1);
        glVertex3f(0.5, -0.5, 0.5);

        //glColor3f(0.5, 0, 0);
        glTexCoord2f(1, 1);
        glNormal3f(0, 0, 1);
        glVertex3f(0.5, -0.5, 0.5);

        glTexCoord2f(1, 0);
        glNormal3f(0, 0, 1);
        glVertex3f(0.5, 0.5, 0.5);

        glTexCoord2f(0, 0);
        glNormal3f(0, 0, 1);
        glVertex3f(-0.5, 0.5, 0.5);

        //glColor3f(0, 1, 0);
        glTexCoord2f(0, 0);
        glNormal3f(-1, 0, 0);
        glVertex3f(-0.5, 0.5, -0.5);

        glTexCoord2f(0, 1);
        glNormal3f(-1, 0, 0);
        glVertex3f(-0.5, -0.5, -0.5);

        glTexCoord2f(1, 0);
        glNormal3f(-1, 0, 0);
        glVertex3f(-0.5, 0.5, 0.5);

       // glColor3f(0, 0.5, 0);
        glTexCoord2f(1, 0);
        glNormal3f(-1, 0, 0);
        glVertex3f(-0.5, 0.5, 0.5);

        glTexCoord2f(0, 1);
        glNormal3f(-1, 0, 0);
        glVertex3f(-0.5, -0.5, -0.5);

        glTexCoord2f(1, 1);
        glNormal3f(-1, 0, 0);
        glVertex3f(-0.5, -0.5, 0.5);

    glEnd();

    SDL_GL_SwapWindow(window);
}


#define ATLAS_SIZE_X 16.0
#define ATLAS_SIZE_Y 16.0
void add_tex_coord(int atlas_coord_x, int atlas_coord_y, float uv_x, float uv_y) {
    float tile_size_x = 1.0 / ATLAS_SIZE_X;
    float tile_size_y = 1.0 / ATLAS_SIZE_Y;

    float pos_x = tile_size_x * atlas_coord_x;
    float pos_y = tile_size_y * atlas_coord_y;

    float offset_x = uv_x * tile_size_x;
    float offset_y = uv_y * tile_size_y;

    glTexCoord2f(pos_x + offset_x, pos_y + offset_y);
}

void box_tris_lights_uv_texture_atlas() {
    loadGLTextures("download.bmp");

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
    float light1_pos[] = { -2, 1, 1 };

    glLightfv(GL_LIGHT0, GL_AMBIENT, light1_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light1_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light1_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light1_pos);

    glEnable(GL_LIGHT1);

    float light2_ambient[] = { 0, 0, 0, 1 };
    float light2_diffuse[] = { 1, 0, 0, 1 };
    float light2_specular[] = { 1, 1, 1, 1 };
    float light2_pos[] = { 1, 1, 2 };

    glLightfv(GL_LIGHT1, GL_AMBIENT, light2_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light2_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light2_specular);
    glLightfv(GL_LIGHT1, GL_POSITION, light2_pos);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);

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

    int atlas_coord_1_x = 3;
    int atlas_coord_1_y = 3;

    int atlas_coord_2_x = 2;
    int atlas_coord_2_y = 3;

    glBegin(GL_TRIANGLES);

        //glColor3f(1, 0, 0);
        add_tex_coord(atlas_coord_1_x, atlas_coord_1_y, 0, 0);
        glNormal3f(0, 0, 1);
        glVertex3f(-0.5, 0.5, 0.5);

        add_tex_coord(atlas_coord_1_x, atlas_coord_1_y, 0, 1);
        glNormal3f(0, 0, 1);
        glVertex3f(-0.5, -0.5, 0.5);

        add_tex_coord(atlas_coord_1_x, atlas_coord_1_y, 1, 1);
        glNormal3f(0, 0, 1);
        glVertex3f(0.5, -0.5, 0.5);

        //glColor3f(0.5, 0, 0);
        add_tex_coord(atlas_coord_1_x, atlas_coord_1_y, 1, 1);
        glNormal3f(0, 0, 1);
        glVertex3f(0.5, -0.5, 0.5);

        add_tex_coord(atlas_coord_1_x, atlas_coord_1_y, 1, 0);
        glNormal3f(0, 0, 1);
        glVertex3f(0.5, 0.5, 0.5);

        add_tex_coord(atlas_coord_1_x, atlas_coord_1_y, 0, 0);
        glNormal3f(0, 0, 1);
        glVertex3f(-0.5, 0.5, 0.5);

        //glColor3f(0, 1, 0);
        add_tex_coord(atlas_coord_2_x, atlas_coord_2_y, 0, 0);
        glNormal3f(-1, 0, 0);
        glVertex3f(-0.5, 0.5, -0.5);

        add_tex_coord(atlas_coord_2_x, atlas_coord_2_y, 0, 1);
        glNormal3f(-1, 0, 0);
        glVertex3f(-0.5, -0.5, -0.5);

        add_tex_coord(atlas_coord_2_x, atlas_coord_2_y, 1, 0);
        glNormal3f(-1, 0, 0);
        glVertex3f(-0.5, 0.5, 0.5);

       // glColor3f(0, 0.5, 0);
        add_tex_coord(atlas_coord_2_x, atlas_coord_2_y, 1, 0);
        glNormal3f(-1, 0, 0);
        glVertex3f(-0.5, 0.5, 0.5);

        add_tex_coord(atlas_coord_2_x, atlas_coord_2_y, 0, 1);
        glNormal3f(-1, 0, 0);
        glVertex3f(-0.5, -0.5, -0.5);

        add_tex_coord(atlas_coord_2_x, atlas_coord_2_y, 1, 1);
        glNormal3f(-1, 0, 0);
        glVertex3f(-0.5, -0.5, 0.5);

    glEnd();

    SDL_GL_SwapWindow(window);
}

void first_2d_triangle_vertex_array() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    GLfloat vertices[] = {
        0.0, 0.5,
        0.5, -0.5,
        -0.5, -0.5
    };

    glEnableClientState(GL_VERTEX_ARRAY);

    glVertexPointer(2, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableClientState(GL_VERTEX_ARRAY);

    SDL_GL_SwapWindow(window);
}

void first_3d_triangle_vertex_array() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    GLfloat vertices[] = {
        0.0, 0.5, 0.0,
        0.5, -0.5, 0.0,
        -0.5, -0.5, 0.0,
    };

    glEnableClientState(GL_VERTEX_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableClientState(GL_VERTEX_ARRAY);

    SDL_GL_SwapWindow(window);
}

void first_3d_triangle_vertex_array_colors() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    GLfloat vertices[] = {
        0.0, 0.5, 0.0,
        0.5, -0.5, 0.0,
        -0.5, -0.5, 0.0,
    };

    GLfloat colors[] = {
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    SDL_GL_SwapWindow(window);
}

void box_tris_vertex_array() {
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
    //glRotatef(30, 1, 0, 0);
    //glRotatef(box_tris_rot, 0, 1, 0);

    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);

    GLfloat vertices[] = {
        -0.5, 0.5, 0.5,
        -0.5, -0.5, 0.5,
        0.5, -0.5, 0.5,

        0.5, -0.5, 0.5,
        0.5, 0.5, 0.5,
        -0.5, 0.5, 0.5,
    };

    GLfloat colors[] = {
        1, 0, 0,
        1, 0, 0,
        1, 0, 0,

        0.5, 0, 0,
        0.5, 0, 0,
        0.5, 0, 0,
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    SDL_GL_SwapWindow(window);
}

void box_tris_vertex_array_indices() {
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
    //glRotatef(30, 1, 0, 0);
    //glRotatef(box_tris_rot, 0, 1, 0);

    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);

    GLfloat vertices[] = {
        -0.5, 0.5, 0.5,
        -0.5, -0.5, 0.5,
        0.5, -0.5, 0.5,
        0.5, 0.5, 0.5,
    };

    GLfloat colors[] = {
        1, 0, 0,
        0, 1, 0,
        0, 0, 1,
        1, 1, 0,
    };

    GLuint indices[] = {
        0, 1, 2, 0, 2, 3
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, indices);

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    SDL_GL_SwapWindow(window);
}

void box_tris_vertex_array_indices_uv() {
    loadGLTextures("download.bmp");

    if (box_tris_rot_dir)
        box_tris_rot += 0.5;
    else
        box_tris_rot -= 0.5;

    if (box_tris_rot > 90 || box_tris_rot < 0)
        box_tris_rot_dir = !box_tris_rot_dir;

    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_TEXTURE_2D);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //glFrustum(-1, 1, -0.75, 0.75, 1, 10);
    glTranslatef(0, 0.1, 0);
    glOrtho(-2, 2, -1.5, 1.5, -10, 10);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBindTexture(GL_TEXTURE_2D, texture);

    //glTranslatef(0, 0, -2);
    //glRotatef(30, 1, 0, 0);
    //glRotatef(box_tris_rot, 0, 1, 0);

    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);

    GLfloat vertices[] = {
        -0.5, 0.5, 0.5,
        -0.5, -0.5, 0.5,
        0.5, -0.5, 0.5,
        0.5, 0.5, 0.5,
    };

    GLfloat uvs[] = {
        0, 0,
        0, 1,
        1, 1,
        1, 0
    };

    GLuint indices[] = {
        0, 1, 2, 0, 2, 3
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glTexCoordPointer(2, GL_FLOAT, 0, uvs);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, indices);

    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    SDL_GL_SwapWindow(window);
}

GLuint triange_VBO;
bool vbo_init = false;

void triangle_3d_vertex_buffer_object() {
    if (!vbo_init) {
        vbo_init = true;

        GLfloat vertices[] = {
            0.0, 0.5, 0.0,
            0.5, -0.5, 0.0,
            -0.5, -0.5, 0.0,
        };

        glGenBuffers(1, &triange_VBO);
        glBindBuffer(GL_ARRAY_BUFFER, triange_VBO);
        //sizeof(vertices) -> byte -> 9x4
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    }

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableClientState(GL_VERTEX_ARRAY);

    glBindBuffer(GL_ARRAY_BUFFER, triange_VBO);

    glVertexPointer(3, GL_FLOAT, 0, NULL);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableClientState(GL_VERTEX_ARRAY);

    SDL_GL_SwapWindow(window);
}

size_t v_size = 0;
void triangle_3d_vertex_buffer_object_color() {
    if (!vbo_init) {
        vbo_init = true;

        GLfloat vertices[] = {
            0.0, 0.5, 0.0,
            0.5, -0.5, 0.0,
            -0.5, -0.5, 0.0,
        };

        GLfloat colors[] = {
            1, 0, 0,
            0, 1, 0,
            0, 0, 1
        };

        //sizeof() -> tömb méret byte-ban
        v_size = sizeof(vertices);
        size_t c_size = sizeof(colors);

        glGenBuffers(1, &triange_VBO);
        glBindBuffer(GL_ARRAY_BUFFER, triange_VBO);
        //ez így csak allokáció
        glBufferData(GL_ARRAY_BUFFER, v_size + c_size, 0, GL_STATIC_DRAW);

        glBufferSubData(GL_ARRAY_BUFFER, 0, v_size, vertices);
        glBufferSubData(GL_ARRAY_BUFFER, v_size, c_size, colors);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glBindBuffer(GL_ARRAY_BUFFER, triange_VBO);

    glVertexPointer(3, GL_FLOAT, 0, 0);
    glColorPointer(3, GL_FLOAT, 0, (void*)v_size);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    SDL_GL_SwapWindow(window);
}

int current_demo = 24;

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
        case 13:
            first_2d_triangle_uv();
            break;
        case 14:
            first_2d_triangle_quad_uv();
            break;
        case 15:
            box_tris_lights_uv();
            break;
        case 16:
            box_tris_lights_uv_texture_atlas();
            break;
        case 17:
            first_2d_triangle_vertex_array();
            break;
        case 18:
            first_3d_triangle_vertex_array();
            break;
        case 19:
            first_3d_triangle_vertex_array_colors();
            break;
        case 20:
            box_tris_vertex_array();
            break;
        case 21:
            box_tris_vertex_array_indices();
            break;
        case 22:
            box_tris_vertex_array_indices_uv();
            break;
        case 23:
            triangle_3d_vertex_buffer_object();
            break;
        case 24:
            triangle_3d_vertex_buffer_object_color();
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

    if (vbo_init) {
        glDeleteBuffers(1, &triange_VBO);
    }

    SDL_DestroyWindow(window);

    window = nullptr;

    SDL_Quit();

    return 0;
}