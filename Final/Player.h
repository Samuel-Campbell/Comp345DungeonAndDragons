#pragma once
#include "character.h"

class Player: public Character
{
public:
	Player();

	void setType(std::string type);
	void setStats();
};

