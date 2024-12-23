#include "Input.h"

#include "..\Core\Log.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    Log::key(key, action);
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    Log::mouse(button, action);
}

void InitInput(GLFWwindow* window)
{
    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
}

bool IsKeyPressed(int key) {
    return glfwGetKey(glfwGetCurrentContext(), key) == GLFW_PRESS;
}

bool IsMouseButtonPressed(int button) {
    return glfwGetMouseButton(glfwGetCurrentContext(), button) == GLFW_PRESS;
}

void GetMousePosition(double& xpos, double& ypos) {
    glfwGetCursorPos(glfwGetCurrentContext(), &xpos, &ypos);
}