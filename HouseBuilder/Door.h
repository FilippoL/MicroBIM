#pragma once
#include "House.h"

class Door : public House
{
public:
	Door();
	~Door() override = default;

	bool initialise_position() override;

private:
	bool m_retrievedPositions = false;
};
