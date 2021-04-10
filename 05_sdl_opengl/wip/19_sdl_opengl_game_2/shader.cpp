#include "shader.h"

#include <stdio.h>
#include <vector>

Shader *Shader::current_shader = nullptr;

bool Shader::bind() {
	if (current_shader != this) {
		glUseProgram(program);

		current_shader = this;

		return true;
	}

	return false;
}
void Shader::unbind() {
	if (current_shader == this) {
		glUseProgram(0);
	}
}

void Shader::compile() {
	program = glCreateProgram();

	vertex_shader = glCreateShader(GL_VERTEX_SHADER);

	const GLchar **vertex_shader_source = get_vertex_shader_source();

	glShaderSource(vertex_shader, 1, vertex_shader_source, NULL);
	glCompileShader(vertex_shader);

	GLint shader_compiled = GL_FALSE;
	glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &shader_compiled);
	if (shader_compiled != GL_TRUE) {
		print_shader_errors(vertex_shader, "compiling Vertex Shader");
		return;
	}

	glAttachShader(program, vertex_shader);

	fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

	const GLchar **fragment_shader_source = get_fragment_shader_source();

	glShaderSource(fragment_shader, 1, fragment_shader_source, NULL);
	glCompileShader(fragment_shader);

	GLint fragment_shader_compiled = GL_FALSE;
	glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &fragment_shader_compiled);
	if (fragment_shader_compiled != GL_TRUE) {
		print_shader_errors(fragment_shader, "compiling Fragment Shader");
		return;
	}

	glAttachShader(program, fragment_shader);

	glBindAttribLocation(program, ATTRIBUTE_POSITION, "a_position");
	glBindAttribLocation(program, ATTRIBUTE_NORMAL, "a_normal");
	glBindAttribLocation(program, ATTRIBUTE_COLOR, "a_color");
	glBindAttribLocation(program, ATTRIBUTE_UV, "a_uv");

	glLinkProgram(program);

	GLint program_success = GL_TRUE;
	glGetProgramiv(program, GL_LINK_STATUS, &program_success);
	if (program_success != GL_TRUE) {
		print_program_errors(program);
		return;
	}
}
void Shader::destroy() {
	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);
	glDeleteProgram(program);
}

const GLchar **Shader::get_vertex_shader_source() {
	return vertex_shader_source;
}
void Shader::set_vertex_shader_source(const GLchar **source) {
	vertex_shader_source = source;
}

const GLchar **Shader::get_fragment_shader_source() {
	return fragment_shader_source;
}
void Shader::set_fragment_shader_source(const GLchar **source) {
	fragment_shader_source = source;
}

void Shader::print_shader_errors(const GLuint p_program, const char *name) {
	int max_length = 5000;
	std::vector<GLchar> error_log(max_length);
	glGetShaderInfoLog(p_program, max_length, &max_length, &error_log[0]);

	printf("Error %s!\n", name);
	printf("%s\n", &error_log[0]);
}

void Shader::print_program_errors(const GLuint p_program) {
	if (glIsProgram(p_program)) {
		int info_length = 0;
		int max_length = 5000;

		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &info_length);

		char *info_log = new char[max_length];

		glGetProgramInfoLog(p_program, max_length, &info_length, info_log);

		if (info_length > 0) {
			printf("%s\n", info_log);
		}

		delete[] info_log;
	} else {
		printf("print_program_errors: Not a program!");
	}
}

Shader::Shader() {
}
Shader::~Shader() {
	destroy();
}

//Meyers singleton
//Thread safe
ShaderCache *ShaderCache::get_singleton() {
    static ShaderCache instance;

    return &instance;
}

Shader *ShaderCache::get_shader(const int id) {
    return shaders[id];
}
void ShaderCache::add_shader(const int id, Shader *shader) {
    shaders[id] =  shader;
}

ShaderCache::ShaderCache() {
}
ShaderCache::~ShaderCache() {
    for (const std::pair<int, Shader*>& n : shaders) {
        delete n.second;
    }

    shaders.clear();
}
