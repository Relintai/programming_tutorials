#ifndef TEXTURE_MATERIAL_H
#define TEXTURE_MATERIAL_H

#include "material.h"
#include "glm/vec4.hpp"
#include "texture.h"

#include "camera.h"

#include "./glm/gtc/type_ptr.hpp"

class TextureMaterial : public Material {

public:
    int get_material_id() {
        return 3;
    }

    void bind_uniforms() {
        glUniformMatrix4fv(projection_matrix_location, 1, GL_FALSE, glm::value_ptr(Camera::current_camera->projection_matrix));
        glUniformMatrix4fv(model_view_matrix_location, 1, GL_FALSE, glm::value_ptr(Camera::current_camera->model_view_matrix));

        if (texture) {
            glBindTexture(GL_TEXTURE_2D, texture->texture);
        }
    }

    void setup_uniforms() {
        projection_matrix_location = get_uniform("u_proj_matrix");
        model_view_matrix_location = get_uniform("u_model_view_matrix");
    }

    void unbind() {
        glDisable(GL_TEXTURE_2D);
    }

    void setup_state() {
        glEnable(GL_TEXTURE_2D);
    }

    const GLchar** get_vertex_shader_source() {
        static const GLchar *vertex_shader_source[] = {
            "uniform mat4 u_proj_matrix;\n"
            "uniform mat4 u_model_view_matrix;\n"
            "\n"
            "attribute vec4 a_position;\n"
            "attribute vec4 a_uv;\n"
            "\n"
            "varying vec4 v_uv;\n"
            "\n"
            "void main() { \n"
            "   v_uv = a_uv;\n"
            "   gl_Position = u_proj_matrix * u_model_view_matrix * a_position; \n"
            "}"
        };

        return vertex_shader_source;
    }

    const GLchar** get_fragment_shader_source() {
        static const GLchar *fragment_shader_source[] = {
            //"#version 130\n"
            "precision mediump float;\n"
            "uniform sampler2D image;\n"
            "varying vec4 v_uv;\n"
            "\n"
            "void main() { gl_FragColor = texture(image, v_uv); }\n"
        };

        return fragment_shader_source;
    }

    TextureMaterial() {
        texture = nullptr;
    }

    GLint projection_matrix_location;
    GLint model_view_matrix_location;

    Texture *texture;
};

#endif