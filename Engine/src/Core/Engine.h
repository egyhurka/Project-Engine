#pragma once

#include <string>
#include <vector>

#include "TypedefGLM.h"

#define ENGINE_CUBE 1

class Window;
class Camera;
class Renderer;

class GameObject;

class Engine 
{
public:
	Engine(unsigned int width, unsigned int height, std::string title);
	~Engine();

	void run();
	
	void addObject(GameObject* object);

	float deltaTime = 0.0f;

private:
	Window* window;
	Camera* cam;
	Renderer* renderer;
	int screenWidth, screenHeight;

	std::vector<GameObject*> sceneObjects;

	void processInput();
	void deltaTimeCalculation();
};