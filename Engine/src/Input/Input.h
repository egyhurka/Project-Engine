#pragma once

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

void InitInput(GLFWwindow* window);

bool IsKeyPressed(int key);
bool IsKeyReleased(int key);
bool IsMouseButtonPressed(int button);
glm::vec2 GetMousePosition();