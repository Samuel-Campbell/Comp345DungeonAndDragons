#ifndef SHIELD_H
#define SHIELD_H

#include "item.h"


class Shield :public Item
{
private:
	int armor_class;
	int level;
	std::string itemName;
public:
	Shield();
	Shield(Character *decoratedCharacter);
	Shield(Character *decoratedCharacter, int armorC, int level);
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
	void levelStat(int l);
	std::string getType();
	std::string getItem();
	std::vector<std::string> names;
	std::string randomName();
};

#endif