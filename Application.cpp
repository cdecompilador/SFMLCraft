#include "Application.h"

#include <iostream>

#include "States/StatePlaying.h"

Application::Application(const Config& config)
    : m_context(config)
    , m_camera(config)
    , m_config(config)
{
    pushState<StatePlaying>(*this, config);
}

void
Application::runLoop()
{
    sf::Clock dtTimer;

    sf::Time m;

    while (m_context.window.isOpen() && !m_states.empty())
    {
        auto deltaTime = dtTimer.restart();
        auto& state = *m_states.back();

        Entity player({0, 0, m_z}, {0, 0, 0});
        m_camera.hookEntity(player);
        m_camera.update();

        state.handleInput();
        state.update(deltaTime.asSeconds());

        state.render(m_masterRenderer);
        m_masterRenderer.finishRender(m_context.window, m_camera);

        handleEvents();
        if (m_isPopState)
        {
            m_isPopState = false;
            m_states.pop_back();
        }
    }
}

void
Application::handleEvents()
{
    sf::Event e;
    while (m_context.window.pollEvent(e))
    {
        m_states.back()->handleEvent(e);
        switch (e.type)
        {
        case sf::Event::Closed:
            m_context.window.close();
            break;

        case sf::Event::KeyPressed:
            switch (e.key.code)
            {
            case sf::Keyboard::Escape:
                m_context.window.close();
                break;
            case sf::Keyboard::W:
                m_z -= 0.1;
                break;
            case sf::Keyboard::S:
                m_z += 0.1;
                break;
            default:
                break;
            }
            break;

        default:
            break;
        }
    }
}

void
Application::popState()
{
    m_isPopState = true;
}
