#pragma once
#include "House.h"

class Door : public HouseEntity, public IInitialiser
{
public:
	Door();
	~Door() override = default;

	bool initialise_position() override { m_fixedPositionInitialiser.initialise_position(m_currentLabel, m_door); };

private:
	bool m_retrievedPositions = false;
	Box m_door;
};
