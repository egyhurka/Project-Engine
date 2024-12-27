#include "Shader.h"

#include "..\Core\Log.h"

#include <string>

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	std::string vCode = readShader(vertexPath);
	std::string fCode = readShader(fragmentPath);

	const char* vertexCode = vCode.c_str();
	const char* fragmentCode = fCode.c_str();

	unsigned int vertex, fragment;

	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vertexCode, NULL);
	glCompileShader(vertex);
	checkCompileErrors(vertex, "VERTEX");

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fragmentCode, NULL);
	glCompileShader(fragment);
	checkCompileErrors(fragment, "FRAGMENT");

	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);
	checkCompileErrors(ID, "PROGRAM");

	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

void Shader::use()
{
	glUseProgram(ID);
}

UniformLocationResult Shader::getUniformLocation(const char* name)
{
	int location = glGetUniformLocation(ID, name);

	if (location == -1)
	{
		Log::error("[SHADER] Uniform location not found: " + (std::string)(name));
		return { location, false };
	}
	
	return { location, true };
}

void Shader::setColor(const glm::vec4& color)
{
	auto result = getUniformLocation("uColor");
	if (result.success)
		glUniform4f(result.location, color.r, color.g, color.b, color.a);
}

std::string Shader::readShader(const char* path)
{
	std::string code;
	std::ifstream file;

	file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		file.open(path);
		std::stringstream stream;
		stream << file.rdbuf();
		file.close();
		code = stream.str();
	}
	catch (const std::exception& e)
	{
		Log::error("[SHADER] File not successfully read: ");
		Log::error(e.what());
	}

	return code;
}

void Shader::checkCompileErrors(unsigned int shader, std::string type)
{
	int success;
	char infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			Log::error("[SHADER] Compilation error (" + type + "): " + infoLog);
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			Log::error("[SHADER] Program linking error (" + type + "): " + infoLog);
		}
	}
}
