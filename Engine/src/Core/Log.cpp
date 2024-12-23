#include "Log.h"

void Log::dprint(std::string message)
{
	std::cout << "[DEBUG] " << message << std::endl;
}

void Log::eprint(std::string error)
{
	std::cout << "\033[31m[ERROR] " << error << "\033[0m" << std::endl;
}
