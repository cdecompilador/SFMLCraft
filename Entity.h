#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include "Math.h"

struct Entity
{
    Entity()
        : position(Vector3(0.0f, 0.0f, 1.0f))
        , rotation(Vector3())
        , velocity(Vector3())
    {
    }

    Entity(const Vector3& pos, const Vector3& rot)
        : position(pos)
        , rotation(rot)
        , velocity(Vector3())
    {
    }

    Vector3 position;
    Vector3 rotation;
    Vector3 velocity;
};

#endif
