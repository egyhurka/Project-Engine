#pragma once

#include "Vertex.h"

#include <vector>

struct geometryData
{
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
};

namespace geometry
{
	extern geometryData Cube;
}