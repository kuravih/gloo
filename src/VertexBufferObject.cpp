#include "gloo/VertexBufferObject.h"

/**
 * Create a VertexBufferObject.
 * Binds the created VertexBufferObject as a result.
 * \param _vertices The vertex array.
 * \param _size The size of the vertex array.
 **/
gloo::VertexBufferObject::VertexBufferObject(const std::vector<Vertex> &_vertices)
{
    glGenBuffers(1, &id);
    Bind();
    glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(Vertex), _vertices.data(), GL_STATIC_DRAW);
}

/**
 * Bind the VertexBufferObject.
 **/
void gloo::VertexBufferObject::Bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, id);
}

/**
 * Delete the VertexBufferObject.
 **/
void gloo::VertexBufferObject::Delete()
{
    glDeleteBuffers(1, &id);
}