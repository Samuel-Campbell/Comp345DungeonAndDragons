#include "stdafx.h"
#include "Player.h"
#include <random>
#include <iostream>
#include <cstdlib>
#include <ctime>

Player::Player(){
	srand(time(NULL));
	int strength = ((rand() % 15 + 3) - 10) / 2;
	int dexterity = ((rand() % 15 + 3) - 10) / 2;
	int constitution = ((rand() % 15 + 3) - 10) / 2;
	int intelligence = ((rand() % 15 + 3) - 10) / 2;
	int wisdom = ((rand() % 15 + 3) - 10) / 2;
	int charisma = ((rand() % 15 + 3) - 10) / 2;

	abilityScores[0] = strength * 2 + 10;
	abilityScores[1] = dexterity * 2 + 10;
	abilityScores[2] = constitution * 2 + 10;
	abilityScores[3] = intelligence * 2 + 10;
	abilityScores[4] = wisdom * 2 + 10;
	abilityScores[5] = charisma * 2 + 10;

	Player::setStats();
	// Initial level is 1...
	level = 1;

	// and set hit points to 10 + constitution
	currentHitPoints = 10 + constitution;

	// Set the armor
	int armor = 10 + dexterity;

	Player::setType("Player");
}

void Player::setType(std::string _type) {
	type = _type;
}

void Player::setStats() {
	strength = (abilityScores[0] -10) / 2 ;
	dexterity = (abilityScores[1] - 10) / 2;
	constitution = (abilityScores[2] - 10) / 2;
	intelligence = (abilityScores[3] - 10) / 2;
	wisdom = (abilityScores[4] - 10) / 2;
	charisma = (abilityScores[5] - 10) / 2;
	armor = 10 + dexterity;
}