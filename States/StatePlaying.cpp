#include "StatePlaying.h"

#include "../Math.h"
#include "../Input.h"

#include <iostream>

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
    if (m_pApplication->getKeyboard().isKeyDown(Key::W))
    {
        m_player.velocity.z -= PLAYER_SPEED;
    } 
    if (m_pApplication->getKeyboard().isKeyDown(Key::S))
    {
        m_player.velocity.z += PLAYER_SPEED;
    }
    if (m_pApplication->getKeyboard().isKeyDown(Key::A))
    {
        m_player.velocity.x -= PLAYER_SPEED;
    } 
    if (m_pApplication->getKeyboard().isKeyDown(Key::D))
    {
        m_player.velocity.x += PLAYER_SPEED;
    }

    m_player.position += m_player.velocity * deltaTime;

    m_player.velocity = Vector3(0.0f);
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
    m_pApplication->getCamera().hookEntity(m_player);
}
