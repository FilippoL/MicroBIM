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
#include "Door.h"
#include "Window.h"

class HouseEntity : public Entity {
public:
	virtual bool initialise_position() = 0;
	virtual bool initialise_size() = 0;
	virtual double get_price() { return m_currentComponentPrice; };

protected:
	double m_currentComponentPrice = 0.0;
	std::string m_currentLabel = "";

	std::map<char, double> m_materials{ { '#', 0.50},
										{ 'O', 0.75},
										{ '*', 1.00} };

	FreePositionInitialiser m_freePositionInitialiser;
	FreePositionInitialiser m_fixedPositionInitialiser;

	SquaredComponentSizeInitialiser m_squaredSizeInitialiser;
	RoundComponentSizeInitialiser m_roundSizeInitialiser;
};

class IInitialiser {
protected:
	UserInterfaceRenderer m_inputRenderer;
	UserInputHandler m_inputHandler;
	std::string m_userAnswer = "";
};

class FreePositionInitialiser : public IInitialiser {
public:
	virtual bool initialise_position(const std::string& label, Entity& primitive);

	virtual ~FreePositionInitialiser() = default;
};

class ConstrainedPositionInitialiser : public IInitialiser {
public:
	virtual bool initialise_position(const std::string& label, Entity& primitive);

	virtual ~ConstrainedPositionInitialiser() = default;
};

class RoundComponentSizeInitialiser : public IInitialiser {
public:
	virtual bool initialise_size(const std::string& label, Circle& primitive);

	virtual ~RoundComponentSizeInitialiser() = default;
};

class SquaredComponentSizeInitialiser : public IInitialiser {
public:
	virtual bool initialise_size(const std::string& label, Box& primitive);

	virtual ~SquaredComponentSizeInitialiser() = default;
};

class House : public HouseEntity, public IInitialiser
{
public:
	House() = default;
	~House() override = default;

	bool initialise_position() override { m_freePositionInitialiser.initialise_position(m_currentLabel, m_house); };
	bool initialise_material(Shape* shape);
	bool initialise_size() override { m_squaredSizeInitialiser.initialise_size(m_currentLabel, m_house); };

	double get_total_price() {
		double totalPrice = 0.0;

		for (auto& window : m_windows)
		{
			totalPrice += window.get_price();
		}
		for (auto& door : m_doors)
		{
			totalPrice += door.get_price();
		}

		return totalPrice;
	}

	void draw(ConsoleCanvas& canvas) override {
		m_house.draw(canvas);

		for (auto& window : m_windows)
		{
			window.draw(canvas);
		}
		for (auto& door : m_doors)
		{
			door.draw(canvas);
		}
	};

private:
	std::vector<Window> m_windows;
	std::vector<Door> m_doors;
	Box m_house;
};
