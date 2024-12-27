#version 330 core

layout(location = 0) in vec3 position;

uniform vec4 uColor;

out vec4 vertexColor;

void main()
{
    gl_Position = vec4(position, 1.0);
    vertexColor = uColor;
}
