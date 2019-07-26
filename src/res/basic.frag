#version 130

in vec2 fragPosition;
in vec4 fragColor;

out vec4 color;

uniform float time;

void main()
{
	color = vec4(
		fragColor.x * (cos(fragPosition.x + time) + 1) * 0.5,
		fragColor.y * (cos(fragPosition.x + time) + 1) * 0.5,
		fragColor.z * (cos(fragPosition.x + time) + 1) * 0.5,
		0.0
	);
};
