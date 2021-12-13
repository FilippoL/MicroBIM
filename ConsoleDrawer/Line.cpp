#include "Line.h"

Line::Line(Point origin, Point target, bool exact) : m_exact(exact), m_target(target) {
	set_position(origin);
}

void Line::draw(ConsoleCanvas& canvas) {
	// Bresenham’s Line Drawing Algorithm
	int x = get_position().x;
	int y = get_position().y;

	int w = m_target.x - get_position().x;
	int h = m_target.y - get_position().y;
	int dx1 = 0, dy1 = 0, dx2 = 0, dy2 = 0;

	if (w < 0) dx1 = -1; else if (w > 0) dx1 = 1;
	if (h < 0) dy1 = -1; else if (h > 0) dy1 = 1;
	if (w < 0) dx2 = -1; else if (w > 0) dx2 = 1;

	int longest = abs(w);
	int shortest = abs(h);

	if (!(longest > shortest)) {
		std::swap(longest, shortest);
		if (h < 0) dy2 = -1; else if (h > 0) dy2 = 1;
		dx2 = 0;
	}

	int numerator = longest >> 1;

	for (int i = 0; i <= longest; i++) {
		canvas.set_canvas_tile(Point{ x, y }, get_glyph());
		numerator += shortest;
		if (!(numerator < longest)) {
			numerator -= longest;
			x += dx1;
			y += dy1;
		}
		else {
			x += dx2;
			y += dy2;
		}
	}
}