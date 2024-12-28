#include "Mesh.h"

#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, glm::vec4 color) : model(glm::mat4(1.0f))
{
	this->vertices = vertices;
	this->indices = indices;
    this->color = color;

	setupMesh();
}

void Mesh::update()
{
    model = glm::mat4(1.0f);
}

void Mesh::draw(Shader& shader, glm::mat4& view, glm::mat4& projection)
{
    shader.use();
    shader.setColor(color);

    shader.setUniformMat4("model", model);
    shader.setView(view);
    shader.setUniformMat4("projection", projection);

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void Mesh::translate(glm::vec3 position)
{
    model = glm::translate(model, position);
}

void Mesh::rotate(glm::vec3 axis, float speed)
{    
    model = glm::rotate(model, (float)glfwGetTime() * glm::radians(speed), axis);
}

void Mesh::scale(glm::vec3 factor)
{
    model = glm::scale(model, factor);
}

void Mesh::scale(float factor)
{
    model = glm::scale(model, glm::vec3(factor));
}

void Mesh::setupMesh()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

    glBindVertexArray(0);
}