#include "Builder.h"

void Builder::initialise_new_object(const std::string& label, bool needspositioning, bool isfilled, bool hasdimension)
{
	bool invalid{ true };

	auto component = new Box();

	component->set_is_filled(isfilled);
	component->set_dimension(Dimension{ 0,0 });

	m_houseComponents.insert({ component, 0.0 });
	m_currentPrice = std::accumulate(std::begin(m_houseComponents), std::end(m_houseComponents), 0.,
		[](const double previous, const auto& element) { return previous + (double)element.second; });

	if (hasdimension) {
		while (invalid)
		{
			draw_all();
			std::cout << "\nCurrent " << label << " price: " << std::fixed << std::setprecision(1) << m_materials[component->get_glyph()] * component->get_area();
			std::cout << "\nCurrent total: " << std::fixed << std::setprecision(1) << m_materials[component->get_glyph()] * component->get_area() + m_currentPrice << "\n\n";
			m_inputRenderer.draw_text("Please enter the dimensions you want your " + label +
				" to be in the format WxH.\nTip: make it small enough to fit in your canvas.");

			m_userAnswer = m_inputHandler.get_parsed_input();
			m_inputHandler.clean_string(m_userAnswer);
			m_inputHandler.split_on_identifier(m_userAnswer, component->get_dimension(), "x");

			if (component->get_dimension().w == 0 || component->get_dimension().h == 0) { m_inputRenderer.set_validity(false); }
			else {
				component->get_dimension().h = static_cast<int>(floor((float)component->get_dimension().h * m_canvas.get_console_aspect_ratio()));
				invalid = false;
			}
		}

		m_inputRenderer.set_validity(true);
		invalid = true;
	}

	if (needspositioning) {
		while (invalid)
		{
			draw_all();
			std::cout << "\nCurrent " << label << " price: " << std::fixed << std::setprecision(1) << m_materials[component->get_glyph()] * component->get_area();
			std::cout << "\nCurrent total: " << std::fixed << std::setprecision(1) << m_materials[component->get_glyph()] * component->get_area() + m_currentPrice << "\n\n";
			m_inputRenderer.draw_text("The " + label + " has been placed at arbitrary coordinates.\n"
				"Type [L]eft, [R]ight, [U]p or [D]own to move it in the corresponding direction.\nType [A]ccept to go to the next step.");

			m_userAnswer = m_inputHandler.get_parsed_input();
			m_inputHandler.clean_string(m_userAnswer);

			if (m_userAnswer == "l" || m_userAnswer == "left") { component->set_position(component->get_position() + Point{ -1, 0 }); }
			else if (m_userAnswer == "r" || m_userAnswer == "right") { component->set_position(component->get_position() + Point{ 1, 0 }); }
			else if (m_userAnswer == "u" || m_userAnswer == "up") { component->set_position(component->get_position() + Point{ 0, -1 }); }
			else if (m_userAnswer == "d" || m_userAnswer == "down") { component->set_position(component->get_position() + Point{ 0, 1 }); }
			else if (m_userAnswer == "a" || m_userAnswer == "accept") { invalid = false; }
			else { m_inputRenderer.set_validity(false); }
		}

		m_inputRenderer.set_validity(true);
		invalid = true;
	}

	while (invalid)
	{
		draw_all();
		std::cout << "\nCurrent " << label << " price: " << std::fixed << std::setprecision(1) << m_materials[component->get_glyph()] * component->get_area();
		std::cout << "\nCurrent total: " << std::fixed << std::setprecision(1) << m_materials[component->get_glyph()] * component->get_area() + m_currentPrice << "\n\n";
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
				component->set_glyph(it->first);
				m_currentPrice += (it->second * component->get_area());
				m_houseComponents[component] = it->second * component->get_area();
				invalid = false;
			}
		}
		else { m_inputRenderer.set_validity(false); }
	}
}

void Builder::run()
{
	initialise_new_object("house", false, false);
	initialise_new_object("window");
	initialise_new_object("window");
	initialise_new_object("door");
}

void Builder::initialise_canvas_dimension()
{
	bool invalid{ true };

	while (invalid)
	{
		m_inputRenderer.draw_text("Please enter the dimensions you want your canvas to be in the format WxH (e.g. 150x75).\nBare in mind that your console should always be bigger than the canvas.");
		m_userAnswer = m_inputHandler.get_parsed_input();

		m_inputHandler.split_on_identifier(m_userAnswer, m_canvasDimension, "x");
		if (m_canvasDimension.w == 0 || m_canvasDimension.h == 0) { m_inputRenderer.set_validity(false); }
		else { invalid = false; }
		m_inputRenderer.clear_screen();
	}

	m_inputRenderer.set_validity(true);
	m_canvas.set_console_size(m_canvasDimension);
}

void Builder::make_default_prefab()
{
	m_houseComponents.insert({ &Box({ 0,0 }, { 52, 52 }, false), 1.f });
	m_houseComponents.insert({ &Box({ -10, -10 }, { 5, 5 }, false), 10.f });
	m_houseComponents.insert({ &Box({ 10, -10 }, { 5, 5 }, false), 75.f });
	m_houseComponents.insert({ &Box({ 0, 21 }, { 3, 8 }), 50.f });
	m_houseComponents.insert({ &Circle({ -50, -25 }, 4), 10.f });

	for (auto const& item : m_houseComponents)
	{
		item.first->draw(m_canvas);
	}

	m_canvas.render();

	std::cout << "\n Total price: " << m_currentPrice << std::endl;
}

void Builder::draw_all() {
	m_inputRenderer.clear_screen();
	m_canvas.clear_canvas();

	for (auto const& item : m_houseComponents)
	{
		item.first->draw(m_canvas);
	}

	m_canvas.render();
}

Builder::~Builder()
{
	for (auto item : m_houseComponents)
	{
		delete item.first;
	}
	m_houseComponents.clear();
}