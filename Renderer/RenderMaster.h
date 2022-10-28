#ifndef RENDERMASTER_H_INCLUDED
#define RENDERMASTER_H_INCLUDED

#include <SFML/Window/Window.hpp>

#include "../Math.h"
#include "../Config.h"
#include "QuadRenderer.h"

class RenderMaster
{
public:
    void
    drawQuad(Vector3& position);

    void 
    finishRender(sf::Window& window);
private:
    QuadRenderer m_quadRenderer;
};

#endif
