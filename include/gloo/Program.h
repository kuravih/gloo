#ifndef _GLOO_PROGRAM_H_
#define _GLOO_PROGRAM_H_

#include "gloo/Shader.h"
#include "gloo/Texture.h"

#include <glm/glm.hpp>
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
        Program(const Shader &vertex);
        Program(const Shader &vertex, const Shader &fragment);
        Program(const Shader &vertex, const Shader &fragment, const Shader &geometry);
        ~Program() = default;
        /**
         * Cast to GLuint.
         * Lets you use the objects of Shader Program class in regular opengl calls.
         **/
        operator GLuint() const
        {
            return id;
        }
        void Activate();
        /**
         * Deactivate the Shader Program.
         **/
        static void DEACTIVATE()
        {
            glUseProgram(0);
        }
        void Delete();
        void Uniform(const char *_uniform, GLuint _unit);
        void Uniform(const char *_uniform, Texture &_texture);
        void Uniform(const char *_uniform, glm::mat4 &_mat4);
        void Uniform(const char *_uniform, glm::vec4 &_vec4);
        void Uniform(const char *_uniform, glm::vec3 &_vec3);
        void Uniform(const char *_uniform, glm::vec2 &_vec2);
        void Uniform(const char *_uniform, float _float);
        void Uniform(const char *_uniform, int _int);

    private:
        // Checks if the different Programs have compiled properly
        void compileErrors(unsigned int _shader, const char *_type);
    };

}
#endif // _GLOO_PROGRAM_H_