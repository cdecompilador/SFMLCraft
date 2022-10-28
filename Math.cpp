#include "Math.h"

#include "Config.h"
#include "Entity.h"
#include "Camera.h"

Matrix4
makeModelMatrix(const Entity& entity)
{
    // Instantiate identity matrix
    Matrix4 matrix(1.0f);

    // Rotate it
    matrix = glm::rotate(matrix, glm::radians(entity.rotation.x), {1, 0, 0});
    matrix = glm::rotate(matrix, glm::radians(entity.rotation.y), {0, 1, 0});
    matrix = glm::rotate(matrix, glm::radians(entity.rotation.z), {0, 0, 1});

    // Translate it
    matrix = glm::translate(matrix, entity.position);

    return matrix;
}

#include <iostream>

Matrix4
makeViewMatrix(const Camera& camera)
{
    Matrix4 matrix(1.0f);

    // Rotate it
    matrix = glm::rotate(matrix, glm::radians(camera.rotation.x), {1, 0, 0});
    matrix = glm::rotate(matrix, glm::radians(camera.rotation.y), {0, 1, 0});
    matrix = glm::rotate(matrix, glm::radians(camera.rotation.z), {0, 0, 1});

    // Translate it
    matrix = glm::translate(matrix, -camera.position);

    return matrix;
}

Matrix4
makeProjectionMatrix(const Config& config)
{
    float AR = (float)config.windowW / (float)config.windowH;
    float fov = (float)config.fov;

    return glm::perspective(glm::radians(fov), AR, 0.1f, 100.0f);
}
