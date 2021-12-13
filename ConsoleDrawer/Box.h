#pragma once

#include <iostream>
#include <vector>
#include <math.h>
#include "Line.h"

class Box : public Line
{
public:
	Box() = default;
	Box(Point position, Dimension dimension, bool is_filled = true);

	~Box() override = default;

	inline bool get_is_filled() const { return m_isFilled; }
	inline void set_is_filled(const bool& isfilled) { m_isFilled = isfilled; }
	inline Dimension& get_dimension() { return m_dimension; }
	inline void set_dimension(const Dimension& dims) { m_dimension = dims; }

	void draw(ConsoleCanvas& canvas) override;
	double get_area()override { return static_cast<double>(m_dimension.w) * static_cast<double>(m_dimension.h); }

private:
	Dimension m_dimension{ 0,0 };
	bool m_isFilled = true;
};
