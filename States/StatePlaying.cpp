#include "StatePlaying.h"


StatePlaying::StatePlaying(Application& app, const Config& config)
    : StateBase(app)
{
}

void 
StatePlaying::handleEvent(sf::Event e)
{
}

void 
StatePlaying::handleInput()
{
}

void
StatePlaying::update(float deltaTime)
{
}

void
StatePlaying::render(RenderMaster& renderer)
{
    auto pos = Vector3(0.0f, 0.0f, 0.0f);
    renderer.drawQuad(pos);
}

void
StatePlaying::onOpen()
{
}
