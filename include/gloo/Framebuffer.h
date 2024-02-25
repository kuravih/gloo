#ifndef _GLOO_FRAMEBUFFER_H_
#define _GLOO_FRAMEBUFFER_H_

#include <glad/glad.h>

namespace gloo
{

    /**
     * Framebuffer class.
     **/
    class Framebuffer
    {
    private:
        GLuint id;

    public:
        Framebuffer();
        ~Framebuffer() = default;
        /**
         * Cast to GLuint.
         * Lets you use the objects of Framebuffer class in regular opengl calls.
         **/
        operator GLuint() const
        {
            return id;
        }
        void Delete();
        void Bind();
        /**
         * Unbind the Framebuffer.
         **/
        static void UNBIND()
        {
            glBindFramebuffer(GL_FRAMEBUFFER, 0);
        }
    };

}

#endif // _GLOO_FRAMEBUFFER_H_