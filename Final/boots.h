#ifndef BOOTS_H
#define BOOTS_H

#include "item.h"


class Boots :public Item {

	int armor_class;
	int dexterity_amount;
	int level;
	std::string itemName;

public:
	Boots();
	Boots(Character *decoratedCharacter);
	Boots(Character *decoratedCharacter, int armor_class, int dexterity, int lvl);
	double getIntelligence();
	double getWisdom();
	double getArmorClass();
	double getStrength();
	double getConstitution();
	double getCharisma();
	double getDexterity();
	double getDamage();
	double getAttack();
	double getLevel();

	void levelStat(int level);
	std::string getType();
	std::string getItem();
	std::string randomName();
	std::vector<std::string> names;
};

#endif