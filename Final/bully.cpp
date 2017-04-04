#include "bully.h"

Bully::Bully() {
	Bully::setSpecialAbility("Dish out the DPS");
	Bully::setSubClass("Bully");
}

void Bully::setSpecialAbility(std::string _ability) {
	ability = _ability;
}

void Bully::setSubClass(std::string _subClass) {
	subClass = _subClass;
}
