#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <string>
#include <filesystem>

#include "../Core/Log.h"

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

	UniformLocationResult getUniformLocation(const char* uniform);
	void setColor(const glm::vec4& color);
	void setView(const glm::mat4& view);

	void setUniformMat4(const char* uniform, const glm::mat4& mat);

private:
	std::filesystem::path getPath(std::string fileName);
	std::string readShader(std::filesystem::path path);
	void checkCompileErrors(unsigned int shader, std::string type);
};