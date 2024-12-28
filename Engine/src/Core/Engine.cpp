#include "Engine.h"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>

#include "Log.h"
#include "..\Window\Window.h"
#include "..\Input\Input.h"
#include "..\Camera\Camera.h"
#include "..\Shader\Shader.h"
#include "..\Mesh\Mesh.h"
#include "..\Mesh\Geometry.h"


Engine::Engine(unsigned int width, unsigned int height, std::string title)
{
	window = new Window(width, height, title);
	cam = new Camera(window->ratio);

	screenWidth = static_cast<int>(width);
	screenHeight = static_cast<int>(height);
}

Engine::~Engine()
{
	delete window;
	delete cam;
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
		// per-frame time logic
		deltaTimeCalculation();

		// input
		processInput();

		// render
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// camera/view transformation
		cam->update(window->ratio);

		// update
		mesh.update();

		mesh.translate(glm::vec3(0.0f, 0.0f, -3.0f));
		mesh.rotate();

		mesh.draw(shader, cam->view, cam->projection);

		glfwSwapBuffers(window->windowRef);
		glfwPollEvents();
	}
	glfwDestroyWindow(window->windowRef);
	glfwTerminate();
}

int polygonMode = 0;
bool polygonModeKeyReleased = true;
float lastX = 0.0f;
float lastY = 0.0f;
bool firstMouse = true;
void Engine::processInput()
{
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

	if (IsKeyPressed(GLFW_KEY_W))
		cam->ProcessKeyboard(FORWARD, deltaTime);
	if (IsKeyPressed(GLFW_KEY_S))
		cam->ProcessKeyboard(BACKWARD, deltaTime);
	if (IsKeyPressed(GLFW_KEY_A))
		cam->ProcessKeyboard(LEFT, deltaTime);
	if (IsKeyPressed(GLFW_KEY_D))
		cam->ProcessKeyboard(RIGHT, deltaTime);
	if (IsKeyPressed(GLFW_KEY_E))
		cam->ProcessKeyboard(UP, deltaTime);
	if (IsKeyPressed(GLFW_KEY_Q))
		cam->ProcessKeyboard(DOWN, deltaTime);

	glm::vec2 mousePosition = GetMousePosition();

	if (firstMouse)
	{
		lastX = mousePosition.x;
		lastY = mousePosition.y;
		firstMouse = false;
	}

	float xoffset = mousePosition.x - lastX;
	float yoffset = lastY - mousePosition.y;

	lastX = mousePosition.x;
	lastY = mousePosition.y;

	cam->ProcessMouseMovement(xoffset, yoffset);
}

float lastFrameTime = 0.0f;
void Engine::deltaTimeCalculation()
{
	float currentFrame = static_cast<float>(glfwGetTime());
	deltaTime = currentFrame - lastFrameTime;
	lastFrameTime = currentFrame;
}