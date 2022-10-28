#ifndef QUADRENDERER_H_INCLUDE
#define QUADRENDERER_H_INCLUDE

#include <vector>

#include "../Shaders/BasicShader.h"
#include "../Texture/BasicTexture.h"
#include "../Math.h"
#include "../Model.h"
#include "../Camera.h"

class QuadRenderer
{
public:
    QuadRenderer();

    void
    addQuad(const Vector3 position);

    void
    renderQuads(const Camera& camera);
private:
    std::vector<Vector3> m_quads;
    Model m_quadModel;
    BasicShader m_shader;
    BasicTexture m_texture;
};

#endif
