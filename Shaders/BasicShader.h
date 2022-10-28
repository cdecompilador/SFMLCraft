#ifndef BASICSHADER_H_INCLUDED
#define BASICSHADER_H_INCLUDED

#include <string>

#include "Shader.h"
#include "../Math.h"

class BasicShader : public Shader
{
public:
    BasicShader(const std::string& vertexFile = "Basic",
                const std::string& fragmentFile = "Basic");

    void
    loadProjectionViewMatrix(const Matrix4& pvm);

    void
    loadModelMatrix(const Matrix4& matrix);
protected:
    virtual void getUniforms() override;
private:
    GLuint m_locationProjectionViewMatrix;
    GLuint m_locationModelMatrix;
};

#endif
