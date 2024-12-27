#include "Engine.h"

#include <glad/glad.h>

#include "Log.h"
#include "..\Window\Window.h"
#include "..\Shader\Shader.h"
#include "..\Input\Input.h"

Engine::Engine(unsigned int width, unsigned int height, std::string title)
{
	window = new Window(width, height, title);
}

Engine::~Engine()
{
	delete window;
}

void Engine::run()
{
	window->create();

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		Log::error("Failed to initialize GLAD");

	InitInput(window->windowRef);


	Shader shader("C:\\Programoz�s\\cpp\\Graphics\\OpenGL\\Project Engine\\Engine\\src\\Shader\\Source\\default_shader.vert", "C:\\Programoz�s\\cpp\\Graphics\\OpenGL\\Project Engine\\Engine\\src\\Shader\\Source\\default_shader.frag");



	while (!window->shouldClose())
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);



		glfwSwapBuffers(window->windowRef);
		processInput();
	}
	glfwDestroyWindow(window->windowRef);
	glfwTerminate();
}

void Engine::processInput()
{
	glfwPollEvents();

	if (IsKeyPressed(GLFW_KEY_ESCAPE))
		glfwSetWindowShouldClose(window->windowRef, true);
}
