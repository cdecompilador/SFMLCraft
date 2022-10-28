#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED

#include <string>

#include <SFML/Graphics.hpp>
#include <GL/glew.h>

#include "../Util/NonCopyable.h"

class BasicTexture : public NonCopyable
{
public:
    BasicTexture() = default;
    BasicTexture(const std::string& file);

    ~BasicTexture();

    void
    loadFromImage(const sf::Image& i);

    void
    loadFromFile(const std::string& file);

    void
    bindTexture() const;
private:
    GLuint m_id;
};

#endif
