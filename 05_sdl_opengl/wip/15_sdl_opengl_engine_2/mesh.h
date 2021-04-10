#ifndef MESH_H
#define MESH_H

#include <vector>
#include "opengl.h"

using namespace std;

class Mesh {
public:
    void add_vertex2(GLfloat x, GLfloat y);
    void add_vertex3(GLfloat x, GLfloat y, GLfloat z);
    
    void add_normal(GLfloat x, GLfloat y, GLfloat z);
    void add_color(GLfloat r = 1, GLfloat g = 1, GLfloat b = 1, GLfloat a = 1);

    void add_uv(GLfloat u, GLfloat v);
    void add_index(GLuint index);
    void add_triangle(GLuint i1, GLuint i2, GLuint i3);

    void clear();

    void upload();
    void destroy();
    void render();

    Mesh();
    Mesh(int vert_dim);
    virtual ~Mesh();

    GLuint VBO;
    GLuint IBO;

    int vertex_dimensions;

    vector<GLfloat> vertices;
    vector<GLfloat> normals;
    vector<GLfloat> colors;
    vector<GLfloat> uvs;
    vector<GLuint> indices;

protected:
    size_t vertices_vbo_size;
    size_t normals_vbo_size;
    size_t colors_vbo_size;
    size_t uvs_vbo_size;
    size_t indices_vbo_size;
};

#endif