#ifndef HELMET_H
#define HELMET_H

#include "item.h" 

class Helmet :public Item
{
	int armor_class;
	double intelligence_amount;
	int wisdom_amount;
	int level;
	std::string itemName;
public:
	Helmet();
	Helmet(Character *decoratedCharacter);
	Helmet(Character *decoratedCharacter, int intelligence, int wisdom, int armor, int level);
	void levelStat(int lvl);
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
	std::string getType();
	std::string getItem();
	std::vector<std::string> names;
	std::string randomName();
};

#endif