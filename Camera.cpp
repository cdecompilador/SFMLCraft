#include "Camera.h"

#include "Math.h"
#include "Entity.h"

#include <iostream>

Camera::Camera(const Config& config)
    : m_config(config)
{
    m_projMatrix = makeProjectionMatrix(config);
}

void
Camera::hookEntity(const Entity& entity)
{
    m_pEntity = &entity;
}

void 
Camera::update()
{
    position = m_pEntity->position;
    rotation = m_pEntity->rotation;

    m_viewMatrix = makeViewMatrix(*this);
    m_projViewMatrix = m_projMatrix * m_viewMatrix;
}

const Matrix4&
Camera::getProjectionViewMatrix() const
{
    return m_projViewMatrix;
}
