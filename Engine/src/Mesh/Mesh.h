#pragma once

#include <vector>

#include "Vertex.h"
#include "..\Shader\Shader.h"

class Mesh
{
public:
	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, glm::vec4 color);
	void update();
	void draw(Shader& shader, glm::mat4& view, glm::mat4& projection);

	void translate(glm::vec3 position);
	void rotate(glm::vec3 axis = glm::vec3(0.0f, 1.0f, 0.0f), float speed = 25.0f);
	void scale(glm::vec3 factor);
	void scale(float factor);

	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	glm::vec4 color;
	glm::mat4 model;

private:
	unsigned int VAO, VBO, EBO;
	void setupMesh();
};