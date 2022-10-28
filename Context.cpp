#include "Context.h"

#include <iostream>

#include <GL/glew.h>
#include <SFML/Window.hpp>

Context::Context(const Config& config)
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 0;
    settings.majorVersion = 3;
    settings.minorVersion = 3;
    settings.depthBits = 24;
    settings.stencilBits = 8;

    if (config.isFullscreen) 
    {
        window.create(sf::VideoMode::getDesktopMode(), "Mineclone",
                      sf::Style::Fullscreen, settings);
    } 
    else 
    {
        window.create(sf::VideoMode({config.windowW, config.windowH}),
                      "Mineclone", sf::Style::Close, settings);
    }

    window.setActive(true);
    if (glewInit() != GLEW_OK)
    {
        std::cerr << "Failed to initialize glew" << std::endl;
    }

    glViewport(0, 0, window.getSize().x, window.getSize().y);
}
