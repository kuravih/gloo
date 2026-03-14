#ifndef _GLOO_FRAMEBUFFER_H_
#define _GLOO_FRAMEBUFFER_H_

#pragma once

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
        /**
         * Generate a Framebuffer.
         * Binds the created Framebuffer as a result.
         **/
        Framebuffer()
        {
            glGenFramebuffers(1, &id);
            Bind();
        }

        ~Framebuffer()
        {
            Delete();
        }

        /**
         * Cast to GLuint.
         * Lets you use the objects of Framebuffer class in regular opengl calls.
         **/
        operator GLuint() const
        {
            return id;
        }

        /**
         * Bind the Framebuffer.
         **/
        void Bind()
        {
            glBindFramebuffer(GL_FRAMEBUFFER, id);
        }

        /**
         * Unbind the Framebuffer.
         **/
        static void UNBIND()
        {
            glBindFramebuffer(GL_FRAMEBUFFER, 0);
        }

        /**
         * Delete the Framebuffer.
         **/
        void Delete()
        {
            glDeleteFramebuffers(1, &id);
        }
    };

}

#endif // _GLOO_FRAMEBUFFER_H_
