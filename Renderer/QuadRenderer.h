#ifndef QUADRENDERER_H_INCLUDE
#define QUADRENDERER_H_INCLUDE

#include <vector>

#include "../Shaders/BasicShader.h"
#include "../Math.h"
#include "../Model.h"

class QuadRenderer
{
public:
    QuadRenderer();

    void
    addQuad(const Vector3 position);

    void
    renderQuads();
private:
    std::vector<Vector3> m_quads;
    Model m_quadModel;
    BasicShader m_shader;
};

#endif
