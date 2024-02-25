#include "gloo/ElementBufferObject.h"

/**
 * Generate a ElementBufferObject.
 * Binds the created ElementBufferObject as a result.
 **/
gloo::ElementBufferObject::ElementBufferObject(const std::vector<GLuint> &_indices)
{
    glGenBuffers(1, &id);
    Bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof(GLuint), _indices.data(), GL_STATIC_DRAW);
}

/**
 * Bind the ElementBufferObject.
 **/
void gloo::ElementBufferObject::Bind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

/**
 * Delete the ElementBufferObject.
 **/
void gloo::ElementBufferObject::Delete()
{
    glDeleteBuffers(1, &id);
}