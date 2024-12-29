#include <Engine.h>
#include <GameObject/GameObject.h>

#include <iostream>
#include <optional>

int main()
{
	Engine engine(800, 600, "Engine");

	GameObject object();

	engine.run();

	std::cin.get();

	return EXIT_SUCCESS;
}