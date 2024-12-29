#pragma once

#include <GLFW/glfw3.h>

#include <string>

#include "..\Core\Log.h"

class Window
{
public:
	Window(unsigned int width, unsigned int height, std::string title);

	void create();

	inline const bool shouldClose() const { return glfwWindowShouldClose(windowRef); };

	int width, height;
	float ratio;
	const char* title;
	GLFWwindow* windowRef;
private:
	
};

