#pragma once

#include "Vertex.h"
#include "..\Shader\Shader.h"

#include <vector>

class Mesh
{
public:
	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, glm::vec4 color);
	void draw(Shader& shader, glm::mat4& model, glm::mat4& view, glm::mat4& projection);

	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	glm::vec4 color;

private:
	unsigned int VAO, VBO, EBO;
	void setupMesh();
};