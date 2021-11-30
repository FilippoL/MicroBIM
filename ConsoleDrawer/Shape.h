#pragma once
#include "ConsoleCanvas.h"

class Shape
{
public:
	Shape() = default;
	virtual ~Shape() = default;

	void set_position(Point position) { m_position = position; }
	inline void set_glyph(const char& glyph) { m_glyph = glyph; }

	inline Point get_position() const { return m_position; }
	inline char get_glyph() const { return m_glyph; }

	virtual double get_area() = 0;

	virtual void draw(ConsoleCanvas& canvas) = 0;

private:
	Point m_position{ 0,0 };
	char m_glyph{ '#' };
};
