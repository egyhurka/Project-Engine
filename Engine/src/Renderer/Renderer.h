#pragma once

#include <vector>
#include <utility>

class Camera;
class Mesh;
class Shader;

class Renderer
{
public:
	void update();
	void draw(Camera* camera);

	void addToQueue(Mesh& mesh, Shader& shader);

private:
	std::vector<std::pair<Mesh*, Shader*>> queue = {};
};