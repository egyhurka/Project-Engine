#pragma once

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
	Shader(const char* vertexPath, const char* fragmentPath);

	void use();

	unsigned int ID;

private:
	const char* readShader(const char* path);
	void checkCompileErrors(unsigned int shader, std::string type);
};