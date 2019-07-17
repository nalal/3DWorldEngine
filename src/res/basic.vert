//#shader vertex
#version 130 core

in vec2 vertexPosition;

void main()
{
	gl_position.xy = vertexPosition;
	gl_position.z = 0.0;
	gl_position.w = 1.0;
};
