#ifndef OPENGL_H
#define OPENGL_H

#ifdef __unix__
#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#endif

#ifdef _WIN64
#include <glad/glad.h>
#endif


#endif
