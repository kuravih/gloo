#ifndef _GLOO_PROGRAM_H_
#define _GLOO_PROGRAM_H_

#pragma once

#include "gloo/Shader.h"
#include "gloo/Texture.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>

namespace gloo
{

    /**
     * Shader program class.
     **/
    class Program
    {
    private:
        GLuint id;

    public:
        Program() = default;

        /**
         * Create a Shader Program with a vertex shader.
         **/
        Program(const Shader &_vertex)
        {
            id = glCreateProgram();
            glAttachShader(id, _vertex);
            glLinkProgram(id);
        }

        /**
         * Create a Shader Program with vertex and fragment shaders.
         **/
        Program(const Shader &_vertex, const Shader &_fragment)
        {
            id = glCreateProgram();
            glAttachShader(id, _vertex);
            glAttachShader(id, _fragment);
            glLinkProgram(id);
        }

        /**
         * Create a Shader Program with vertex, fragment and geometry shaders.
         **/
        Program(const Shader &_vertex, const Shader &_fragment, const Shader &_geometry)
        {
            id = glCreateProgram();
            glAttachShader(id, _vertex);
            glAttachShader(id, _fragment);
            glAttachShader(id, _geometry);
            glLinkProgram(id);
        }

        ~Program()
        {
            Delete();
        }

        /**
         * Cast to GLuint.
         * Lets you use the objects of Program class in regular opengl calls.
         **/
        operator GLuint() const
        {
            return id;
        }

        /**
         * Activate the Shader Program.
         **/
        void Activate()
        {
            glUseProgram(id);
        }

        /**
         * Deactivate the Shader Program.
         **/
        static void DEACTIVATE()
        {
            glUseProgram(0);
        }

        /**
         * Delete the Shader Program.
         **/
        void Delete()
        {
            glDeleteProgram(id);
        }

        /**
         * Link GLuint to shader program uniform.
         **/
        void Uniform(const char *_uniform, const GLuint _unit)
        {
            Activate();
            glUniform1i(glGetUniformLocation(id, _uniform), _unit);
        }

        /**
         * Link Texture to shader program uniform.
         **/
        void Uniform(const char *_uniform, const Texture &_texture)
        {
            Activate();
            glUniform1i(glGetUniformLocation(id, _uniform), (GLenum)((int)_texture.slot - (int)Texture::Slot::slot00));
        }

        /**
         * Link 4x4 Matrix to shader program uniform.
         **/
        void Uniform(const char *_uniform, const glm::mat4 &_mat4)
        {
            Activate();
            glUniformMatrix4fv(glGetUniformLocation(id, _uniform), 1, GL_FALSE, glm::value_ptr(_mat4));
        }

        /**
         * Link 4 element Vector to shader program uniform.
         **/
        void Uniform(const char *_uniform, const glm::vec4 &_vec4)
        {
            Activate();
            glUniform4f(glGetUniformLocation(id, _uniform), _vec4.x, _vec4.y, _vec4.z, _vec4.w);
        }

        /**
         * Link 3 element Vector to shader program uniform.
         **/
        void Uniform(const char *_uniform, const glm::vec3 &_vec3)
        {
            Activate();
            glUniform3f(glGetUniformLocation(id, _uniform), _vec3.x, _vec3.y, _vec3.z);
        }

        /**
         * Link 2 element Vector to shader program uniform.
         **/
        void Uniform(const char *_uniform, const glm::vec2 &_vec2)
        {
            Activate();
            glUniform2f(glGetUniformLocation(id, _uniform), _vec2.x, _vec2.y);
        }

        /**
         * Link float to shader program uniform.
         **/
        void Uniform(const char *_uniform, const float _float)
        {
            Activate();
            glUniform1f(glGetUniformLocation(id, _uniform), _float);
        }

        /**
         * Link int to shader program uniform.
         **/
        void Uniform(const char *_uniform, const int _int)
        {
            Activate();
            glUniform1i(glGetUniformLocation(id, _uniform), _int);
        }
    };

}
#endif // _GLOO_PROGRAM_H_
