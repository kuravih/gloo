#ifndef _GLOO_SHADER_H_
#define _GLOO_SHADER_H_

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <iostream>

namespace gloo
{

    std::string getFileContents(const char *_filename);

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
        Shader(Type _type);
        Shader(const std::string &_code, Type _type);
        ~Shader() = default;
        /**
         * Cast to GLuint.
         * Lets you use the objects of Shader class in regular opengl calls.
         **/
        operator GLuint() const
        {
            return id;
        }
        void Source(const std::string &_code);
        void Compile();
        void Delete();
        std::string GetInfoLog();
    };

}
#endif // _GLOO_SHADER_H_