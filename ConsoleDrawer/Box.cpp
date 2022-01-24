#include "Box.h"

Box::Box(Point position, Dimension dimension, bool isfilled) : m_dimension(dimension), m_isFilled(isfilled) {
	m_position = position;
}

void Box::draw(ConsoleCanvas& canvas) {
	std::vector<Line> m_sides;

	// Center coordinates
	const Point centred_origin{ get_position().x - m_dimension.w / 2 , get_position().y - m_dimension.h / 2 };

	if (m_dimension == Dimension{ 0,0 }) { return; }

	if (m_isFilled) {
		for (int i = 0; i < m_dimension.w; i++)
		{
			m_sides.emplace_back(Line({ centred_origin.x + i, centred_origin.y }, { centred_origin.x + i, centred_origin.y + m_dimension.h }));
		}
	}
	else {
		m_sides.emplace_back(Line({ centred_origin.x , centred_origin.y }, { centred_origin.x + m_dimension.w, centred_origin.y }));
		m_sides.emplace_back(Line({ centred_origin.x , centred_origin.y }, { centred_origin.x , centred_origin.y + m_dimension.h }));
		m_sides.emplace_back(Line({ centred_origin.x , centred_origin.y + m_dimension.h }, { centred_origin.x + m_dimension.w, centred_origin.y + m_dimension.h }));
		m_sides.emplace_back(Line({ centred_origin.x + m_dimension.w , centred_origin.y }, { centred_origin.x + m_dimension.w, centred_origin.y + m_dimension.h }));
	}

	for (auto side : m_sides)
	{
		side.set_glyph(get_glyph());
		side.draw(canvas);
	}
}