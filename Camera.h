#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include "Entity.h"
#include "Config.h"

class Camera : public Entity
{
public:
    Camera(const Config& config);

    void
    hookEntity(const Entity& entity);

    void 
    update();

    const Matrix4&
    getProjectionViewMatrix() const;
private:
    const Entity* m_pEntity;
    Matrix4 m_projViewMatrix;
    Matrix4 m_projMatrix;
    Matrix4 m_viewMatrix;
    Config m_config;
};

#endif
