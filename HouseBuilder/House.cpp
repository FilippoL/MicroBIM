#include "House.h"

House::House() {
	m_currentLabel = "house";
}

bool SquaredComponentSizeInitialiser::initialise_size(const std::string& label, Box& primitive)
{
	m_inputRenderer.draw_text("Please enter the dimensions you want your " + label +
		" to be in the format WxH.\nTip: make it small enough to fit in your canvas.");

	m_userAnswer = m_inputHandler.get_parsed_input();
	m_inputHandler.clean_string(m_userAnswer);
	m_inputHandler.split_on_identifier(m_userAnswer, primitive.get_dimension(), "x");

	if (primitive.get_dimension().w == 0 || primitive.get_dimension().h == 0) { m_inputRenderer.set_validity(false); return false; }
	else { return true; }
}

bool RoundComponentSizeInitialiser::initialise_size(const std::string& label, Circle& primitive)
{
	m_inputRenderer.draw_text("Please enter the radius you want your " + label +
		" to be.\nTip: make it small enough to fit in your canvas.");

	m_userAnswer = m_inputHandler.get_parsed_input();
	m_inputHandler.clean_string(m_userAnswer);

	if (!m_inputHandler.is_number(m_userAnswer)) { m_inputRenderer.set_validity(false); return false; }
	else {
		primitive.set_radius(stoi(m_userAnswer));

		return true;
	}
}

bool FreePositionInitialiser::initialise_position(const std::string& label, Entity& entity)
{
	m_inputRenderer.draw_text("The " + label + " has been placed at arbitrary coordinates.\n"
		"Type [L]eft, [R]ight, [U]p or [D]own to move it in the corresponding direction.\nType [A]ccept to go to the next step.");

	m_userAnswer = m_inputHandler.get_parsed_input();
	m_inputHandler.clean_string(m_userAnswer);

	if (m_userAnswer == "l" || m_userAnswer == "left") { entity.move_by(Point{ -1, 0 }); }
	else if (m_userAnswer == "r" || m_userAnswer == "right") { entity.move_by(Point{ 1, 0 }); }
	else if (m_userAnswer == "u" || m_userAnswer == "up") { entity.move_by(Point{ 0, -1 }); }
	else if (m_userAnswer == "d" || m_userAnswer == "down") { entity.move_by(Point{ 0, 1 }); }
	else if (m_userAnswer == "a" || m_userAnswer == "accept") { return true; }
	else { m_inputRenderer.set_validity(false); }

	return false;
}

bool ConstrainedPositionInitialiser::initialise_position(const std::string& label, Entity& entity)
{
	m_inputRenderer.draw_text("The " + label + " has been placed at arbitrary coordinates on the ground floor.\n"
		"Type [L]eft or [R]ight to move it in the corresponding direction.\nType [A]ccept to go to the next step.");

	m_userAnswer = m_inputHandler.get_parsed_input();
	m_inputHandler.clean_string(m_userAnswer);

	if (m_userAnswer == "l" || m_userAnswer == "left") { entity.move_by(Point{ -1, 0 }); }
	else if (m_userAnswer == "r" || m_userAnswer == "right") { entity.move_by(Point{ 1, 0 }); }
	else if (m_userAnswer == "a" || m_userAnswer == "accept") { return true; }
	else { m_inputRenderer.set_validity(false); }

	return false;
}

bool House::initialise_material(Shape* shape)
{
	std::cout << "Choose among the following materials : ";
	m_inputRenderer.draw_map(m_materials);
	m_inputRenderer.draw_text("\nType a number between 1 and " + std::to_string(m_materials.size()));
	m_userAnswer = m_inputHandler.get_parsed_input();

	if (m_inputHandler.is_number(m_userAnswer))
	{
		if (stoi(m_userAnswer) > m_materials.size() || stoi(m_userAnswer) < 1) { m_inputRenderer.set_validity(false); }
		else {
			auto it = m_materials.begin();
			std::advance(it, stoi(m_userAnswer) - 1);
			shape->set_glyph(it->first);
			m_currentComponentPrice = (m_materials[shape->get_glyph()] * shape->get_area());
			return true;
		}
	}
	else { m_inputRenderer.set_validity(false); }

	return false;
}