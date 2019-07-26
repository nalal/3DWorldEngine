#pragma once

struct Color
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
};

struct Position
{
	float x;
	float y;
};

struct vertex
{
	Position position;
	Color color;
};
