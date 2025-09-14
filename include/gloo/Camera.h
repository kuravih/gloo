#ifndef _GLOO_CAMERA_H_
#define _GLOO_CAMERA_H_

#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <GLFW/glfw3.h>

namespace gloo
{

    class Camera
    {
    public:
        glm::vec3 position, target, up;
        float fov_rad, aspect, near, far;
        glm::mat4 view, projection, matrix;
        bool firstClick = true;
        float speed = 1.0f;
        float sensitivity = 1.0f;
        Camera(glm::vec3 _position, glm::vec3 _lookat, glm::vec3 _up, float _fovy_deg = 45.0f, float _aspect = 1.0f, float _near = 0.1f, float _far = 100.0f);
        void setPosition(const glm::vec3 &_position);
        void setTarget(const glm::vec3 &_target);
        void setUp(const glm::vec3 &_up);
        void setFOV_rad(const float _fov_rad);
        void setFOV_deg(const float _fov_deg);
        void setAspect(const float _aspect);
        void setNear(const float _near);
        void setFar(const float _far);
        void Update();
        void Inputs(GLFWwindow *_window);
    };

}

#endif // _GLOO_CAMERA_H_