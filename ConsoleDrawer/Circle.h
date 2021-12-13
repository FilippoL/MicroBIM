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
	double get_radius()const { return m_radius; }

	void set_radius(double r) { m_radius = r; }

private:
	void draw_circle(ConsoleCanvas& canvas, int xc, int yc, int x, int y) const;
	double m_radius{ 0 };
};
