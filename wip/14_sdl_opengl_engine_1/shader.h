#ifndef SHADER_H
#define SHADER_H

#include "opengl.h"
#include <unordered_map>

class Shader {
public:
    bool bind();
    void unbind();

    void compile();
    void destroy();

    const GLchar** get_vertex_shader_source();
    void set_vertex_shader_source(const GLchar** source);

    const GLchar** get_fragment_shader_source();
    void set_fragment_shader_source(const GLchar** source);

    void print_shader_errors(const GLuint p_program, const char* name);

    Shader();
    ~Shader();

    GLuint vertex_shader = 0;
    GLuint fragment_shader = 0;
    GLuint program = 0;

protected:
    static Shader* current_shader;

    const GLchar **vertex_shader_source;
    const GLchar **fragment_shader_source;
};

class ShaderCache {
public:
    static ShaderCache *get_singleton();

    Shader *get_shader(const int id);
    void add_shader(const int id, Shader * shader);

    ShaderCache(); //lehetene nem publikus
    ~ShaderCache();

protected:
    std::unordered_map<int, Shader*> shaders;
};

#endif