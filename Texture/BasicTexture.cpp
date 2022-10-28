#include "BasicTexture.h"

#include <stdexcept>

BasicTexture::BasicTexture(const std::string& file)
{
    loadFromFile(file);
}

BasicTexture::~BasicTexture()
{
    glDeleteTextures(1, &m_id);
}

void
BasicTexture::loadFromImage(const sf::Image& i)
{
    // Alloc space on the GPU and GL state
    glGenTextures(1, &m_id);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_id);

    // Upload image data to the GPU
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, i.getSize().x, i.getSize().y, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, i.getPixelsPtr());

    // Generate lower res versions of the data for small rasters
    glGenerateMipmap(GL_TEXTURE_2D);

    // Setup how to interpolate image pixels, wrapping, etc, ...
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                    GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                    GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}

void
BasicTexture::loadFromFile(const std::string& file)
{
    sf::Image i;
    if (!i.loadFromFile("Assets/" + file))
    {
        throw std::runtime_error("");
    }

    loadFromImage(i);
}

void
BasicTexture::bindTexture() const
{
    glBindTexture(GL_TEXTURE_2D, m_id);
}
