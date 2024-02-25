#ifndef _GLOO_VERTEXBUFFEROBJECT_H_
#define _GLOO_VERTEXBUFFEROBJECT_H_

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
        VertexBufferObject(const std::vector<Vertex> &_vertices);
        ~VertexBufferObject() = default;
        /**
         * Cast to GLuint.
         * Lets you use the objects of VertexBufferObject class in regular opengl calls.
         **/
        operator GLuint() const
        {
            return id;
        }
        void Bind();
        /**
         * Unbind the VertexBufferObject.
         **/
        void static UNBIND()
        {
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }
        void Delete();
    };

}

#endif // _GLOO_VERTEXBUFFEROBJECT_H_