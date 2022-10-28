#include "RenderMaster.h"

#include <SFML/OpenGL.hpp>

void
RenderMaster::drawQuad(Vector3& position)
{
    m_quadRenderer.addQuad(position);
}

void
RenderMaster::finishRender(sf::Window& window, const Camera& camera)
{
    glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    m_quadRenderer.renderQuads(camera);

    window.display();
}
