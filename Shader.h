#ifndef _GLOO_SHADER_H_
#define _GLOO_SHADER_H_

#pragma once

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <iostream>

namespace gloo
{

    /**
     * Read a text file and outputs a string with everything in the file.
     * \param _filename shader source filename.
     **/
    inline std::string getFileContents(const char *_filename)
    {
        std::ifstream in(_filename, std::ios::binary);
        if (in)
        {
            std::string contents;
            in.seekg(0, std::ios::end);
            contents.resize(in.tellg());
            in.seekg(0, std::ios::beg);
            in.read(&contents[0], contents.size());
            in.close();
            return (contents);
        }
        throw(errno);
    }

    /**
     * Shader compile exception class.
     **/
    class CompileException : public std::exception
    {
    public:
        CompileException(const std::string &str) throw() : infoLog(str) {}
        ~CompileException() throw() {}
        virtual const char *what() const throw()
        {
            return infoLog.c_str();
        }

    private:
        std::string infoLog;
    };

    /**
     * Shader class.
     **/
    class Shader
    {
    public:
        /*! Type of Shader */
        enum class Type : GLenum
        {
            Vertex = GL_VERTEX_SHADER,     /*!< Vertex shader */
            Fragment = GL_FRAGMENT_SHADER, /*!< Fragment shader */
            Geometry = GL_GEOMETRY_SHADER  /*!< geometry shader */
        };

    private:
        GLuint id;

    public:
        Shader() = default;

        /**
         * Create a Shader of a given type.
         * \param _type Shader type.
         **/
        Shader(Type _type)
        {
            id = glCreateShader((GLenum)_type);
        }

        /**
         * Create a Shader.
         * \param _code Shader code.
         * \param _type Shader type.
         **/
        Shader(const std::string &_code, Type _type) : Shader(_type)
        {
            Source(_code);
            Compile();
        }

        ~Shader()
        {
            Delete();
        }

        /**
         * Cast to GLuint.
         * Lets you use the objects of Shader class in regular opengl calls.
         **/
        operator GLuint() const
        {
            return id;
        }

        /**
         * Load code to the shader.
         * \param _code Shader code.
         **/
        void Source(const std::string &_code)
        {
            const char *code = _code.c_str();
            glShaderSource(id, 1, &code, NULL);
        }

        /**
         * Compile the shader.
         **/
        void Compile()
        {
            glCompileShader(id);
            GLint res;
            glGetShaderiv(id, GL_COMPILE_STATUS, &res);
            if (res == GL_FALSE)
                throw CompileException(GetInfoLog());
        }

        /**
         * Delete the Shader.
         **/
        void Delete()
        {
            glDeleteShader(id);
        }

        /**
         * Get the shader info log.
         **/
        std::string GetInfoLog()
        {
            GLint res;
            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &res);
            if (res > 0)
            {
                std::string infoLog(res, 0);
                glGetShaderInfoLog(id, res, &res, &infoLog[0]);
                return infoLog;
            }
            else
            {
                return "";
            }
        }
    };

}
#endif // _GLOO_SHADER_H_
