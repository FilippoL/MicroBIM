#pragma once
#include "House.h"

class Window : public HouseEntity, public IInitialiser
{
	//TODO: implementare set_position per la propria position e tutte le shapes che la compongono
public:
	Window();
	~Window() override = default;

	bool initialise_size() override;
private:
	bool m_answered = false;
	bool m_isRound = false;

	Shape* window;

	Circle m_roundWindow;
	Box m_squaredWindow;
};
