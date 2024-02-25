#include "gloo/Mesh.h"

/**
 * Create Mesh.
 * \param _vertices The vertex vector.
 * \param _indices The index vector.
 **/
gloo::Mesh::Mesh(const std::vector<Vertex> &_vertices, const std::vector<GLuint> &_indices) : NIndices(_indices.size()), vao(), vbo(_vertices), ebo(_indices) {}

/**
 * Link a mesh attribute to the shader.
 * \param _layout layout of the shader this attribute is linking to.
 * \param _numComponents number of components of this attribute.
 * \param _type type of the attribute.
 * \param _stride stride of the array.
 * \param _offset offset on the array.
 **/
void gloo::Mesh::LinkAttribute(GLuint _layout, GLint _numComponents, gloo::VertexArrayObject::Type _type, GLsizei _stride, const void *_offset)
{
    vao.LinkAttribute(vbo, _layout, _numComponents, _type, _stride, _offset);
}

/**
 * Link mesh position attribute to the shader.
 * \param _layout layout of the shader this attribute is linking to.
 * \param _numComponents number of components of this attribute.
 * \param _type type of the attribute.
 **/
void gloo::Mesh::LinkPositionToLocation(GLuint _layout)
{
    LinkAttribute(_layout, 3, gloo::VertexArrayObject::Type::Float, sizeof(gloo::Vertex), (void *)0);
}

/**
 * Link mesh color attribute to the shader.
 * \param _layout layout of the shader this attribute is linking to.
 * \param _numComponents number of components of this attribute.
 * \param _type type of the attribute.
 **/
void gloo::Mesh::LinkColorToLocation(GLuint _layout)
{
    LinkAttribute(_layout, 3, gloo::VertexArrayObject::Type::Float, sizeof(gloo::Vertex), (void *)(sizeof(glm::vec3)));
}

/**
 * Link mesh normal attribute to the shader.
 * \param _layout layout of the shader this attribute is linking to.
 * \param _numComponents number of components of this attribute.
 * \param _type type of the attribute.
 **/
void gloo::Mesh::LinkNormalToLocation(GLuint _layout)
{
    LinkAttribute(_layout, 3, gloo::VertexArrayObject::Type::Float, sizeof(gloo::Vertex), (void *)(sizeof(glm::vec3) + sizeof(glm::vec3)));
}

/**
 * Link texture uv coordinate attribute to the shader.
 * \param _layout layout of the shader this attribute is linking to.
 * \param _numComponents number of components of this attribute.
 * \param _type type of the attribute.
 **/
void gloo::Mesh::LinkTextureUVToLocation(GLuint _layout)
{
    LinkAttribute(_layout, 2, gloo::VertexArrayObject::Type::Float, sizeof(gloo::Vertex), (void *)(sizeof(glm::vec3) + sizeof(glm::vec3) + sizeof(glm::vec3)));
}

/**
 * Delete the Mesh.
 * Delete the associated VertexBufferObject, VertexBufferObject and ElementBufferObject.
 **/
void gloo::Mesh::Delete()
{
    vao.Delete();
    vbo.Delete();
    ebo.Delete();
}

/**
 * Draw the Mesh.
 **/
void gloo::Mesh::Draw()
{
    vao.Bind();
    glDrawElements(GL_TRIANGLES, NIndices, GL_UNSIGNED_INT, 0);
    gloo::VertexArrayObject::UNBIND();
}