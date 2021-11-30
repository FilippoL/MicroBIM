#pragma once

#include <iostream>
#include <math.h>
#include "DataStructures.h"

class ConsoleCanvas
{
private:
	Dimension m_charDimension{ 5,10 };

	float m_charApectRatio{ 0.5 };

	Dimension m_canvasDimension{ 50,50 };

	std::vector<char> m_canvas;

	bool m_visibleBorders = true;

	void render_border(char& character, size_t iteration_counter) const;

public:

	ConsoleCanvas(Dimension canvas_size, Dimension char_dimension);

	ConsoleCanvas() = default;

	~ConsoleCanvas() = default;

	void set_char_aspect_ratio(float aspect_ratio) { m_charApectRatio = aspect_ratio; }

	void set_borders_visible(bool visible) { m_visibleBorders = visible; }

	bool set_canvas_tile(Point position, char what_char);

	void set_console_size(Dimension dimension);

	float get_console_aspect_ratio() const { return m_charApectRatio; }

	void render();

	void clear_canvas();
};
