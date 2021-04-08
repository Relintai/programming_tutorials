#ifndef COLOR_MATERIAL_H
#define COLOR_MATERIAL_H

#include "material.h"
#include "glm/vec4.hpp"

class ColorMaterial : public Material {

public:
    int get_material_id() {
        return 2;
    }

    void bind_uniforms() {
        glUniform4f(tri_color_uniform_location, color.r, color.g, color.b, color.a);
    }

    void setup_uniforms() {
        tri_color_uniform_location = get_uniform("fragment_color");
    }

    const GLchar** get_vertex_shader_source() {
        static const GLchar *vertex_shader_source[] = {
            "void main() { "
            "   gl_FrontColor = gl_Color;"
            "   gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex; "
            "}"
        };

        return vertex_shader_source;
    }

    const GLchar** get_fragment_shader_source() {
        static const GLchar *fragment_shader_source[] = {
            "uniform vec4 fragment_color = vec4(1, 1, 1, 1);"
            ""
            "void main() { gl_FragColor = gl_Color; }"
        };

        return fragment_shader_source;
    }

    ColorMaterial() {
        color = glm::vec4(1, 1, 1, 1);
    }

    GLint tri_color_uniform_location;
    glm::vec4 color;
};

#endif