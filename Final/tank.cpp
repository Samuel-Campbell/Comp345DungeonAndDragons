#include "tank.h"

Tank::Tank(){
	Tank::setSpecialAbility("Eat Damage");
	Tank::setSubClass("Tank");
}

void Tank::setSpecialAbility(std::string _ability){
    ability = _ability;
}

void Tank::setSubClass(std::string _subClass){
	subClass = _subClass;
}
