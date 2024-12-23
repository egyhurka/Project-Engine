#pragma once

#include <string>

class Window;

class Engine 
{
public:
	Engine(unsigned int width, unsigned int height, std::string title);
	~Engine();

	void run();

private:
	Window* window;

	void processInput();
};