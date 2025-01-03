#include "Input.h"

#include "..\Core\Log.h"

#include <vector>

std::vector<int> keyExceptions = { GLFW_KEY_W, GLFW_KEY_S, GLFW_KEY_A, GLFW_KEY_D, GLFW_KEY_Q, GLFW_KEY_E, GLFW_KEY_LEFT_SHIFT };

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (std::find(keyExceptions.begin(), keyExceptions.end(), key) == keyExceptions.end())
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

bool IsKeyReleased(int key) {
    return glfwGetKey(glfwGetCurrentContext(), key) == GLFW_RELEASE;
}

bool IsMouseButtonPressed(int button) {
    return glfwGetMouseButton(glfwGetCurrentContext(), button) == GLFW_PRESS;
}

glm::vec2 GetMousePosition() {
    double xpos, ypos;
    glfwGetCursorPos(glfwGetCurrentContext(), &xpos, &ypos);
    return glm::vec2((float)xpos, (float)ypos);
}