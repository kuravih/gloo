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
        Mesh(const std::vector<Vertex> &_vertices, const std::vector<GLuint> &_indices);
        Mesh(const std::vector<GLuint> &_indices); // TODO: a mesh can be rendered only with indices;
        ~Mesh()
        {
            Delete();
        }
        void LinkAttribute(GLuint _layout, GLint _numComponents, VertexArrayObject::Type _type, GLsizei _stride, const void *_offset);
        void LinkPositionToLocation(GLuint _layout);
        void LinkColorToLocation(GLuint _layout);
        void LinkNormalToLocation(GLuint _layout);
        void LinkTextureUVToLocation(GLuint _layout);
        void Delete();
        void Draw();
    };

}

#endif // _GLOO_MESH_H_