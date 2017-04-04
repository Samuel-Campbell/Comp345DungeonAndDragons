#include "fighter.h"

Fighter::Fighter(){
    Fighter::setDice(10);
    int array [4];
    array[0] = 1;
    array[1] = 0;
    array[2] = 0;
    array[3] = 0;

    Fighter::setBaseAttackBonus(array);
    Fighter::setAttackBonus(baseAttackBonus);
    Fighter::setAttackBonusRate(1);
	Fighter::setClassName("Fighter");
}

void Fighter::setDice(int die){
    dice = die;
}

void Fighter::setAttackBonus(int* bonus){
    attackBonus[0] = bonus[0];
    attackBonus[1] = bonus[1];
    attackBonus[2] = bonus[2];
    attackBonus[3] = bonus[3];
}

//set the attack bonus at level 1
void Fighter::setBaseAttackBonus(int* attack){

    baseAttackBonus[0] = attack[0];
    baseAttackBonus[1] = attack[1];
    baseAttackBonus[2] = attack[2];
    baseAttackBonus[3] = attack[3];
}

void Fighter::setAttackBonusRate(int bonus){
    attackBonusRate = bonus;
}

void Fighter::setClassName(std::string name) {
	className = name;
}





