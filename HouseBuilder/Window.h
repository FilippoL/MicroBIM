#pragma once
#include "House.h"

class Window : public House
{
public:
	Window();
	~Window() override = default;

	bool initialise_size() override;

private:
	bool init_round_component_dimension(Circle& circle);
	bool m_answered = false;
	bool m_isRound = false;
};
