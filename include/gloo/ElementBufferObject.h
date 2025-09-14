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
        ElementBufferObject(const std::vector<GLuint> &_indices);
        ~ElementBufferObject()
        {
            Delete();
        };
        /**
         * Cast to GLuint.
         * Lets you use the objects of ElementBufferObject class in regular opengl calls.
         **/
        operator GLuint() const
        {
            return id;
        }
        void Bind();
        /**
         * Unbind the ElementBufferObject.
         **/
        static void UNBIND()
        {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        }
        void Delete();
    };

}

#endif // _GLOO_ELEMENTBUFFEROBJECT_H_