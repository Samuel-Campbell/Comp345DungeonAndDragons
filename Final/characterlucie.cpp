
#include "character.h"
#include <random>
#include <iostream>
#include <cstdlib>
#include <ctime>

//**********NEW
void Character::setAttackBonus(int level){
	// variable to decrease by five
	int Decrease5 = level;
	NumberAttack = 0;
	//we begin to affect the highest value of attack
	int ind = 0;
	while (Decrease5>0 || ind<4) { //4=attackBonus size
		attackBonus[ind] = Decrease5;
		NumberAttack++;
		Decrease5 = Decrease5 - 5;
		ind++;
	}
}

//roll a dice xdy+z x=times, y=typeDice z=NbToAdd
int roll(int times, int typeDice, int NbToAdd=0){
	srand(time(NULL));
	int result = NbToAdd;
	for (int idx = 0; idx < times; idx++){
		result += rand() % typeDice + 1;
	}
}

void Combat(Character* personnage, Character* monster){
	int characterRoll = roll(1,20) + personnage->attackBonus; //1. roll a d20 (this is your attack roll)and add your attack bonus
	if (characterRoll) >= (monster->Character::getArmor()) //3. if this number is greater or equal than the armor class of your enemy, you hit.
		if (characterRoll) >= (monster->Character::getArmor()) //3. if this number is greater or equal than the armor class of your enemy, you hit.
		{
		//empty;
		}
		else // If not, you miss.
		{                                // to determine how much damage you do on a hit:
			int damageAttack = roll(1,8); //1. roll a dice (for a long sword, a d8)
			personnage->Character::setDamage(damageAttack);//2. add your damage bonus
			personnage->Character::getHitPoints(setHitPoints() - damageAttack);
		}
}

//function need for Character()
int ComputeScore(){
	// we roll 4*1d6
	const int NbOfDice = 4;
	int ScoreArray[NbOfDice];
	int Sum = 0;
	for (int ind = 0; ind <NbOfDice; ind++) {
		ScoreArray[ind] = roll(1, 6);
		Sum += ScoreArray[ind];
	}
	//We find the minimum roll
	int Min = ScoreArray[0];
	for (int ind = 2; ind < NbOfDice; ind++) {
		if (ScoreArray[ind]< Min)
			Min = ScoreArray[ind];
	}
	//We substract the minimum to the sum of all rolls and apply the modify
	return ((Sum - Min) - 10) / 2;
}

//! Constructor: passes values to each ability score and set hit points to 10
Character::Character(){
	//Roll 4d6 and select the 3 highest dice values


	strength = ComputeScore();
	abilityScores[0] = strength * 2 + 10;

	dexterity = ComputeScore();
	abilityScores[1] = dexterity * 2 + 10;

	constitution = ComputeScore();
	abilityScores[2] = constitution * 2 + 10;

	intelligence = ComputeScore();
	abilityScores[3] = intelligence * 2 + 10;

	wisdom = ComputeScore();
	abilityScores[4] = wisdom * 2 + 10;

	charisma = ComputeScore();
	abilityScores[5] = charisma * 2 + 10;

	damage = roll(1,20) + strength;

	// Initial level is 1
	level = 1;
	for (int i = 1; i < 4; i++){
		attackBonus[i] = 0;
	}
	attackBonus[0] = 1;

	// and set hit points to 10 + constitution
	currentHitPoints = 10 + constitution;

	// Set the armor
	armor = roll(1,20) + dexterity;
}

//*************************** END OF MODIFICATION

// Getters
// Get hit points
int Character::getHitPoints()
{
	return currentHitPoints;
}

// Get strength
int Character::getStrength() {
	return strength;

}

// Get dexterity
int Character::getDexterity() {
	return dexterity;
}

// Get constitution
int Character::getConstitution() {
	return constitution;
}

// get intelligence
int Character::getIntelligence() {
	return intelligence;
}

// get wisdom
int Character::getWisdom() {
	return wisdom;
}


// get charisma
int Character::getCharisma() {
	return charisma;
}

int Character::getArmor() {
	return armor;
}

int Character::getLevel() {
	return level;
}

void Character::setLevel(int lvl) {
	level = lvl;
}

void Character::setHitPoint(int pts) {
	currentHitPoints = pts;
}

void Character::setStrength(int str) {
	strength = str;
}

void Character::setDexterity(int dex) {
	dexterity = dex;
}
void Character::setConstitution(int cons) {
	constitution = cons;
}
void Character::setIntelligence(int intel) {
	intelligence = intel;
}
void Character::setWisdom(int wis) {
	wisdom = wis;
}
void Character::setCharisma(int cha) {
	charisma = cha;
}
void Character::setArmor(int arm) {
	armor = arm;
}



