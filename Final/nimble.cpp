#include "nimble.h"

Nimble::Nimble(){
	Nimble::setSpecialAbility("Use Dexterity");
	Nimble::setSubClass("Nimble");
}

void Nimble::setSpecialAbility(std::string _ability) {
	ability = _ability;
}

void Nimble::setSubClass(std::string _subClass) {
	subClass = _subClass;
}

