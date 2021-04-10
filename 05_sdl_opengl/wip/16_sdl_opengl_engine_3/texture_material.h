#ifndef TEXTURE_MATERIAL_H
#define TEXTURE_MATERIAL_H

#include "material.h"
#include "glm/vec4.hpp"
#include "texture.h"

class TextureMaterial : public Material {

public:
    int get_material_id() {
        return 3;
    }

    void bind_uniforms() {
        if (texture) {
            glBindTexture(GL_TEXTURE_2D, texture->texture);
        }
    }

    void setup_uniforms() {
    }

    void unbind() {
        glDisable(GL_TEXTURE_2D);
    }

    void setup_state() {
        glEnable(GL_TEXTURE_2D);
    }

    const GLchar** get_vertex_shader_source() {
        static const GLchar *vertex_shader_source[] = {
            "varying vec4 v_uv;"
            "void main() { "
            "   v_uv = gl_MultiTexCoord0;"
            "   gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex; "
            "}"
        };

        return vertex_shader_source;
    }

    const GLchar** get_fragment_shader_source() {
        static const GLchar *fragment_shader_source[] = {
            "uniform sampler2D image;"
            "varying vec4 v_uv;"
            ""
            "void main() { gl_FragColor = texture(image, v_uv); }"
        };

        return fragment_shader_source;
    }

    TextureMaterial() {
        texture = nullptr;
    }

    Texture *texture;
};

#endif