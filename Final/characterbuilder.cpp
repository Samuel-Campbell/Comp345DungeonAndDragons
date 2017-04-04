#include "characterbuilder.h"

CharacterBuilder::CharacterBuilder(std::string someClass, std::string subclass){
    character = new Character();

    if (someClass == "Fighter"){
        characterClass = new Fighter();
    }

    if (subclass == "Nimble"){
        subClass = new Nimble();
    }
    else if(subclass == "Bully"){
        subClass = new Bully();
    }
    else if (subclass == "Tank"){
        subClass = new Tank();
    }
}

// Levels up a character and all corresponding stats
void CharacterBuilder::levelUp(){
    int level = character->getLevel();
    int currentHitPoints = character->getHitPoints();
    int constitution = character->getConstitution();
    int dice = characterClass->getDice();
    int* baseAttackBonus = characterClass->getBaseAttackBonus();
    int* attackBonus = characterClass->getAttackBonus();
    int attackBonusRate = characterClass->getAttackBonusRate();

    level++;
    character->setLevel(level);

    //Character can't gain less than 1 hp per level, so we do a verificatio nhere
    int temp = currentHitPoints + constitution + (rand()% dice + 1);

    if (temp <= 0){
        currentHitPoints++;
        character->setHitPoint(currentHitPoints);
    }
    //Or else the normal procedure is followed
    else{
        currentHitPoints = temp;
        character->setHitPoint(currentHitPoints);
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
    updateNb ++;

    for (int i= 0; i < updateNb; i++){
        baseAttackBonus[i] += attackBonusRate;
    }

    characterClass->setBaseAttackBonus(baseAttackBonus);

    // Update actual attack bonus
    for (int i = 0; i <4 ; i++){
        //We only want to update fields that have been initialized
        if (baseAttackBonus[i] != 0){
            attackBonus[i] = baseAttackBonus[i];
        }
    }

    characterClass->setAttackBonus(attackBonus);

}

// Automatically set a character to a specific level --> No cap yet. Too many different rules
void CharacterBuilder::setLevel(int newLevel){
    int level = character->getLevel();
    if (level < newLevel){
        if (newLevel < 20){
            //Will randomly generate random stats every level
            for (int i = level; i < newLevel; i++){
                levelUp();
            }
        }else{
            // Max level is 20
            for (int i = level; i < 20; i++){
                levelUp();
            }
        }
    }
}

//Display stats for debugging
void CharacterBuilder::displayStats(){
    std::cout << "Class: " << characterClass->getClass() << "\n";
    std::cout << "SubClass: " << subClass->getSubClass() << "\n";
    std::cout << "Special Ability: " << subClass->getSpecialAbility() << "\n";
    std::cout << "Level: " << character->getLevel() << "\n";
    std::cout << "Strenght: " << character->getStrength() << "\n";
    std::cout << "Dexterity: " << character->getDexterity() << "\n";
    std::cout << "Constitution: " << character->getConstitution() << "\n";
    std::cout << "Intelligence: " << character->getIntelligence() << "\n";
    std::cout << "Wisdom: " << character->getWisdom() << "\n";
    std::cout << "Charisma: " << character->getCharisma() << "\n";
    std::cout << "Armor: " << character->getArmor() << "\n";
    std::cout << "AttackBonus: ";

    int* attackBonus = characterClass->getAttackBonus();
    for (int i = 0 ; i< 4; i++){
        std::cout << attackBonus[i] << " / ";
    }
    std::cout << "\n";
    std::cout << "Hit Points: " << character->getHitPoints() << "\n";
}

CharacterBuilder* CharacterBuilder::returnInstance() {
	return this; 
}

SubClass* CharacterBuilder::returnSubClass() {
	return subClass;
}

Class* CharacterBuilder::returnClass() {
	return characterClass;
}

Character* CharacterBuilder::returnCharacter() {
	return character;
}
