#ifndef MATH_H_INCLUDED
#define MATH_H_INCLUDED

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/ext.hpp>
#include <glm/gtx/string_cast.hpp>

using Vector2 = glm::vec2;
using Vector3 = glm::vec3;

using Matrix4 = glm::mat4;

class Entity;
class Camera;
class Config;

Matrix4
makeModelMatrix(const Entity& entity);

Matrix4
makeViewMatrix(const Camera& camera);

Matrix4
makeProjectionMatrix(const Config& config);

#endif
