#ifndef _GLOO_RENDERBUFFER_H_
#define _GLOO_RENDERBUFFER_H_

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
        Renderbuffer();
        ~Renderbuffer() = default;
        /**
         * Cast to GLuint.
         * Lets you use the objects of Renderbuffer class in regular opengl calls .
         **/
        operator GLuint() const
        {
            return id;
        }
        void Delete();
        void Bind();
        /**
         * Unbind the Renderbuffer.
         **/
        static void UNBIND()
        {
            glBindRenderbuffer(GL_RENDERBUFFER, 0);
        }
        void RenderToTexture(Texture &_target);
    };

}

#endif // _GLOO_RENDERBUFFER_H_