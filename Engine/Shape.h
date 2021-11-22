#pragma once

struct Point
{
	int x;
	int y;
};

struct Dimension
{
	unsigned int w;
	unsigned int h;
};

class Shape
{
public:
	Shape();
	~Shape();

protected:
	Point m_position{ 0,0 };
};
