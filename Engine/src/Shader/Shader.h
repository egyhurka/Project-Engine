#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "../Core/Log.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

struct UniformLocationResult {
	int location;
	bool success;
};

class Shader
{
public:
	Shader(const char* vertexPath, const char* fragmentPath);

	void use();

	unsigned int ID;

	UniformLocationResult getUniformLocation(const char* name);
	void setColor(const glm::vec4& color);

private:
	std::string readShader(const char* path);
	void checkCompileErrors(unsigned int shader, std::string type);
};