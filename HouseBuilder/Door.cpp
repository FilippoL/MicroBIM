#include "Door.h"

Door::Door() {
	get_current_component_label() = "door";
}

bool Door::initialise_position()
{
	if (!m_retrievedPositions) {
		std::vector<Shape*> comps = get_components_by_label("house");
		if (!comps.empty()) {
			auto door = (Box*)get_current_component_primitive();
			auto house = (Box*)comps[0];
			get_current_component_primitive()->set_position(Point{ house->get_position().x, house->get_dimension().h / 2 - door->get_dimension().h / 2 });
			m_retrievedPositions = true;
			return false;
		}
	}

	std::cout << "\nCurrent " << get_current_component_label() << " price: " << std::fixed << std::setprecision(1) << get_current_component_price() << "$\n";
	get_input_renderer().draw_text("The " + get_current_component_label() + " has been placed at arbitrary coordinates on the ground floor.\n"
		"Type [L]eft or [R]ight to move it in the corresponding direction.\nType [A]ccept to go to the next step.");

	get_answer_object() = get_input_handler().get_parsed_input();
	get_input_handler().clean_string(get_answer_object());

	if (get_answer_object() == "l" || get_answer_object() == "left") { get_current_component_primitive()->move_by(Point{ -1, 0 }); }
	else if (get_answer_object() == "r" || get_answer_object() == "right") { get_current_component_primitive()->move_by(Point{ 1, 0 }); }
	else if (get_answer_object() == "a" || get_answer_object() == "accept") { return true; }
	else { get_input_renderer().set_validity(false); }

	return false;
}