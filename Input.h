#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include <optional>
#include <array>

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

const float ANGLE_BOUND = 89.0f;

enum class Key
{
    A,
    W,
    S,
    D
};

class Keyboard
{
public:
    Keyboard();

    void
    update(sf::Event e);

    bool
    isKeyDown(Key key) const;

    bool
    isKeyReleased(Key key) const;
private:
    std::array<bool, 4> m_keys;
    std::optional<Key> m_recentlyReleased;
};

#endif
