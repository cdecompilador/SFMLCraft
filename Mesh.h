#ifndef MESH_H_INCLUDED
#define MESH_H_INCLUDED

#include <vector>

#include <SFML/OpenGL.hpp>

using FloatVector = std::vector<GLfloat>;
using IndexVector = std::vector<GLuint>;

struct Mesh
{
    FloatVector vertexPositions;
    IndexVector indices;
};

#endif
