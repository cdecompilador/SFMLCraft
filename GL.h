#ifndef GL_H_INCLUDED
#define GL_H_INCLUDED

#include <GL/glew.h>

namespace gl
{
    inline void
    drawElements(GLuint indicesCount)
    {
        glDrawElements(GL_TRIANGLES, indicesCount, GL_UNSIGNED_INT, nullptr);
    }
}

#endif
