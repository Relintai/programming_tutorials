#include "mesh.h"

#include "shader.h"

void Mesh::add_vertex2(GLfloat x, GLfloat y) {
    vertices.push_back(x);
    vertices.push_back(y);
}
void Mesh::add_vertex3(GLfloat x, GLfloat y, GLfloat z) {
    vertices.push_back(x);
    vertices.push_back(y);
    vertices.push_back(z);
}

void Mesh::add_normal(GLfloat x, GLfloat y, GLfloat z) {
    normals.push_back(x);
    normals.push_back(y);
    normals.push_back(z);
}
void Mesh::add_color(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
    colors.push_back(r);
    colors.push_back(g);
    colors.push_back(b);
    colors.push_back(a);
}

void Mesh::add_uv(GLfloat u, GLfloat v) {
    uvs.push_back(u);
    uvs.push_back(v);
}
void Mesh::add_index(GLuint index) {
    indices.push_back(index);
}
void Mesh::add_triangle(GLuint i1, GLuint i2, GLuint i3) {
    indices.push_back(i1);
    indices.push_back(i2);
    indices.push_back(i3);
}

void Mesh::clear() {
    vertices.clear();
    normals.clear();
    colors.clear();
    uvs.clear();
    indices.clear();
}

void Mesh::upload() {
    if (vertices.size() == 0)
        return;

    if (!VBO) {
        glGenBuffers(1, &VBO);
    }

    vertices_vbo_size = sizeof(GLfloat) * vertices.size();
    normals_vbo_size = sizeof(GLfloat) * normals.size();
    colors_vbo_size = sizeof(GLfloat) * colors.size();
    uvs_vbo_size = sizeof(GLfloat) * uvs.size();
    indices_vbo_size = sizeof(GLfloat) * indices.size();

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices_vbo_size + normals_vbo_size + colors_vbo_size + uvs_vbo_size, 0, GL_STATIC_DRAW);

    glBufferSubData(GL_ARRAY_BUFFER, 0, vertices_vbo_size, &vertices[0]);

    if (normals_vbo_size > 0) {
        glBufferSubData(GL_ARRAY_BUFFER, vertices_vbo_size, normals_vbo_size, &normals[0]);
    }

    if (colors_vbo_size > 0) {
        glBufferSubData(GL_ARRAY_BUFFER, vertices_vbo_size + normals_vbo_size, colors_vbo_size, &colors[0]);
    }

    if (uvs_vbo_size > 0) {
        glBufferSubData(GL_ARRAY_BUFFER, vertices_vbo_size + normals_vbo_size + colors_vbo_size, uvs_vbo_size, &uvs[0]);
    }

    if (indices_vbo_size > 0) {
        if (!IBO) {
            glGenBuffers(1, &IBO);
        }

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_vbo_size, &indices[0], GL_STATIC_DRAW);
    }

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
void Mesh::destroy() {
    if (VBO) {
        glDeleteBuffers(1, &VBO);
    }

    if (IBO) {
        glDeleteBuffers(1, &IBO);
    }
}
void Mesh::render() {
    if (vertices.size() == 0 || !VBO)
        return;

    if (!Shader::current_shader)
        return;

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glVertexAttribPointer(Shader::ATTRIBUTE_POSITION, vertex_dimensions, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(Shader::ATTRIBUTE_POSITION);

    if (normals_vbo_size > 0) {
        glVertexAttribPointer(Shader::ATTRIBUTE_NORMAL, 3, GL_FLOAT, GL_FALSE, 0, (void *)(vertices_vbo_size));
        glEnableVertexAttribArray(Shader::ATTRIBUTE_NORMAL);
    }

    if (colors_vbo_size > 0) {
        glVertexAttribPointer(Shader::ATTRIBUTE_COLOR, 4, GL_FLOAT, GL_FALSE, 0, (void *)(vertices_vbo_size + normals_vbo_size));
        glEnableVertexAttribArray(Shader::ATTRIBUTE_COLOR);
    }

    if (uvs_vbo_size > 0) {
        glVertexAttribPointer(Shader::ATTRIBUTE_UV, 2, GL_FLOAT, GL_FALSE, 0, (void *)(vertices_vbo_size + normals_vbo_size + colors_vbo_size));
        glEnableVertexAttribArray(Shader::ATTRIBUTE_UV);
    }

    if (indices_vbo_size > 0) {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, (GLvoid*)0);
    } else {
        glDrawArrays(GL_TRIANGLES, 0, vertices.size());
    }

    glDisableVertexAttribArray(Shader::ATTRIBUTE_POSITION);

    if (normals_vbo_size > 0) {
        glDisableVertexAttribArray(Shader::ATTRIBUTE_NORMAL);
    }

    if (colors_vbo_size > 0) {
        glDisableVertexAttribArray(Shader::ATTRIBUTE_COLOR);
    }

    if (uvs_vbo_size > 0) {
        glDisableVertexAttribArray(Shader::ATTRIBUTE_UV);
    }

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

Mesh::Mesh() {
    VBO = 0;
    IBO = 0;

    vertex_dimensions = 3;

    vertices_vbo_size = 0;
    normals_vbo_size = 0;
    colors_vbo_size = 0;
    uvs_vbo_size = 0;
    indices_vbo_size = 0;
}
Mesh::Mesh(int vert_dim) {
    VBO = 0;
    IBO = 0;

    vertex_dimensions = vert_dim;

    vertices_vbo_size = 0;
    normals_vbo_size = 0;
    colors_vbo_size = 0;
    uvs_vbo_size = 0;
    indices_vbo_size = 0;
}
Mesh::~Mesh() {
    destroy();
    clear();
}