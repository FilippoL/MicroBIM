#include "Builder.h"

void Builder::initialise_new_object(const ComponentType& type)
{
	switch (type)
	{
	case Builder::ComponentType::HOUSE:
		build_component(new House);
		break;
	case Builder::ComponentType::WINDOW:
		build_component(new Window);
		break;
	case Builder::ComponentType::DOOR:
		build_component(new Door);
		break;
	default:
		break;
	}
}

//void Builder::build_component(House* component) {
//	bool valid = false;
//
//	while (!valid) { draw_all(); valid = component->initialise_size(); } valid = false;
//	while (!valid) { draw_all(); valid = component->initialise_position(); } valid = false;
//	while (!valid) { draw_all(); valid = component->initialise_material(); }
//
//	delete component;
//}

Builder::ComponentType Builder::map_num_to_enum(int i) const {
	if (i == 1) { return Builder::ComponentType::HOUSE; }
	else if (i == 2) { return Builder::ComponentType::WINDOW; }
	else if (i == 3) { return Builder::ComponentType::DOOR; }
}

void Builder::run()
{
	std::string m_userAnswer{ "" };

	while (true)
	{
		draw_all();
		std::cout << "Current total: " << std::fixed << std::setprecision(1) << m_house.get_total_price() << "$\n\n";
		std::vector<std::string>options{ "House", "Window", "Door" };
		m_inputRenderer.draw_vector(options);
		m_inputRenderer.draw_text("Add a new object to your canvas by typing any index of the above listed components.\nType 0 to exit.");
		m_userAnswer = m_inputHandler.get_parsed_input();
		if (!m_inputHandler.is_number(m_userAnswer)) { m_inputRenderer.set_validity(false); continue; }
		int numeric_answer = stoi(m_userAnswer);
		if (numeric_answer < 0 || numeric_answer > options.size()) { m_inputRenderer.set_validity(false); continue; }
		if (numeric_answer == 0) { break; }
		initialise_new_object(map_num_to_enum(numeric_answer));
	}
}

void Builder::initialise_canvas_dimension()
{
	bool invalid{ true };
	std::string m_userAnswer{ "" };

	while (invalid)
	{
		m_inputRenderer.draw_text("Please enter the dimensions you want your canvas to be in the format WxH (e.g. 150x75).\nBare in mind that your console should always be bigger than the canvas.");
		m_userAnswer = m_inputHandler.get_parsed_input();

		m_inputHandler.split_on_identifier(m_userAnswer, m_canvasDimension, "x");
		if (m_canvasDimension.w == 0 || m_canvasDimension.h == 0) { m_inputRenderer.set_validity(false); }
		else { invalid = false; }
		m_inputRenderer.clear_screen();
	}

	m_canvas.set_console_size(m_canvasDimension);
}

void Builder::draw_all() {
	m_inputRenderer.clear_screen();
	m_canvas.clear_canvas();

	m_house.draw(m_canvas);

	m_canvas.render();
}