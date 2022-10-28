#include "Shader.h"

#include "ShaderLoader.h"

Shader::Shader(const std::string& vertexFile,
               const std::string& fragmentFile)
    : m_id(loadShaders(vertexFile, fragmentFile))
{
    useProgram();
}

void
Shader::useProgram() const
{
    glUseProgram(m_id);
}

Shader::~Shader()
{
    glDeleteProgram(m_id);
}

void
Shader::loadInt(GLuint location, int value)
{
    glUniform1i(location, value);
}

void
Shader::loadFloat(GLuint location, float value)
{
    glUniform1f(location, value);
}

void
Shader::loadVector2(GLuint location, const Vector2& vec)
{
    glUniform2f(location, vec.x, vec.y);
}

void
Shader::loadVector3(GLuint location, const Vector3& vec)
{
    glUniform3f(location, vec.x, vec.y, vec.z);
}

void
Shader::loadMatrix4(GLuint location, const Matrix4& mat)
{
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat));
}
