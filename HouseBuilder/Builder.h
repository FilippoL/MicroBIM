#include <vector>
#include <map>
#include <numeric>

#include "Shape.h"

#include "Box.h"
#include "Line.h"
#include "Circle.h"

#include "DataStructures.h"

#include "ConsoleCanvas.h"
#include "UserInputHandler.h"
#include "UserInterfaceRenderer.h"

class Builder
{
public:
	Builder() = default;
	~Builder();

	void run();

	void initialise_canvas_dimension();

	void make_default_prefab();

private:

	void initialise_new_object(const std::string& label, bool needspositioning = true, bool isfilled = true, bool hasdimension = true);

	Dimension m_houseDimension{ 0,0 };
	Dimension m_canvasDimension{ 50,50 };

	Point m_housePosition{ 0,0 };

	std::map<Shape*, double> m_houseComponents;

	ConsoleCanvas m_canvas;

	UserInterfaceRenderer m_inputRenderer;
	UserInputHandler m_inputHandler;
	std::string m_userAnswer;

	std::map<char, double> m_materials{ { '#', 0.5}, { 'O', 0.75}, {'*', 1.0} };
	double m_currentPrice = 0.0;

	void draw_all();
};
