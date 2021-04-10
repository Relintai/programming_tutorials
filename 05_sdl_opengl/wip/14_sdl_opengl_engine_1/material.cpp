#include "material.h"

#include <stdio.h>

bool Material::bind() {
    //csak a main thread fogja meghívni!

    if (!shader) {
        shader = ShaderCache::get_singleton()->get_shader(get_material_id());

        if (!shader) {
            shader = new Shader();

            shader->set_vertex_shader_source(get_vertex_shader_source());
            shader->set_fragment_shader_source(get_fragment_shader_source());
            shader->compile();

            ShaderCache::get_singleton()->add_shader(get_material_id(), shader);
        }

        setup_uniforms();
    }

    shader->bind();

    bind_uniforms();
}

void Material::unbind() {
}
void Material::bind_uniforms() {
}
void Material::setup_uniforms() {
}
void Material::setup_state() {
}

GLint Material::get_uniform(const char *name) {
    GLint uniform = glGetUniformLocation(shader->program, name);

    if (uniform == -1) {
        printf("%s is not a valid glsl program variable!\n", name);
    }

    return uniform;
}

Material::Material() {
}
Material::~Material() {
}
