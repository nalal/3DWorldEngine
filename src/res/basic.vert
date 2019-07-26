#version 130 



in vec2 vertexPosition;
in vec4 vertexColor;

out vec2 fragPosition;
out vec4 fragColor;

void main()
{
	gl_Position.xy = vertexPosition;
	gl_Position.z = 0.0;
	gl_Position.w = 1.0;
	fragPosition = vertexPosition;
	fragColor = vertexColor;
};
