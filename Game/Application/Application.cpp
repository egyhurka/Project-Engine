#include <Core\Engine.h>

#include "test.h"

#include <iostream>

int main()
{
	Engine engine(800, 600, "Engine");

	//Test::error("An error occurred: ", 404, " Not Found");


	engine.run();

	std::cin.get();

	return EXIT_SUCCESS;
}