#ifndef CHARACTERBUILDER_H
#define CHARACTERBUILDER_H
#include <string>
#include <iostream>
#include "subclass.h"
#include "class.h"
#include "character.h"
#include "fighter.h"
#include "nimble.h"
#include "tank.h"
#include "bully.h"

/**
 * @brief The CharacterBuilder class: builds a Hero
 */
class CharacterBuilder
{
public:
    /**
     * @brief CharacterBuilder: Builds a hero with a class and subclass
     * @param someClass
     * @param subclass
     */
    CharacterBuilder(std::string someClass, std::string subclass);

    /**
     * @brief levelUp: Level up a character once
     */
    void levelUp();

    /**
     * @brief setLevel: Level up a character x amount of times. Calls levelUp()
     */
    void setLevel(int);

    /**
     * @brief displayStats: Display stats of the hero
     */
    void displayStats();

	CharacterBuilder* returnInstance();
	SubClass* returnSubClass();
	Class* returnClass();
	Character* returnCharacter();

private:
    SubClass* subClass;
    Class* characterClass;
    Character* character;
};

#endif // CHARACTERBUILDER_H
