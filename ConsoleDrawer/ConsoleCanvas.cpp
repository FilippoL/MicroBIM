#include "ConsoleCanvas.h"

ConsoleCanvas::ConsoleCanvas(Dimension canvas_size, Dimension char_dimension) : m_charDimension(char_dimension)
{
	set_console_size(canvas_size);
	set_char_aspect_ratio({ (float)m_charDimension.w / (float)m_charDimension.h });
};

void ConsoleCanvas::render_border(char& character, size_t iteration_counter) const
{
	if (iteration_counter <= (m_canvasDimension.w) ||
		iteration_counter > ((static_cast<size_t>(m_canvasDimension.w) * static_cast<size_t>(m_canvasDimension.h)) - m_canvasDimension.w))
	{
		character = '-';
	}
	else if (iteration_counter % m_canvasDimension.w == 0 ||
		(iteration_counter - 1) % m_canvasDimension.w == 0)
	{
		character = '|';
	}
	else {
		character = character != '\0' ? character : ' ';
	}
}

bool ConsoleCanvas::set_canvas_tile(Point position, char what_char)
{
	int new_index = (position.x + m_canvasDimension.w / 2) + m_canvasDimension.w * (position.y + m_canvasDimension.h / 2);

	if (new_index >= m_canvas.size()) { return false; }

	m_canvas[new_index] = what_char;

	return true;
}

void ConsoleCanvas::set_console_size(Dimension dimension)
{
	set_char_aspect_ratio({ static_cast<float>(m_charDimension.w) / m_charDimension.h });
	m_canvasDimension = Dimension{ dimension.w, static_cast<int>(dimension.h * m_charApectRatio) };
	m_canvas.resize(static_cast<size_t>(m_canvasDimension.w) * static_cast<size_t>(m_canvasDimension.h));
}

void ConsoleCanvas::render()
{
	size_t counter{ 0 };
	for (auto& character : m_canvas) {
		counter++;
		if (m_visibleBorders) { render_border(character, counter); }
		std::cout << character;
		if (counter % m_canvasDimension.w == 0) { std::cout << std::endl; }
	}
}

void ConsoleCanvas::clear_canvas() {
	for (auto& character : m_canvas) {
		character = '\0';
	}
}