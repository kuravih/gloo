#include "gloo/Framebuffer.h"

/**
 * Generate a Framebuffer.
 * Binds the created Framebuffer as a result.
 **/
gloo::Framebuffer::Framebuffer()
{
    glGenFramebuffers(1, &id);
    Bind();
}

/**
 * Delete the Framebuffer.
 **/
void gloo::Framebuffer::Delete()
{
    glDeleteFramebuffers(1, &id);
}

/**
 * Bind the Framebuffer.
 **/
void gloo::Framebuffer::Bind()
{
    glBindFramebuffer(GL_FRAMEBUFFER, id);
}