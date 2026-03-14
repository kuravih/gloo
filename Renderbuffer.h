#ifndef _GLOO_RENDERBUFFER_H_
#define _GLOO_RENDERBUFFER_H_

#pragma once

#include "gloo/Texture.h"

#include <glad/glad.h>

namespace gloo
{

    /**
     * Renderbuffer class.
     **/
    class Renderbuffer
    {
    private:
        GLuint id;

    public:
        /**
         * Create a Renderbuffer.
         * Binds the created Renderbuffer as a result.
         **/
        Renderbuffer()
        {
            glGenRenderbuffers(1, &id);
            Bind();
        }

        ~Renderbuffer()
        {
            Delete();
        }

        /**
         * Cast to GLuint.
         * Lets you use the objects of Renderbuffer class in regular opengl calls.
         **/
        operator GLuint() const
        {
            return id;
        }

        /**
         * Bind the Renderbuffer.
         **/
        void Bind()
        {
            glBindRenderbuffer(GL_RENDERBUFFER, id);
        }

        /**
         * Unbind the Renderbuffer.
         **/
        static void UNBIND()
        {
            glBindRenderbuffer(GL_RENDERBUFFER, 0);
        }

        /**
         * Delete the Renderbuffer.
         **/
        void Delete()
        {
            glDeleteRenderbuffers(1, &id);
        }

        /**
         * Setup Renderbuffer with a target texture.
         **/
        void RenderToTexture(Texture &_target)
        {
            Bind();
            glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, _target.width, _target.height);
            glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, id);
            glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, _target, 0);

            GLenum DrawBuffers[1] = {GL_COLOR_ATTACHMENT0};
            glDrawBuffers(1, DrawBuffers);
        }
    };

}

#endif // _GLOO_RENDERBUFFER_H_
