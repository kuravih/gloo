#ifndef _GLOO_MESH_H_
#define _GLOO_MESH_H_

#pragma once

#include "gloo/VertexArrayObject.h"
#include "gloo/VertexBufferObject.h"
#include "gloo/ElementBufferObject.h"

#include <glad/glad.h>

namespace gloo
{

    /**
     * Mesh class.
     **/
    class Mesh
    {
    public:
        GLsizeiptr NIndices;
        VertexArrayObject vao;
        VertexBufferObject vbo;
        ElementBufferObject ebo;

        Mesh() = default;

        /**
         * Create Mesh.
         * \param _vertices The vertex vector.
         * \param _indices The index vector.
         **/
        Mesh(const std::vector<Vertex> &_vertices, const std::vector<GLuint> &_indices)
            : NIndices(_indices.size()), vao(), vbo(_vertices), ebo(_indices) {}

        ~Mesh()
        {
            Delete();
        }

        /**
         * Link a mesh attribute to the shader.
         * \param _layout layout of the shader this attribute is linking to.
         * \param _numComponents number of components of this attribute.
         * \param _type type of the attribute.
         * \param _stride stride of the array.
         * \param _offset offset on the array.
         **/
        void LinkAttribute(GLuint _layout, GLint _numComponents, VertexArrayObject::Type _type, GLsizei _stride, const void *_offset)
        {
            vao.LinkAttribute(vbo, _layout, _numComponents, _type, _stride, _offset);
        }

        /**
         * Link mesh position attribute to the shader.
         * \param _layout layout of the shader this attribute is linking to.
         **/
        void LinkPositionToLocation(GLuint _layout)
        {
            LinkAttribute(_layout, 3, VertexArrayObject::Type::Float, sizeof(Vertex), (void *)0);
        }

        /**
         * Link mesh normal attribute to the shader.
         * \param _layout layout of the shader this attribute is linking to.
         **/
        void LinkNormalToLocation(GLuint _layout)
        {
            LinkAttribute(_layout, 3, VertexArrayObject::Type::Float, sizeof(Vertex), (void *)(sizeof(glm::vec3)));
        }

        /**
         * Link mesh color attribute to the shader.
         * \param _layout layout of the shader this attribute is linking to.
         **/
        void LinkColorToLocation(GLuint _layout)
        {
            LinkAttribute(_layout, 3, VertexArrayObject::Type::Float, sizeof(Vertex), (void *)(sizeof(glm::vec3) + sizeof(glm::vec3)));
        }

        /**
         * Link texture uv coordinate attribute to the shader.
         * \param _layout layout of the shader this attribute is linking to.
         **/
        void LinkTextureUVToLocation(GLuint _layout)
        {
            LinkAttribute(_layout, 2, VertexArrayObject::Type::Float, sizeof(Vertex), (void *)(sizeof(glm::vec3) + sizeof(glm::vec3) + sizeof(glm::vec3)));
        }

        /**
         * Delete the Mesh.
         * Deletes the associated VertexArrayObject, VertexBufferObject and ElementBufferObject.
         **/
        void Delete()
        {
            vao.Delete();
            vbo.Delete();
            ebo.Delete();
        }

        /**
         * Draw the Mesh.
         **/
        void Draw()
        {
            vao.Bind();
            glDrawElements(GL_TRIANGLES, NIndices, GL_UNSIGNED_INT, 0);
            VertexArrayObject::UNBIND();
        }
    };

}

#endif // _GLOO_MESH_H_
