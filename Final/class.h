#ifndef CLASS_H
#define CLASS_H
#include <string>
#include "player.h"

class Class: public Player
{
public:
	//////////////////////////
	// Virtual methods
    virtual void setDice(int){}
    virtual void setAttackBonus(int*){}
    virtual void setBaseAttackBonus(int*){}
    virtual void setAttackBonusRate(int){}
	virtual void setClassName(std::string name) {};

	///////////////////////////
	// Non virtual methods

	// Getters
	int getDice();
	int* getAttackBonus();
	int* getBaseAttackBonus();
	int getAttackBonusRate();
	std::string getClassName();

	// Setters
	void setLevelUp(int level);
	void levelUp();

	//////////////////////////
	// Instance Variables
	int dice;
	int attackBonus[4];
	int baseAttackBonus[4];
	int attackBonusRate;
	std::string className;
};

#endif // CLASS_H
