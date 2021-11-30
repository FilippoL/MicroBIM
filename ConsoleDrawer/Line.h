#pragma once

#include <math.h>
#include <algorithm>
#include <iostream>

#include "Shape.h"

class Line : public Shape
{
public:
	Line() = default;
	Line(Point origin, Point target, bool exact = true);
	~Line() override = default;

	void draw(ConsoleCanvas& canvas) override;
	void set_target(Point target) { m_target = target; }
	double get_area() override { return Point{ m_target - get_position() }.get_magnitude(); }

private:
	bool m_exact = true;
	Point m_target{ 0,0 };
};
