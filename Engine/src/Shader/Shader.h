#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "../Core/Log.h"

#include <string>
#include <filesystem>

struct UniformLocationResult {
	int location;
	bool success;
};

class Shader
{
public:
	Shader(std::string vertexFileName, std::string fragmentFileName);

	void use();

	unsigned int ID;

	UniformLocationResult getUniformLocation(const char* name);
	void setColor(const glm::vec4& color);

private:
	std::filesystem::path getPath(std::string fileName);
	std::string readShader(std::filesystem::path path);
	void checkCompileErrors(unsigned int shader, std::string type);
};