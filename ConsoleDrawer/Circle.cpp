#include "Circle.h"

Circle::Circle(Point position, int radius) : m_radius(radius) {
	set_position(position);
}

void Circle::draw_circle(ConsoleCanvas& canvas, int xc, int yc, int x, int y) const {
	canvas.set_canvas_tile({ xc + x, yc + y }, get_glyph());
	canvas.set_canvas_tile({ xc - x, yc + y }, get_glyph());
	canvas.set_canvas_tile({ xc + x, yc - y }, get_glyph());
	canvas.set_canvas_tile({ xc - x, yc - y }, get_glyph());
	canvas.set_canvas_tile({ xc + y, yc + x }, get_glyph());
	canvas.set_canvas_tile({ xc - y, yc + x }, get_glyph());
	canvas.set_canvas_tile({ xc + y, yc - x }, get_glyph());
	canvas.set_canvas_tile({ xc - y, yc - x }, get_glyph());
}

void Circle::draw(ConsoleCanvas& canvas) {
	int x = 0;
	int y = m_radius;
	int d = 4 - 2 * m_radius;
	draw_circle(canvas, get_position().x, get_position().y, x, y);

	while (y >= x)
	{
		x++;
		if (d > 0)
		{
			y--;
			d = d + 2*x - 2*y + 1;
		}
		else
		{
			d = d + 2 * x + 1;
		}
		draw_circle(canvas, get_position().x, get_position().y, x, y);
	}
}