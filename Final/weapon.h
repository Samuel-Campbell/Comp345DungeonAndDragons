#ifndef WEAPON_H
#define WEAPON_H

#include "item.h"


class Weapon :public Item
{
private:
	int attack_bonus;
	int damage_bonus;
	int level;
	std::string itemName;
public:
	Weapon();
	Weapon(Character *decoratedCharacter);
	Weapon(Character *decoratedCharacter, int att, int dam, int l);
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