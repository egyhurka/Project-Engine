#include "Window.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

Window::Window(unsigned int width, unsigned int height, std::string title) : windowRef(NULL), ratio((float)width / (float) height)
{
	if (width == 0)
		Log::error("Window width cannot be zero");

	if (height == 0)
		Log::error("Window height cannot be zero");

	if (title == "")
		title = "Engine";

	if (!glfwInit())
		Log::error("Failed to initialize GLFW!");

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	this->width = static_cast<int>(width);
	this->height = static_cast<int>(height);
	this->title = title.c_str();
}

void Window::create()
{
	windowRef = glfwCreateWindow(width, height, title, NULL, NULL);

	if (!windowRef)
	{
		glfwTerminate();
		Log::error("Failed to create window!");
	}

	glfwMakeContextCurrent(windowRef);
	glfwSetWindowUserPointer(windowRef, this);
	glfwSetFramebufferSizeCallback(windowRef, framebuffer_size_callback);

	glfwSetInputMode(windowRef, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPos(windowRef, width / 2.0, height / 2.0);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	Window* win = static_cast<Window*>(glfwGetWindowUserPointer(window));

	if (win)
		win->ratio = (float)width / (float)height;
	glViewport(0, 0, width, height);
}