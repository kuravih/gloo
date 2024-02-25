#ifndef _GLOO_VERTEXARRAYOBJECT_H_
#define _GLOO_VERTEXARRAYOBJECT_H_

#include "gloo/VertexBufferObject.h"

#include <glad/glad.h>

namespace gloo
{

    /**
     * VertexArrayObject class.
     **/
    class VertexArrayObject
    {
    public:
        /*! Type of linked attribute */
        enum class Type : GLenum
        {
            Byte = GL_BYTE,                                             /*!< Byte type */
            UnsignedByte = GL_UNSIGNED_BYTE,                            /*!< Unsigned Byte */
            Short = GL_SHORT,                                           /*!< Short */
            UnsignedShort = GL_UNSIGNED_SHORT,                          /*!< Unsigned Short */
            Int = GL_INT,                                               /*!< Integer */
            UnsignedInt = GL_UNSIGNED_INT,                              /*!< Unsigned Integer */
            HalfFloat = GL_HALF_FLOAT,                                  /*!< 16-bit Float */
            Float = GL_FLOAT,                                           /*!< Float */
            Double = GL_DOUBLE,                                         /*!< Double */
            Int2101010_Rev = GL_INT_2_10_10_10_REV,                     /*!< TODO: */
            UnsignedInt2101010_Rev = GL_UNSIGNED_INT_2_10_10_10_REV,    /*!< TODO: */
            UnsignedInt10f11f11f_Rev = GL_UNSIGNED_INT_10F_11F_11F_REV, /*!< TODO: */
            nTypes
        };

    private:
        GLuint id;

    public:
        VertexArrayObject();
        ~VertexArrayObject() = default;
        /**
         * Cast to GLuint.
         * Lets you use the objects of VertexArrayObject class in regular opengl calls.
         **/
        operator GLuint() const
        {
            return id;
        }
        void LinkAttribute(VertexBufferObject &_vertexBufferObject, GLuint _layout, GLint _numComponents, Type _type, GLsizei _stride, const void *_offset);
        void Bind();
        /**
         * Unbind the VertexArrayObject.
         **/
        static void UNBIND()
        {
            glBindVertexArray(0);
        }
        void Delete();
    };

}

#endif // _GLOO_VERTEXARRAYOBJECT_H_