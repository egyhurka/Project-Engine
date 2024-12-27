#include <Core\Engine.h>

#include "test.h"

#include <iostream>

int main()
{
	Engine engine(800, 600, "Engine");

	engine.run();

	std::cin.get();

	return EXIT_SUCCESS;
}