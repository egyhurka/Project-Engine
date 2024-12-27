#include "Engine.h"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>

#include "Log.h"
#include "..\Window\Window.h"
#include "..\Input\Input.h"
#include "..\Shader\Shader.h"
#include "..\Mesh\Mesh.h"
#include "..\Mesh\Geometry.h"


Engine::Engine(unsigned int width, unsigned int height, std::string title)
{
	window = new Window(width, height, title);
	screenWidth = static_cast<int>(width);
	screenHeight = static_cast<int>(height);
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

	Shader shader("default_shader.vert", "default_shader.frag");

	glm::vec4 color = { 1.0f, 0.0f, 0.2f, 1.0f };
	Mesh mesh(geometry::Cube.vertices, geometry::Cube.indices, color);

	while (!window->shouldClose())
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 projection = glm::mat4(1.0f);
		model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
		// Need to update screen variables
		projection = glm::perspective(glm::radians(45.0f), (float)screenWidth / (float)screenHeight, 0.1f, 100.0f);

		mesh.draw(shader, model, view, projection);

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
