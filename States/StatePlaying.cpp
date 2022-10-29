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
    // Handle keyboard input
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

    // Handle mouse input
    auto& window = m_pApplication->getWindow();

    static auto lastMousePosition = sf::Mouse::getPosition(window);
    auto change = sf::Mouse::getPosition() - lastMousePosition;

    m_player.rotation.y += change.x * 0.05f;
    m_player.rotation.x += change.y * 0.05f;

    if (m_player.rotation.x > ANGLE_BOUND)
        m_player.rotation.x = ANGLE_BOUND;
    else if (m_player.rotation.x < -ANGLE_BOUND)
        m_player.rotation.x = -ANGLE_BOUND;

    if (m_player.rotation.y > 360)
        m_player.rotation.y = 0;
    else if (m_player.rotation.y < 0)
        m_player.rotation.y = 360;

    auto cx = static_cast<int>(window.getSize().x / 2);
    auto cy = static_cast<int>(window.getSize().y / 2);

    sf::Mouse::setPosition({cx, cy}, window);
    lastMousePosition = sf::Mouse::getPosition();

    // Apply differentials and reset
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
