#pragma once

#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>
#include <iomanip>

#include "Shape.h"

class Circle : public Shape
{
public:
	Circle() = default;
	Circle(Point position, int radius);
	~Circle() override = default;

	void draw(ConsoleCanvas& canvas) override;
	double get_area()override { return m_radius * 3.14159265358979323846; }

private:
	void draw_circle(ConsoleCanvas& canvas, int xc, int yc, int x, int y) const;
	double m_radius{ 10 };
};
