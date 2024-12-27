#include "Engine.h"

#include <glad/glad.h>
#include <vector>

#include "Log.h"
#include "..\Window\Window.h"
#include "..\Shader\Shader.h"
#include "..\Mesh\Mesh.h"
#include "..\Input\Input.h"

Engine::Engine(unsigned int width, unsigned int height, std::string title)
{
	window = new Window(width, height, title);
}

Engine::~Engine()
{
	delete window;
}

const std::vector<Vertex> vertices = 
{
	{{0.5f,  0.5f, 0.0f}},
	{{0.5f, -0.5f, 0.0f}},
	{{-0.5f, -0.5f, 0.0f}},
	{{-0.5f,  0.5f, 0.0f}}
};

const std::vector<unsigned int> indices = {
	0, 1, 3,
	1, 2, 3
};

void Engine::run()
{
	window->create();

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		Log::error("Failed to initialize GLAD");

	InitInput(window->windowRef);

	Shader shader("default_shader.vert", "default_shader.frag");

	glm::vec4 color = { 1.0f, 0.0f, 0.2f, 1.0f };
	Mesh mesh(vertices, indices, color);

	while (!window->shouldClose())
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		mesh.draw(shader);

		glfwSwapBuffers(window->windowRef);
		processInput();
	}
	glfwDestroyWindow(window->windowRef);
	glfwTerminate();
}

int polygonMode = 0;
bool polygonModeKeyReleased = true;
void Engine::processInput()
{
	glfwPollEvents();

	if (IsKeyPressed(GLFW_KEY_ESCAPE))
		glfwSetWindowShouldClose(window->windowRef, true);

	if (IsKeyReleased(GLFW_KEY_F1) && !polygonModeKeyReleased) {
		polygonMode = (polygonMode + 1) % 3;
		polygonModeKeyReleased = true;
	}
	else if (IsKeyPressed(GLFW_KEY_F1)) {
		polygonModeKeyReleased = false;
	}

	switch (polygonMode)
	{
	case 0:
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		break;
	case 1:
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		break;
	case 2:
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
		break;
	default:
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		break;
	}
}
