#ifndef BELT_H
#define BELT_H


#include "item.h"


class Belt :public Item
{

private:
	int strength_amount;
	int constitution_amount;
	int level;
	std::string itemName;

public:
	Belt();
	Belt(Character *decoratedCharacter);
	Belt(Character *decoratedCharacter, int constitution, int strength, int lvl);
	void levelStat(int level);
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
	std::string getItem();
	std::vector<std::string> names;
	std::string getType();
	std::string randomName();
};

#endif