#pragma once
#include <string>
#include <map>
#include <numeric>
#include <vector>

#include "UserInputHandler.h"
#include "UserInterfaceRenderer.h"
#include "Shape.h"
#include "Box.h"
#include "Circle.h"

using ComponentsContainer = std::map<Shape*, std::pair<std::string, double>>;

class House
{
public:
	House() = default;
	virtual ~House() = default;

	virtual bool initialise_position();
	bool initialise_material();
	virtual bool initialise_size();

	static ComponentsContainer m_houseComponents;

protected:
	bool init_squared_component_dimension(Box& box);

#pragma region Getters and Setters
	inline UserInterfaceRenderer get_input_renderer() const { return m_inputRenderer; };
	inline UserInputHandler get_input_handler() const { return m_inputHandler; };

	inline std::string& get_answer_object() { return m_userAnswer; };
	inline std::string& get_current_component_label() { return m_currentLabel; };

	inline double get_current_component_price() const { return m_currentComponentPrice; };
	inline void set_current_component_price(double p) { m_currentComponentPrice = p; };

	inline double get_aspect_ratio() const { return m_aspectRatio; };
	inline void set_aspect_ratio(double ar) { m_aspectRatio = ar; };

	inline Shape* get_current_component_primitive() const { return m_currentComponentPrimitive; }
	inline void set_current_component_primitive(Shape* curr) { m_currentComponentPrimitive = curr; }

	std::map<char, double> get_materials_map() const { return m_materials; }

	std::vector<Shape*> get_components_by_label(const std::string& key) const;

public:
	static double get_total_price();
#pragma endregion Getters and setters for private member variables

private:

	Shape* m_currentComponentPrimitive = nullptr;

	UserInterfaceRenderer m_inputRenderer;
	UserInputHandler m_inputHandler;

	std::string m_userAnswer = "";
	std::string m_currentLabel = "house";

	Box m_house;

	double m_currentComponentPrice = 0.0;
	double m_aspectRatio = 0.5;

	std::map<char, double> m_materials{ { '#', 0.50},
										{ 'O', 0.75},
										{ '*', 1.00} };
};
