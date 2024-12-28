#include "Renderer.h"

#include "..\Camera\Camera.h"
#include "..\Mesh\Mesh.h"

void Renderer::update()
{
	for (const auto& pair : queue)
	{
		Mesh* mesh = pair.first;

		mesh->update();
	}
}

void Renderer::draw(Camera* camera)
{
	for (const auto& pair : queue)
	{
		Mesh* mesh = pair.first;
		Shader* shader = pair.second;

		shader->use();
		mesh->draw(*shader, camera->view, camera->projection);
	}
}

void Renderer::addToQueue(Mesh& mesh, Shader& shader)
{
	queue.push_back(std::make_pair(&mesh, &shader));
}
