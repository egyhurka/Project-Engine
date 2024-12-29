#include "GameObject.h"

#include "..\..\Mesh\Mesh.h"
#include "..\..\Mesh\Geometry.h"

GameObject::GameObject(std::optional<std::string> name, std::optional<vec3> position, std::optional<vec3> color) : mesh(nullptr)
{
	this->name = name.value_or("Default Object");
	this->position = position.value_or(glm::vec3(0.0f));
	this->color = color.value_or(glm::vec3(1.0f));
}

void GameObject::setName(std::string name)
{
	this->name = name;
}

void GameObject::setPosition(vec3 position)
{
	this->position = position;
}

void GameObject::setColor(vec3 color)
{
	this->color = glm::vec3(abs(color.r), abs(color.g), abs(color.b));
}

void GameObject::translate(vec3 value, int index)
{
	if (index == self)
	{
		position += value;
		mesh->translate(position);
		return;
	}
	
	getMesh(index)->translate(position + value);
}

void GameObject::rotate(vec3 axis, float speed = 25.0f, int index = self)
{
	if (index == self)
	{
		mesh->rotate(axis, speed);
		return;
	}
		
	getMesh(index)->rotate(axis, speed);
}

void GameObject::scale(vec3 factor, int index = self)
{
	if (index == self)
	{
		mesh->scale(factor);
		return;
	}

	getMesh(index)->scale(factor);
}

void GameObject::scale(float factor, int index = self)
{
	if (index == self)
	{
		mesh->scale(factor);
		return;
	}

	getMesh(index)->scale(factor);
}

Mesh* GameObject::getMesh(int index)
{
	if (index == self)
		return mesh;

	return children[index]->getMesh(index);
}