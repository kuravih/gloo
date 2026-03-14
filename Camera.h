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

        Camera(glm::vec3 _position, glm::vec3 _lookat, glm::vec3 _up, float _fovy_deg = 45.0f, float _aspect = 1.0f, float _near = 0.1f, float _far = 100.0f)
            : position(_position), target(_lookat), up(_up), fov_rad(glm::radians(_fovy_deg)), aspect(_aspect), near(_near), far(_far)
        {
            Update();
        }

        void Update()
        {
            view = glm::lookAt(position, target, up);
            projection = glm::perspective(fov_rad, aspect, near, far);
            matrix = projection * view;
        }

        void setPosition(const glm::vec3 &_position)
        {
            position = _position;
            Update();
        }

        void setTarget(const glm::vec3 &_target)
        {
            target = _target;
            Update();
        }

        void setUp(const glm::vec3 &_up)
        {
            up = _up;
            Update();
        }

        void setFOV_rad(const float _fov_rad)
        {
            fov_rad = _fov_rad;
            Update();
        }

        void setFOV_deg(const float _fov_deg)
        {
            fov_rad = glm::radians(_fov_deg);
            Update();
        }

        void setAspect(const float _aspect)
        {
            aspect = _aspect;
            Update();
        }

        void setNear(const float _near)
        {
            near = _near;
            Update();
        }

        void setFar(const float _far)
        {
            far = _far;
            Update();
        }

        void Inputs(GLFWwindow *_window)
        {
            int width, height;
            glfwGetWindowSize(_window, &width, &height);

            if (glfwGetMouseButton(_window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
            {
                glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

                if (firstClick)
                {
                    glfwSetCursorPos(_window, (width / 2), (height / 2));
                    firstClick = false;
                }

                double mouseX;
                double mouseY;
                glfwGetCursorPos(_window, &mouseX, &mouseY);

                float rotX = sensitivity * (float)(mouseY - (height / 2));
                float rotY = sensitivity * (float)(mouseX - (width / 2));

                glm::vec3 newPosition = glm::rotate(position, glm::radians(rotX), glm::normalize(glm::cross(position, up)));

                if (abs(glm::angle(newPosition, up) - glm::radians(90.0f)) <= glm::radians(85.0f))
                    position = newPosition;

                position = glm::rotate(position, glm::radians(-rotY), up);

                glfwSetCursorPos(_window, (width / 2), (height / 2));
            }
            else if (glfwGetMouseButton(_window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
            {
                glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
                firstClick = true;
            }

            Update();
        }
    };

}

#endif // _GLOO_CAMERA_H_
