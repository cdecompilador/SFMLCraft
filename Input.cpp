#include "Input.h"

namespace
{
template <typename E>
constexpr typename std::underlying_type<E>::type 
intoIdx(E e) 
{
    return static_cast<typename std::underlying_type<E>::type>(e);
}
}

Keyboard::Keyboard()
{
    std::fill(m_keys.begin(), m_keys.end(), false);
}

void
Keyboard::update(sf::Event e)
{
    m_recentlyReleased = {};
    switch (e.type)
    {
    case sf::Event::KeyReleased:
        switch (e.key.code) 
        {
        case sf::Keyboard::A:
            m_keys[intoIdx(Key::A)] = false;
            break;
        case sf::Keyboard::W:
            m_keys[intoIdx(Key::W)] = false;
            break;
        case sf::Keyboard::S:
            m_keys[intoIdx(Key::S)] = false;
            break;
        case sf::Keyboard::D:
            m_keys[intoIdx(Key::D)] = false;
            break;
        default:
            break;
        }
        break;

    case sf::Event::KeyPressed:
        switch (e.key.code)
        {
        case sf::Keyboard::A:
            m_recentlyReleased = Key::A;
            m_keys[intoIdx(Key::A)] = true;
            break;
        case sf::Keyboard::W:
            m_recentlyReleased = Key::W;
            m_keys[intoIdx(Key::W)] = true;
            break;
        case sf::Keyboard::S:
            m_recentlyReleased = Key::S;
            m_keys[intoIdx(Key::S)] = true;
            break;
        case sf::Keyboard::D:
            m_recentlyReleased = Key::D;
            m_keys[intoIdx(Key::D)] = true;
            break;
        default:
            break;
        }
        break;

    default:
        break;
    }
}

bool
Keyboard::isKeyDown(Key key) const
{
    return m_keys[intoIdx(key)];
}

bool
Keyboard::isKeyReleased(Key key) const
{
    if (!m_recentlyReleased.has_value())
        return false;

    return m_recentlyReleased.value() == key;
}
