/*
* File:   Item.h
* Author: Vanessa Kurt #27748639
*/
#ifndef ITEM_H
#define ITEM_H

#include "Character.h"
#include <vector>
#include <cstdlib>
#include <time.h>  
#include <iostream>
#include <algorithm> 

class Item { 
 public:
	virtual std::string getItem() = 0;
	virtual std::string getType() = 0;
	virtual double getIntelligence() = 0;
	virtual double getWisdom() = 0;
	virtual double getArmorClass() = 0;
	virtual double getStrength() = 0;
	virtual double getConstitution() = 0;
	virtual double getCharisma() = 0;
	virtual double getDexterity() = 0;
	virtual double getDamage() = 0;
	virtual double getAttack() = 0;
	virtual double getLevel() = 0;

	virtual void levelStat(int lvl) = 0;
};
#endif