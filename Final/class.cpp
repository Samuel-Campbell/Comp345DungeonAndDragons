#include "class.h"



// Automatically set a character to a specific level --> No cap yet. Too many different rules
void Class::setLevelUp(int newLevel) {
	int level = Character::getLevel();
	if (level < newLevel) {
		if (newLevel < 20) {
			//Will randomly generate random stats every level
			for (int i = level; i < newLevel; i++) {
				levelUp();
			}
		}
		else {
			// Max level is 20
			for (int i = level; i < 20; i++) {
				levelUp();
			}
		}
	}
}



// Levels up a character and all corresponding stats
void Class::levelUp() {
	int level = Character::getLevel();
	int currentHitPoints = Character::getHitPoints();
	int constitution = Character::getConstitution();
	int dice = Class::getDice();
	int* baseAttackBonus = Class::getBaseAttackBonus();
	int* attackBonus = Class::getAttackBonus();
	int attackBonusRate = Class::getAttackBonusRate();

	level++;
	Character::setLevel(level);

	//Character can't gain less than 1 hp per level, so we do a verificatio nhere
	int temp = currentHitPoints + constitution + (rand() % dice + 1);

	if (temp <= 0) {
		currentHitPoints++;
		Character::setHitPoint(currentHitPoints);
	}
	//Or else the normal procedure is followed
	else {
		currentHitPoints = temp;
		Character::setHitPoint(currentHitPoints);
	}

	// Get base atttack bonus

	// This algorithm will keep track of when to give a character additional attacks

	///////////////////////////////////////////////////////////////////////////////////////
	// Example: level 17 Fighter leveling to 18
	// level 17 attack bonus = 17 / 12 / 7 / 2
	// 1) 17 mod 5 = 2
	// 2) 17 - 2 = 15
	// 3) 15 / 5 = 3
	// 4) 3++ = 4
	// 5) So we know that at level 17 a fighter has 4 attacks and we increment all of them
	///////////////////////////////////////////////////////////////////////////////////////
	int updateNb;
	int remainder;

	remainder = baseAttackBonus[0] % 5;

	updateNb = (baseAttackBonus[0] - remainder) / 5;
	updateNb++;

	for (int i = 0; i < updateNb; i++) {
		baseAttackBonus[i] += attackBonusRate;
	}


	Class::setBaseAttackBonus(baseAttackBonus);
	
	// Update actual attack bonus
	for (int i = 0; i <4; i++) {
		//We only want to update fields that have been initialized
		if (baseAttackBonus[i] != 0) {
			attackBonus[i] = baseAttackBonus[i];
		}
	}

	Class::setAttackBonus(attackBonus);
}

// Setters
int Class::getDice() {
	return dice;
}

int* Class::getAttackBonus(){
	return attackBonus;
}

int* Class::getBaseAttackBonus() {
	return baseAttackBonus;
}

int Class::getAttackBonusRate(){
	return attackBonusRate;
}

std::string Class::getClassName() {
	return className;
}
