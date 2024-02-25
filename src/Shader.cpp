#include "gloo/Shader.h"

/**
 * Read a text file and outputs a string with everything in the file.
 * \param _filename shader source filename.
 **/
std::string gloo::getFileContents(const char *_filename)
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
 * Create a Shader of a given type.
 * \param _type Shader type.
 **/
gloo::Shader::Shader(gloo::Shader::Type _type)
{
    id = glCreateShader((GLenum)_type);
}

/**
 * Create a Shader.
 * \param _code Shader code.
 * \param _type Shader type.
 **/
gloo::Shader::Shader(const std::string &_code, gloo::Shader::Type _type) : gloo::Shader::Shader(_type)
{
    Source(_code);
    Compile();
}

/**
 * Load code to the shader.
 * \param _code Shader code.
 **/
void gloo::Shader::Source(const std::string &_code)
{
    // Convert the shader source strings into character arrays.
    const char *code = _code.c_str();
    glShaderSource(id, 1, &code, NULL);
}

/**
 * Compile the shader
 **/
void gloo::Shader::Compile()
{
    glCompileShader(id);
    GLint res;
    glGetShaderiv(id, GL_COMPILE_STATUS, &res);
    if (res == GL_FALSE)
        throw CompileException(GetInfoLog());
}

/**
 * Delete the Shader
 **/
void gloo::Shader::Delete()
{
    glDeleteShader(id);
}

std::string gloo::Shader::GetInfoLog()
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