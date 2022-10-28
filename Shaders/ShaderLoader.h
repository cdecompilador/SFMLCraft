#ifndef SHADERLOADER_H_INCLUDE
#define SHADERLOADER_H_INCLUDE

#include <string>

#include <GL/glew.h>

GLuint
loadShaders(const std::string& vertexShader,
            const std::string& fragmentShader);

#endif
