#ifndef OPENGL_H
#define OPENGL_H

#if __unix__ && !__ANDROID__
#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#endif

#if __ANDROID__
#define GL_GLEXT_PROTOTYPES
#include <GLES2/gl2.h>
#endif

#if _WIN64
#include <glad/glad.h>
#endif


#endif
