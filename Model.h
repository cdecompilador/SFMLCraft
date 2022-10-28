#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

#include <vector>

#include <GL/glew.h>

#include "Mesh.h"
#include "Util/NonCopyable.h"
#include "Renderer/RenderInfo.h"

class Model : public NonCopyable
{
public:
    Model() = default;
    Model(const Mesh& mesh);
    ~Model();

    void
    addData(const Mesh& mesh);

    void
    deleteData();

    void
    genVAO();

    void
    bind() const;

    void
    addVBO(int dimensions, const FloatVector& data); 

    void
    addEBO(const IndexVector& indices);

    int
    getIndicesCount();
private:
    RenderInfo m_renderInfo;
    int m_vboCount = 0;
    std::vector<GLuint> m_buffers;
};

#endif
