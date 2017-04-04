#ifndef SUBCLASS_H
#define SUBCLASS_H
#include <string>
#include "fighter.h"

/**
 * @brief The SubClass class: Abstract class for all subclasses
 */
class SubClass: public Fighter
{

public:
	SubClass();
	//////////////////////
	// Virtual Methods
	virtual void setSpecialAbility(std::string ability) {}
	virtual void setSubClass(std::string subClass) {}

	///////////////////////
	// Non Virtual Methods
	void displayStats();
	void subDisplay();

	std::string getSubClass();
	std::string getAbility();

	//////////////////////
	// Instance variables
	std::string ability;
	std::string subClass;
};

#endif // SUBCLASS_H
