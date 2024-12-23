#pragma once

#include <iostream>
#include <string>

namespace Log
{
	void debug(std::string message);	// DEBUG PRINT
	void error(std::string error);		// ERROR PRINT
	void key(int key, int action);		// KEY PRINT
	void mouse(int button, int action); // MOUSE PRINT
}
