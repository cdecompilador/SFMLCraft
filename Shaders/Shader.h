#ifndef SHADER_H_INCLUDED
#define SHADER_H_INCLUDED

#include <string>

#include "../GL.h"
#include "../Math.h"
#include "../Util/NonCopyable.h"

class Shader : NonCopyable
{
public:
    Shader(const std::string& vertexFile,
           const std::string& fragmentFile);
    virtual ~Shader();

    void
    useProgram() const;

    void
    loadInt(GLuint location, int value);

    void
    loadFloat(GLuint location, float value);

    void
    loadVector2(GLuint location, const Vector2& vec);

    void
    loadVector3(GLuint location, const Vector3& vec);

    void
    loadMatrix4(GLuint location, const Matrix4& mat);
protected:
    virtual void getUniforms() = 0;
    GLuint m_id;
};

#endif
