#include "gloo/Camera.h"

gloo::Camera::Camera(glm::vec3 _position, glm::vec3 _target, glm::vec3 _up, float _fov_deg, float _aspect, float _near, float _far) : position(_position), target(_target), up(_up), fov_rad(glm::radians(_fov_deg)), aspect(_aspect), near(_near), far(_far)
{
    Update();
}

void gloo::Camera::Update()
{
    view = glm::lookAt(position, target, up);
    projection = glm::perspective(fov_rad, aspect, near, far);
    matrix = projection * view;
}

void gloo::Camera::setPosition(const glm::vec3 &_position)
{
    position = _position;
    Update();
}

void gloo::Camera::setTarget(const glm::vec3 &_target)
{
    target = _target;
    Update();
}

void gloo::Camera::setUp(const glm::vec3 &_up)
{
    up = _up;
    Update();
}

void gloo::Camera::setFOV_rad(const float _fov_rad)
{
    fov_rad = _fov_rad;
    Update();
}

void gloo::Camera::setFOV_deg(const float _fov_deg)
{
    fov_rad = glm::radians(_fov_deg);
    Update();
}

void gloo::Camera::setAspect(const float _aspect)
{
    aspect = _aspect;
    Update();
}

void gloo::Camera::setNear(const float _near)
{
    near = _near;
    Update();
}

void gloo::Camera::setFar(const float _far)
{
    far = _far;
    Update();
}

void gloo::Camera::Inputs(GLFWwindow *_window)
{

    int width, height;
    glfwGetWindowSize(_window, &width, &height);

    // Handles mouse inputs
    if (glfwGetMouseButton(_window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
    {
        // Hides mouse cursor
        glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

        // Prevents camera from jumping on the first click
        if (firstClick)
        {
            glfwSetCursorPos(_window, (width / 2), (height / 2));
            firstClick = false;
        }

        // Stores the coordinates of the cursor
        double mouseX;
        double mouseY;
        // Fetches the coordinates of the cursor
        glfwGetCursorPos(_window, &mouseX, &mouseY);

        // Normalizes and shifts the coordinates of the cursor such that they begin in the middle of the screen
        // and then "transforms" them into degrees
        float rotX = sensitivity * (float)(mouseY - (height / 2));
        float rotY = sensitivity * (float)(mouseX - (width / 2));

        // Calculates upcoming vertical change in the Position
        glm::vec3 newPosition = glm::rotate(position, glm::radians(rotX), glm::normalize(glm::cross(position, up)));

        // Decides whether or not the next vertical Position is legal or not
        if (abs(glm::angle(newPosition, up) - glm::radians(90.0f)) <= glm::radians(85.0f))
            position = newPosition;

        // Rotates the Position left and right
        position = glm::rotate(position, glm::radians(-rotY), up);

        // Sets mouse cursor to the middle of the screen so that it doesn't end up roaming around
        glfwSetCursorPos(_window, (width / 2), (height / 2));
    }
    else if (glfwGetMouseButton(_window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
    {
        // Un-hides cursor since camera is not looking around anymore
        glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        // Makes sure the next time the camera looks around it doesn't jump
        firstClick = true;
    }

    Update();
}