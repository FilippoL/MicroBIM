#pragma once

#include <vector>
#include <map>
#include <numeric>
#include "ConsoleCanvas.h"

#include "House.h"
#include "Door.h"
#include "Window.h"

#include "UserInputHandler.h"
#include "UserInterfaceRenderer.h"

class Builder
{
	enum class ComponentType {
		HOUSE,
		WINDOW,
		DOOR
	};

public:
	Builder() = default;
	~Builder();

	void run();

	void initialise_canvas_dimension();

private:

	void initialise_new_object(const ComponentType& type);

	void build_component(House* s);

	Builder::ComponentType map_num_to_enum(int i) const;

	void draw_all();

	Dimension m_canvasDimension{ 50,50 };

	ConsoleCanvas m_canvas;

	UserInterfaceRenderer m_inputRenderer;
	UserInputHandler m_inputHandler;
};
