#include "gloo/VertexArrayObject.h"

/**
 * Create a VertexArrayObject.
 * Binds the created VertexArrayObject as a result.
 **/
gloo::VertexArrayObject::VertexArrayObject()
{
    glGenVertexArrays(1, &id);
    Bind();
}

/**
 * Link attribute to the VertexArrayObject.
 * \param _vertexBufferObject VertexBufferObject.
 * \param _layout layout of the shader this atribute is linking to.
 * \param _numComponents number of components of this attribute.
 * \param _type type of the attribute.
 * \param _stride stride of the array.
 * \param _offset offset on the array.
 **/
void gloo::VertexArrayObject::LinkAttribute(VertexBufferObject &_vertexBufferObject, GLuint _layout, GLint _numComponents, Type _type, GLsizei _stride, const void *_offset)
{
    _vertexBufferObject.Bind();
    glVertexAttribPointer(_layout, _numComponents, (GLenum)_type, GL_FALSE, _stride, _offset);
    glEnableVertexAttribArray(_layout);
    VertexBufferObject::UNBIND();
}

/**
 * Bind the VertexArrayObject.
 **/
void gloo::VertexArrayObject::Bind()
{
    glBindVertexArray(id);
}

/**
 * Delete the VertexArrayObject.
 **/
void gloo::VertexArrayObject::Delete()
{
    glDeleteVertexArrays(1, &id);
}