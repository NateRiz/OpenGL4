#include "Camera.h"
#include "World.h"

Camera::Camera(): Object3d() {
    glfwSetCursorPosCallback(World::GetWorld().GetWindowManager().GetWindow(), MouseCallback);
}

void Camera::Tick(float delta) {
    //printf("%f %f %f\n", GetTransform()->GetForward().x, GetTransform()->GetForward().y, GetTransform()->GetForward().z);
}

void Camera::MouseCallback(GLFWwindow*, double x, double y){
    Camera::mCurrentMouseX = x;
    Camera::mCurrentMouseY = y;
}

void Camera::ProcessMouseMovement(float delta)
{
    double deltaX = Camera::mCurrentMouseX - mLastMouseX;
    double deltaY = Camera::mCurrentMouseY - mLastMouseY;

    float sensitivity = delta * 2.5f;
    yaw += deltaX * sensitivity;
    pitch -= deltaY * sensitivity;

    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    /*glm::vec3 rotation = GetTransform()->GetRotation();
    rotation.x = glm::radians(pitch);
    rotation.y = glm::radians(yaw);
    GetTransform()->SetRotation(rotation);*/
}

void Camera::ProcessInput(float delta) {
    /*
    float camSpeed = delta * 5.5f;
    glm::vec3 location = GetTransform()->GetLocation();

    if (glfwGetKey(GetWorld()->GetWindow(), GLFW_KEY_W) == GLFW_PRESS)
        location += camSpeed * GetTransform()->GetForward();
    else if (glfwGetKey(GetWorld()->GetWindow(), GLFW_KEY_S) == GLFW_PRESS)
        location -= camSpeed * GetTransform()->GetForward();

    if (glfwGetKey(GetWorld()->GetWindow(), GLFW_KEY_A) == GLFW_PRESS)
        location -= camSpeed * (glm::cross(GetTransform()->GetForward(), GetTransform()->GetUp()));
    else if (glfwGetKey(GetWorld()->GetWindow(), GLFW_KEY_D) == GLFW_PRESS)
        location += camSpeed * (glm::cross(GetTransform()->GetForward(), GetTransform()->GetUp()));

    GetTransform()->SetLocation(location);
     */
}