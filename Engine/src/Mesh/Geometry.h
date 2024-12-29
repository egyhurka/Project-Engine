#pragma once

#include <vector>

#include "Vertex.h"

struct geometryData
{
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
};

namespace geometry
{
	extern geometryData Cube;
}