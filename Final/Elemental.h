#pragma once
#include "character.h"

class Elemental: public Character
{
public:
	Elemental(std::string size);
	void setSize(std::string _size);
	std::string getSize();

	void setName(std::string _name);
	std::string getName();

	void displayStats();
private: 
	std::string size;
	std::string name;
};

