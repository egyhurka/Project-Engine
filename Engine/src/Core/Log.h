#pragma once

#include <glm/glm.hpp>

#include <iostream>
#include <string>
#include <optional>

namespace Log
{
	void debug(std::string message);
	void error(std::string error);
	void key(int key, int action);
	void mouse(int button, int action);

	class Vector
	{
	public:
		static void vec3(glm::vec3 value, std::optional<std::string> name = "");

	private:
		static glm::vec3 lastValue;
	};
}
