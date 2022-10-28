#ifndef MESH_H_INCLUDED
#define MESH_H_INCLUDED

#include <vector>

#include "GL.h"

using FloatVector = std::vector<GLfloat>;
using IndexVector = std::vector<GLuint>;

struct Mesh
{
    FloatVector vertexPositions;
    FloatVector textureCoords;
    IndexVector indices;
};

#endif
