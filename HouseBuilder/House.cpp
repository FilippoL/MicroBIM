#include "House.h"

ComponentsContainer House::m_houseComponents = {};

bool House::initialise_size()
{
	auto curr = new Box;
	m_currentComponentPrimitive = curr;

	return init_squared_component_dimension(*curr);
}

bool House::init_squared_component_dimension(Box& box)
{
	if (m_currentLabel == "house") { box.set_is_filled(false); }

	get_input_renderer().draw_text("Please enter the dimensions you want your " + get_current_component_label() +
		" to be in the format WxH.\nTip: make it small enough to fit in your canvas.");

	get_answer_object() = get_input_handler().get_parsed_input();
	get_input_handler().clean_string(get_answer_object());
	get_input_handler().split_on_identifier(get_answer_object(), box.get_dimension(), "x");

	if (box.get_dimension().w == 0 || box.get_dimension().h == 0) { get_input_renderer().set_validity(false); return false; }
	else {
		box.get_dimension().h = static_cast<int>(floor((float)box.get_dimension().h * get_aspect_ratio()));
		set_current_component_price(m_materials[get_current_component_primitive()->get_glyph()] * get_current_component_primitive()->get_area());
		m_houseComponents.insert({ get_current_component_primitive(), {get_current_component_label(), get_current_component_price()} });
		return true;
	}
}

bool House::initialise_position()
{
	std::cout << "\nCurrent " << get_current_component_label() << " price: " << std::fixed << std::setprecision(1) << get_current_component_price() << "$\n";
	m_inputRenderer.draw_text("The " + get_current_component_label() + " has been placed at arbitrary coordinates.\n"
		"Type [L]eft, [R]ight, [U]p or [D]own to move it in the corresponding direction.\nType [A]ccept to go to the next step.");

	m_userAnswer = m_inputHandler.get_parsed_input();
	m_inputHandler.clean_string(m_userAnswer);

	if (m_userAnswer == "l" || m_userAnswer == "left") { get_current_component_primitive()->move_by(Point{ -1, 0 }); }
	else if (m_userAnswer == "r" || m_userAnswer == "right") { get_current_component_primitive()->move_by(Point{ 1, 0 }); }
	else if (m_userAnswer == "u" || m_userAnswer == "up") { get_current_component_primitive()->move_by(Point{ 0, -1 }); }
	else if (m_userAnswer == "d" || m_userAnswer == "down") { get_current_component_primitive()->move_by(Point{ 0, 1 }); }
	else if (m_userAnswer == "a" || m_userAnswer == "accept") { return true; }
	else { m_inputRenderer.set_validity(false); }

	return false;
}

std::vector<Shape*> House::get_components_by_label(const std::string& key) const {
	std::vector<Shape*> components;
	for (const auto& component : m_houseComponents) {
		if (component.second.first == key) {
			components.push_back(component.first);
		}
	}
	return components;
}

double House::get_total_price() {
	return std::accumulate(std::begin(m_houseComponents), std::end(m_houseComponents), 0.,
		[](const auto& previous, const auto& element) { return previous + element.second.second; });
}

bool House::initialise_material()
{
	std::cout << "\nCurrent " << get_current_component_label() << " price: " << std::fixed << std::setprecision(1) << get_current_component_price() << "$\n";
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
			get_current_component_primitive()->set_glyph(it->first);
			set_current_component_price(m_materials[get_current_component_primitive()->get_glyph()] * get_current_component_primitive()->get_area());
			m_houseComponents[m_currentComponentPrimitive] = { get_current_component_label(), get_current_component_price() };
			return true;
		}
	}
	else { m_inputRenderer.set_validity(false); }

	return false;
}