#ifndef RING_H
#define RING_H

#include "item.h"


class Ring :public Item
{
private:
	int armor_class;
	int strength_amount;
	int constitution_amount;
	int wisdom_amount;
	int charisma_amount;
	int level;
	std::string itemName;

public:
	Ring();
	Ring(Character *decoratedCharacter);
	Ring(Character *decoratedCharacter, int a, int s, int ca, int w, int c, int lvl);
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