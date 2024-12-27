#include "geometry.h"

namespace geometry
{
    geometryData Cube =
    {
        // vertices
        {
            // front
            {{0.5f,  0.5f,  0.5f}}, // 0
            {{0.5f, -0.5f,  0.5f}}, // 1
            {{-0.5f, -0.5f,  0.5f}}, // 2
            {{-0.5f,  0.5f,  0.5f}}, // 3

            // back
            {{0.5f,  0.5f, -0.5f}}, // 4
            {{0.5f, -0.5f, -0.5f}}, // 5
            {{-0.5f, -0.5f, -0.5f}}, // 6
            {{-0.5f,  0.5f, -0.5f}}  // 7
        },

        // indices
        {
            // front
            0, 1, 3,
            1, 2, 3,

            // back
            4, 5, 7,
            5, 6, 7,

            // left
            3, 2, 7,
            2, 6, 7,

            // right
            0, 1, 4,
            1, 5, 4,

            // top
            3, 0, 4,
            3, 4, 7,

            // bottom
            1, 2, 5,
            2, 6, 5
        }
    };
}
