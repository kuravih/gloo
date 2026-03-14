#ifndef _GLOO_ELEMENTBUFFEROBJECT_H_
#define _GLOO_ELEMENTBUFFEROBJECT_H_

#pragma once

#include <glad/glad.h>
#include <vector>

namespace gloo
{

    /**
     * ElementBufferObject class.
     **/
    class ElementBufferObject
    {
    private:
        GLuint id;

    public:
        ElementBufferObject() = default;

        /**
         * Generate a ElementBufferObject.
         * Binds the created ElementBufferObject as a result.
         **/
        ElementBufferObject(const std::vector<GLuint> &_indices)
        {
            glGenBuffers(1, &id);
            Bind();
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof(GLuint), _indices.data(), GL_STATIC_DRAW);
        }

        ~ElementBufferObject()
        {
            Delete();
        }

        /**
         * Cast to GLuint.
         * Lets you use the objects of ElementBufferObject class in regular opengl calls.
         **/
        operator GLuint() const
        {
            return id;
        }

        /**
         * Bind the ElementBufferObject.
         **/
        void Bind()
        {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
        }

        /**
         * Unbind the ElementBufferObject.
         **/
        static void UNBIND()
        {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        }

        /**
         * Delete the ElementBufferObject.
         **/
        void Delete()
        {
            glDeleteBuffers(1, &id);
        }
    };

}

#endif // _GLOO_ELEMENTBUFFEROBJECT_H_
