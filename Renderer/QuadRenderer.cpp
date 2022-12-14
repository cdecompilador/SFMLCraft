#include "QuadRenderer.h"

#include "../GL.h"

#include <iostream>

QuadRenderer::QuadRenderer()
    : m_shader(BasicShader())
    , m_texture(BasicTexture("Wall.jpg"))
{
    m_quadModel.addData({
        {
             0.5f,  0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            -0.5f,  0.5f, 0.0f,
        },
        {
            1.0f, 1.0f,
            1.0f, 0.0f,
            0.0f, 0.0f,
            0.0f, 1.0f
        },
        {
            0, 1, 3,
            1, 2, 3
        }
    });
}

void
QuadRenderer::addQuad(const Vector3 position)
{
    m_quads.push_back(position);
}

void
QuadRenderer::renderQuads(const Camera& camera)
{
    m_quadModel.bind();
    m_shader.useProgram();
    for (auto& quad : m_quads)
    {
        m_shader.loadProjectionViewMatrix(camera.getProjectionViewMatrix());
        m_shader.loadModelMatrix(Matrix4(1.0f));
        gl::drawElements(m_quadModel.getIndicesCount());
    }

    m_quads.clear();
}
