#include "Window.h"

Window::Window() {
	get_current_component_label() = "window";
}

bool Window::initialise_size()
{
	if (m_answered && m_isRound) {
		auto curr = new Circle;
		set_current_component_primitive(curr);
		return init_round_component_dimension(*curr);
	}
	else if (m_answered && !m_isRound) {
		auto curr = new Box;
		set_current_component_primitive(curr);
		return init_squared_component_dimension(*curr);
	}

	get_input_renderer().draw_text("Do you want a (R)ound or (S)quare shaped " + get_current_component_label() + "? ");
	get_answer_object() = get_input_handler().get_parsed_input();

	if (get_answer_object() == "r" || get_answer_object() == "round") {
		m_isRound = true;
		m_answered = true;
	}
	else if (get_answer_object() == "s" || get_answer_object() == "square") {
		m_isRound = false;
		m_answered = true;
	}
	else {
		get_input_renderer().set_validity(false);
	}

	return false;
}

bool Window::init_round_component_dimension(Circle& circle)
{
	std::cout << "\nCurrent " << get_current_component_label() << " price: " << std::fixed << std::setprecision(1) << get_current_component_price() << "$\n";
	get_input_renderer().draw_text("Please enter the radius you want your " + get_current_component_label() +
		" to be.\nTip: make it small enough to fit in your canvas.");

	get_answer_object() = get_input_handler().get_parsed_input();
	get_input_handler().clean_string(get_answer_object());

	if (get_input_handler().is_number(get_answer_object()))
	{
		circle.set_radius(stoi(get_answer_object()));
		set_current_component_price(get_materials_map()[get_current_component_primitive()->get_glyph()] * get_current_component_primitive()->get_area());
		House::m_houseComponents.insert({ get_current_component_primitive(), {get_current_component_label(), get_current_component_price()} });
		return true;
	}
	else {
		get_input_renderer().set_validity(false);
		return false;
	}
}