#include "stdafx.h"
#include "Elemental.h"


Elemental::Elemental(std::string size){
	// hit dice (2d8)
	//attack slam + 5 melee (1d4)
	if (size == "small") {
		currentHitPoints = 9;
		remainingHitPoints = 9;
		strength = -1;
		dexterity = -1;
		constitution = 0;
		intelligence = -1;
		wisdom =-2;
		charisma = -2;
		level = 3;
	}
	// hit dice (4d8 + 8)
	//attack slam + 5 melee (1d6 + 1)
	else if (size == "medium") {
		currentHitPoints = 26;
		remainingHitPoints = 26;
		strength = 12;
		dexterity = 21;
		constitution = 14;
		intelligence = 4;
		wisdom = 11;
		charisma = 11;
		level = 8;
	}
	// hit dice (8d8 + 24)
	//attack slam + 5 melee (2d6 + 2)
	else if (size == "large") {
		currentHitPoints = 60;
		remainingHitPoints = 60;
		strength = 14;
		dexterity = 25;
		constitution = 16;
		intelligence = 6;
		wisdom = 11;
		charisma = 11;
		level = 15;
	}
}

void Elemental::setSize(std::string _size) {
	size = _size;
}

std::string Elemental::getSize() {
	return size;
}

void Elemental::setName(std::string _name) {
	Character::setCharacterName(_name);
}

std::string Elemental::getName() {
	return name;
}

//Display stats for debugging
void Elemental::displayStats() {
	std::cout << "Name: " << Character::getCharacterName() << "\n";
	std::cout << "Type Of Character: " << Character::getType() << "\n";	
	std::cout << "Level: " << Character::getLevel() << "\n";
	std::cout << "Strenght: " << Character::getStrength() << "\n";
	std::cout << "Dexterity: " << Character::getDexterity() << "\n";
	std::cout << "Constitution: " << Character::getConstitution() << "\n";
	std::cout << "Intelligence: " << Character::getIntelligence() << "\n";
	std::cout << "Wisdom: " << Character::getWisdom() << "\n";
	std::cout << "Charisma: " << Character::getCharisma() << "\n";
	std::cout << "Armor: " << Character::getArmor() << "\n";
	std::cout << "AttackBonus: ";		
	std::cout << "\n";
	std::cout << "Hit Points: " << Character::getHitPoints() << "\n";
}