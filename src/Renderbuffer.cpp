#include "gloo/Renderbuffer.h"

/**
 * Create a Renderbuffer.
 * Binds the created Renderbuffer as a result.
 **/
gloo::Renderbuffer::Renderbuffer()
{
    glGenRenderbuffers(1, &id);
    Bind();
}

/**
 * Delete the Renderbuffer.
 **/
void gloo::Renderbuffer::Delete()
{
    glDeleteRenderbuffers(1, &id);
}

/**
 * Bind the Renderbuffer.
 **/
void gloo::Renderbuffer::Bind()
{
    glBindRenderbuffer(GL_RENDERBUFFER, id);
}

/**
 * Setup Renderbuffer with a target texture.
 **/
void gloo::Renderbuffer::RenderToTexture(gloo::Texture &_target)
{
    Bind();
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, _target.width, _target.height);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, id);
    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, _target, 0);

    // Set the list of draw buffers.
    GLenum DrawBuffers[1] = {GL_COLOR_ATTACHMENT0};
    glDrawBuffers(1, DrawBuffers); // "1" is the size of DrawBuffers
}