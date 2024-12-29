#pragma once

#include <string>
#include <optional>
typedef std::nullopt_t nullopt;

#include "..\..\Core\TypedefGLM.h"

#define self -1

class Mesh;

class GameObject {
public:
	GameObject(std::optional<std::string> name, std::optional<vec3> position, std::optional<vec3> color);

	void setName(std::string name);
	void setPosition(vec3 position);
	void setColor(vec3 color);

	void translate(vec3 value, int index = self);
	void rotate(vec3 axis, float speed = 25.0f, int index = self);
	void scale(vec3 factor, int index = self);
	void scale(float factor, int index = self);

	Mesh* getMesh(int index = self);

private:
	std::vector<GameObject*> children;
	Mesh* mesh;

	std::string name;
	glm::vec3 position;
	glm::vec3 color;
};