#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>
#include <vector>
#include "item.h"

class Item;
//! Class that implements a character
class Character
{
public:
	////Character constructors
	Character();
	////////////////////////////////////////////////////////////////NEW
	// COMBAT FUNCTIONS
	bool Flee(Character* c);
	bool Attack(Character* c);
	int Defend();
	bool Suffer(int damage);
	bool increaseExp(Character* c);
	bool Fight(Character* c);
	void ForceLevelUp();


	////////////////////////
	// GETTERS
	int getDamage();
	int getHitPoints();
	int getStrength();
	int getDexterity();
	int getConstitution();
	int getIntelligence();
	int getWisdom();
	int getCharisma();
	int getArmor();
	int getLevel();
	int getAbilityScore(int index);
	std::string getType();
	std::string getCharacterName();
	int getRemainingHp();

	////////////////////////
	// SETTERS
	void setLevel(int);
	void setHitPoint(int);
	void setStrength(int);
	void setDexterity(int);
	void setConstitution(int);
	void setIntelligence(int);
	void setWisdom(int);
	void setCharisma(int);
	void setArmor(int);
	void setAbilityScore(int index, int value);
	void setDamage(int);
	//////////////////////////////
	// Virtual Methods
	virtual void setLevelUp(int level) {};
	virtual void levelUp() {};
	virtual void displayStats() {};
	virtual void setType(std::string type) {};
	virtual std::string getSubClass() { return NULL; }
	void setCharacterName(std::string name);
	
	void setAbilityChar();

	//////////////////////////////
	// Panel stuff


	/////////////////////////////////
	// Instance variables
	/////////////////////////////////
	// Instance variables
	bool inCombat;
	std::string type;
	int abilityScores[6];
	int level;
	int strength = 0;
	int dexterity = 0;
	int constitution = 0;
	int intelligence = 0;
	int wisdom = 0;
	int charisma = 0;
	int currentHitPoints = 0;
	int remainingHitPoints; // WORK WITH THIS ONE FOR COMBAT
	int armor = 0;
	int experience = 0;
	int damage = 0;
	std::string characterName;
	Character *decoratedItem;


	//stuff for items
	std::vector<Item*> inventory = std::vector<Item*>();

	void pushItem(Item* a);
	void deleteInventoryItem(int position);
	void displayInventory();
	void addToInventory(Item* a); 
	void useItem( Character *c, int position);
	void loadDefaultInventory(Character *c);
 
};

#endif // CHARACTER_H