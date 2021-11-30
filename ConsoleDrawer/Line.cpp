#include "Line.h"

Line::Line(Point origin, Point target, bool exact) : m_exact(exact), m_target(target) {
	set_position(origin);
}

void Line::draw(ConsoleCanvas& canvas) {
	// Straight lines
	if (m_target.y == get_position().y) {
		for (int i = get_position().x; i <= m_target.x; i++)
		{
			canvas.set_canvas_tile(Point{ i, get_position().y }, get_glyph());
		}
		return;
	}
	else if (m_target.x == get_position().x)
	{
		for (int i = get_position().y; i <= m_target.y; i++)
		{
			canvas.set_canvas_tile(Point{ get_position().x, i }, get_glyph());
		}
		return;
	}

	// Bresenham’s Line Drawing Algorithm
	int dx = m_target.x - get_position().x;
	int dy = m_target.y - get_position().y;

	int x = get_position().x;
	int y = get_position().y;

	int p = 2 * dy - dx;

	while (x <= m_target.x)
	{
		if (p >= 0)
		{
			canvas.set_canvas_tile(Point{ x, y }, get_glyph());
			y = y + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			canvas.set_canvas_tile(Point{ x, y }, get_glyph());
			p = p + 2 * dy;
		}
		x = x + 1;
	}
}