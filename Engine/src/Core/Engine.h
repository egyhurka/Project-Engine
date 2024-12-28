#pragma once

#include <string>

class Window;
class Camera;
class Renderer;

class Engine 
{
public:
	Engine(unsigned int width, unsigned int height, std::string title);
	~Engine();

	void run();

	float deltaTime = 0.0f;

private:
	Window* window;
	Camera* cam;
	Renderer* renderer;
	int screenWidth, screenHeight;

	void processInput();
	void deltaTimeCalculation();
};