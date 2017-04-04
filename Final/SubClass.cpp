#include "subclass.h"

SubClass::SubClass() {

}

std::string SubClass::getSubClass() {
	return subClass;
}

std::string SubClass::getAbility() {
	return ability;
}

void SubClass::subDisplay() {
	std::cout << "SubClass: " << SubClass::getSubClass() << "\n";
	std::cout << "Special Ability: " << SubClass::getAbility() << "\n";
}
//Display stats for debugging
void SubClass::displayStats() {
	std::cout << "Name: " << Character::getCharacterName() << "\n";
	std::cout << "Type Of Character: " << Character::getType() << "\n";
	std::cout << "Class: " << Class::getClassName() << "\n";
	std::cout << "SubClass: " << SubClass::getSubClass() << "\n";
	std::cout << "Special Ability: " << SubClass::getAbility() << "\n";
	std::cout << "Level: " << Character::getLevel() << "\n";
	std::cout << "Strenght: " << Character::getStrength() << "\n";
	std::cout << "Dexterity: " << Character::getDexterity() << "\n";
	std::cout << "Constitution: " << Character::getConstitution() << "\n";
	std::cout << "Intelligence: " << Character::getIntelligence() << "\n";
	std::cout << "Wisdom: " << Character::getWisdom() << "\n";
	std::cout << "Charisma: " << Character::getCharisma() << "\n";
	std::cout << "Armor: " << Character::getArmor() << "\n";
	std::cout << "AttackBonus: ";

	int* attackBonus = Class::getAttackBonus();
	for (int i = 0; i< 4; i++) {
		std::cout << attackBonus[i] << " / ";
	}
	std::cout << "\n";
	std::cout << "Hit Points: " << Character::getHitPoints() << "\n";
}
