#pragma once

#include <glm/glm.hpp>

#include "..\Shader\Shader.h"

#include <vector>

struct Vertex
{
	glm::vec3 Position;
};

class Mesh
{
public:
	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, glm::vec4 color);
	void draw(Shader& shader);

	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	glm::vec4 color;

private:
	unsigned int VAO, VBO, EBO;
	void setupMesh();
};