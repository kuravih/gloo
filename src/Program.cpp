#include "gloo/Program.h"

#include <glm/gtc/type_ptr.hpp>

/**
 * Create a Shader Program.
 * Links the created hader Program as a result.
 * \param _vertex Vertex shader.
 **/
gloo::Program::Program(const Shader &_vertex)
{
    // Create Shader Program Object and get its reference
    id = glCreateProgram();
    // Attach the Vertex and Fragment Shaders to the Shader Program
    glAttachShader(id, _vertex); // Wrap-up/Link all the shaders together into the Shader Program
    glLinkProgram(id);
}

/**
 * Create a Shader Program.
 * Links the created hader Program as a result.
 * \param _vertex Vertex shader.
 * \param _fragment Fragment shader.
 **/
gloo::Program::Program(const Shader &_vertex, const Shader &_fragment)
{
    // Create Shader Program Object and get its reference
    id = glCreateProgram();
    // Attach the Vertex and Fragment Shaders to the Shader Program
    glAttachShader(id, _vertex);
    glAttachShader(id, _fragment); // Wrap-up/Link all the shaders together into the Shader Program
    glLinkProgram(id);
}

/**
 * Create a Shader Program.
 * Links the created hader Program as a result.
 * \param _vertex Vertex shader.
 * \param _fragment Fragment shader.
 * \param _geometry Geometry shader.
 **/
gloo::Program::Program(const Shader &_vertex, const Shader &_fragment, const Shader &_geometry)
{
    // Create Shader Program Object and get its reference
    id = glCreateProgram();
    // Attach the Vertex and Fragment Shaders to the Shader Program
    glAttachShader(id, _vertex);
    glAttachShader(id, _fragment);
    glAttachShader(id, _geometry); // Wrap-up/Link all the shaders together into the Shader Program
    glLinkProgram(id);
}

/**
 * Activate the Shader Program.
 **/
void gloo::Program::Activate()
{
    glUseProgram(id);
}

/**
 * Delete the Shader Program.
 **/
void gloo::Program::Delete()
{
    glDeleteProgram(id);
}

/**
 * Link GLuint to shader program uniform.
 **/
void gloo::Program::Uniform(const char *_uniform, const GLuint _unit)
{
    Activate();
    glUniform1i(glGetUniformLocation(id, _uniform), _unit);
}

/**
 * Link Texture to shader program uniform.
 **/
void gloo::Program::Uniform(const char *_uniform, const gloo::Texture &_texture)
{
    Activate();
    glUniform1i(glGetUniformLocation(id, _uniform), (GLenum)((int)_texture.slot - (int)gloo::Texture::Slot::slot00));
}

/**
 * Link 4x4 Matrix to shader program uniform.
 **/
void gloo::Program::Uniform(const char *_uniform, const glm::mat4 &_mat4)
{
    Activate();
    glUniformMatrix4fv(glGetUniformLocation(id, _uniform), 1, GL_FALSE, glm::value_ptr(_mat4));
}

/**
 * Link 4 element Vector to shader program uniform.
 **/
void gloo::Program::Uniform(const char *_uniform, const glm::vec4 &_vec4)
{
    Activate();
    glUniform4f(glGetUniformLocation(id, _uniform), _vec4.x, _vec4.y, _vec4.z, _vec4.w);
}

/**
 * Link 3 element Vector to shader program uniform.
 **/
void gloo::Program::Uniform(const char *_uniform, const glm::vec3 &_vec3)
{
    Activate();
    glUniform3f(glGetUniformLocation(id, _uniform), _vec3.x, _vec3.y, _vec3.z);
}

/**
 * Link 2 element Vector to shader program uniform.
 **/
void gloo::Program::Uniform(const char *_uniform, const glm::vec2 &_vec2)
{
    Activate();
    glUniform2f(glGetUniformLocation(id, _uniform), _vec2.x, _vec2.y);
}

/**
 * Link float to shader program uniform.
 **/
void gloo::Program::Uniform(const char *_uniform, const float _float)
{
    Activate();
    glUniform1f(glGetUniformLocation(id, _uniform), _float);
}

/**
 * Link float to shader program uniform.
 **/
void gloo::Program::Uniform(const char *_uniform, const int _int)
{
    Activate();
    glUniform1i(glGetUniformLocation(id, _uniform), _int);
}
