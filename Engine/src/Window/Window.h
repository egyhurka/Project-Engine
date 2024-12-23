#pragma once
#include <GLFW/glfw3.h>

#include "..\Core\Log.h"

#include <string>

class Window
{
public:
	Window(unsigned int width, unsigned int height, std::string title);

	void create();
	inline const bool shouldClose() const { return glfwWindowShouldClose(windowRef); };

	int width, height;
	const char* title;
	GLFWwindow* windowRef;
private:

};

