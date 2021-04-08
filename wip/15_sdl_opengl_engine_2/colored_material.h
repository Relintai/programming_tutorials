#ifndef COLORED_MATERIAL_H
#define COLORED_MATERIAL_H

#include "material.h"
#include "glm/vec4.hpp"

class ColoredMaterial : public Material {

public:
    int get_material_id() {
        return 1;
    }

    void bind_uniforms() {
        glUniform4f(tri_color_uniform_location, color.r, color.g, color.b, color.a);
    }

    void setup_uniforms() {
        tri_color_uniform_location = get_uniform("fragment_color");
    }

    const GLchar** get_vertex_shader_source() {
        static const GLchar *vertex_shader_source[] = {
            "void main() { gl_Position = gl_Vertex; }"
        };

        return vertex_shader_source;
    }

    const GLchar** get_fragment_shader_source() {
        static const GLchar *fragment_shader_source[] = {
            "uniform vec4 fragment_color = vec4(1, 1, 1, 1);"
            ""
            "void main() { gl_FragColor = fragment_color; }"
        };

        return fragment_shader_source;
    }

    ColoredMaterial() {
        color = glm::vec4(1, 1, 1, 1);
    }

    GLint tri_color_uniform_location;
    glm::vec4 color;
};

#endif