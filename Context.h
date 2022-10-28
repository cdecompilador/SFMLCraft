#ifndef CONTEXT_H_INCLUDE
#define CONTEXT_H_INCLUDE

#include <SFML/Window/Window.hpp>

#include "Config.h"

struct Context
{
    Context(const Config& config);

    sf::Window window;
};

#endif
