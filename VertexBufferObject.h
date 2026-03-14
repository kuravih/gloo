#ifndef _GLOO_VERTEXBUFFEROBJECT_H_
#define _GLOO_VERTEXBUFFEROBJECT_H_

#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <vector>

namespace gloo
{

    struct Vertex
    {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec3 color;
        glm::vec2 texUV;
    };

    /**
     * VertexBufferObject class.
     **/
    class VertexBufferObject
    {
    private:
        GLuint id;

    public:
        VertexBufferObject() = default;

        /**
         * Create a VertexBufferObject.
         * Binds the created VertexBufferObject as a result.
         * \param _vertices The vertex array.
         **/
        VertexBufferObject(const std::vector<Vertex> &_vertices)
        {
            glGenBuffers(1, &id);
            Bind();
            glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(Vertex), _vertices.data(), GL_STATIC_DRAW);
        }

        ~VertexBufferObject()
        {
            Delete();
        }

        /**
         * Cast to GLuint.
         * Lets you use the objects of VertexBufferObject class in regular opengl calls.
         **/
        operator GLuint() const
        {
            return id;
        }

        /**
         * Bind the VertexBufferObject.
         **/
        void Bind()
        {
            glBindBuffer(GL_ARRAY_BUFFER, id);
        }

        /**
         * Unbind the VertexBufferObject.
         **/
        static void UNBIND()
        {
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }

        /**
         * Delete the VertexBufferObject.
         **/
        void Delete()
        {
            glDeleteBuffers(1, &id);
        }
    };

}

#endif // _GLOO_VERTEXBUFFEROBJECT_H_
