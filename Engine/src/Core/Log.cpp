#include "Log.h"

#include <GLFW/glfw3.h>

void Log::debug(std::string message)
{
	std::cout << "[DEBUG] " << message << std::endl;
}

void Log::error(std::string error)
{
	std::cout << "\033[31m[ERROR] " << error << "\033[0m" << std::endl;
}

void Log::key(int key, int action)
{
    if (action == GLFW_PRESS)
        std::cout << "\033[32m[KEY_PRESS]\t\033[0m" << static_cast<char>(key) << " (" << key << ")" << std::endl;

    if (action == GLFW_RELEASE)
        std::cout << "\033[92m[KEY_RELEASE]\t\033[0m " << key << std::endl;
}

void Log::mouse(int button, int action)
{
    if (action == GLFW_PRESS)
        std::cout << "\033[33m[MOUSE_PRESS]\t\033[0m " << button << std::endl;

    if (action == GLFW_RELEASE)
        std::cout << "\033[93m[MOUSE_RELEASE]\t\033[0m " << button << std::endl;
}