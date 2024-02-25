#include "gloo/Texture.h"

/**
 * Create a Texture.
 * Binds the created VertexBufferObject as a result.
 * \param _vertices The vertex array.
 * \param _size The size of the vertex array.
 **/
gloo::Texture::Texture(const void *_data, int _width, int _height, Type _type, InternalFormat _internalFormat, Format _format, Slot _slot, Target _target) : id(0), target(_target), type(_type), internalFormat(_internalFormat), format(_format), slot(_slot), width(_width), height(_height), aspectRatio((float)_height / (float)_width)
{
    // Generates an OpenGL texture object
    glGenTextures(1, &id);
    // Assigns the texture to a Texture Unit
    Activate();
    Bind();

    // Configures the type of algorithm that is used to make the image smaller or bigger
    glTexParameteri((GLenum)target, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
    glTexParameteri((GLenum)target, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // Configures the way the texture repeats (if it does at all)
    glTexParameteri((GLenum)target, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri((GLenum)target, GL_TEXTURE_WRAP_T, GL_REPEAT);

    Update(_data);
}

gloo::Texture::Texture(int _width, int _height, Type _type, InternalFormat _internalFormat, Format _format, Slot _slot, Target _target) : gloo::Texture::Texture(0, _width, _height, _type, _internalFormat, _format, _slot, _target) {}

/**
 * Bind the Texture.
 **/
void gloo::Texture::Bind()
{
    glBindTexture((GLenum)target, id);
}

/**
 * Unbind the Texture.
 **/
void gloo::Texture::Unbind()
{
    glBindTexture((GLenum)target, 0);
}

/**
 * Activate the Texture.
 **/
void gloo::Texture::Activate()
{
    glActiveTexture((GLenum)slot);
}

/**
 * Delete the Texture.
 **/
void gloo::Texture::Delete()
{
    glDeleteTextures(1, &id);
}

/**
 * Update the Texture.
 **/
void gloo::Texture::Update(const void *_data)
{
    Bind();
    glTexImage2D((GLenum)target, 0, (GLint)internalFormat, width, height, 0, (GLenum)format, (GLenum)type, _data);
    glGenerateMipmap((GLenum)target);
}

/**
 * Update the Texture.
 **/
void gloo::Texture::Update()
{
    Bind();
    glGenerateMipmap((GLenum)target);
}