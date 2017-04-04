
#include "character.h"
#include "boots.h"
#include "helmet.h"
#include "belt.h"
#include "ring.h"
#include "weapon.h"

//! Constructor: passes values to each ability score and set hit points to 10
Character::Character(){
}

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
int Character::getDamage() {
	return damage;
}

void Character::setDamage(int dama)
{
	damage = dama;
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

void Character::setAbilityScore(int index, int value) {
	abilityScores[index] = value;
}

std::string Character::getType() {
	return type;
}

std::string Character::getCharacterName() {
	return characterName;
}

void Character::setCharacterName(std::string _name) {
	characterName = _name;
}

int Character::getAbilityScore(int index) {
	return abilityScores[index];
}

void Character::setAbilityChar() {
	strength = (abilityScores[0] - 10) / 2;
	dexterity = (abilityScores[1] - 10) / 2;
	constitution = (abilityScores[2] - 10) / 2;
	intelligence = (abilityScores[3] - 10) / 2;
	wisdom = (abilityScores[4] - 10) / 2;
	charisma = (abilityScores[5] - 10) / 2;
	armor = 10 + dexterity;
}

bool Character::increaseExp(Character* c) {
	if ((experience / 100) < level) {
		experience = experience + (0.05 * wisdom * c->getLevel());
		return false;
	}
	else {
		experience = 0;
		level++;
		remainingHitPoints = currentHitPoints;
		return true;
	}
}

bool Character::Attack(Character* c) {
	int multiplier = floor(strength + 0.5*dexterity + 4);
	int damage = rand() % 10 + 1;
	damage = damage * multiplier;
	std::cout << characterName << " attacks " << c->getCharacterName() << "!" << std::endl;
	std::cout << "Attack strength: " << damage << std::endl;
	if (c->Suffer(damage)) {
		increaseExp(c);
		return true;
	}
	return false;
}

int Character::Defend() {
	int multiplier = floor(0.25*constitution + 0.05*dexterity) + 3;
	int mitigation = rand() % getLevel() + 1;
	mitigation = mitigation * multiplier;
	std::cout << characterName << " defends!" << std::endl;
	std::cout << "Defense strength: " << mitigation << std::endl;
	return mitigation;
}

bool Character::Flee(Character* c) {
	return (rand() % (dexterity + 4) + 1 > (c->getLevel() - level) + 4);
}

bool Character::Suffer(int damage) {
	int hplost = abs(floor(damage / (Defend())));
	remainingHitPoints = remainingHitPoints - hplost;
	std::cout << characterName << " loses " << hplost << " health points!" << std::endl;
	std::cout << characterName << "'s CURRENT HP: " << remainingHitPoints << std::endl;
	if (remainingHitPoints <= 0) {
		remainingHitPoints = 0;
		return true;
	}
	return false;
}

bool Character::Fight(Character* c) {


	std::cout << "++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "STATS for " << characterName << std::endl;
	std::cout << "++++++++++++++++++++++++++++++++++++++++" << std::endl;

	// Display Adam stats
	this->displayStats();

	std::cout << "++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "STATS for " << c->getCharacterName() << std::endl;
	std::cout << "++++++++++++++++++++++++++++++++++++++++" << std::endl;

	// Display Eve stats
	c->displayStats();

	std::cout << "++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "FIGHT BEGINS" << std::endl;
	std::cout << "++++++++++++++++++++++++++++++++++++++++" << std::endl;

	bool over = false;
	bool pturn = true;
	std::string userInput = "";
	while (!over) {
		pturn = true;
		while (pturn) {
			std::cout << "Enter 1 to attack or 2 to flee." << std::endl;
			std::cin >> userInput;
			if (userInput == "1") {
				over = this->Attack(c);
				if (over) {
					std::cout << "++++++++++++++++++++++++++++++++++++++++" << std::endl;
					std::cout << this->getCharacterName() << " wins!" << std::endl;
					std::cout << "++++++++++++++++++++++++++++++++++++++++" << std::endl;
				}
				pturn = false;
			}
			else if (userInput == "2") {
				over = this->Flee(c);
				if (over) {
					std::cout << "++++++++++++++++++++++++++++++++++++++++" << std::endl;
					std::cout << this->getCharacterName() << " flees!" << std::endl;
					std::cout << "++++++++++++++++++++++++++++++++++++++++" << std::endl;
				}
				pturn = false;
			}
			else {
				std::cout << "BAD INPUT!" << std::endl;
			}
		}

		if (!over) {
			over = c->Attack(this);
			if (over) {
				std::cout << "++++++++++++++++++++++++++++++++++++++++" << std::endl;
				std::cout << c->getCharacterName() << " wins!" << std::endl;
				std::cout << "++++++++++++++++++++++++++++++++++++++++" << std::endl;
				return false;
			}
		}
	}
	return true;
}

void Character::ForceLevelUp() {
	experience = 0;
	level++;
	remainingHitPoints = currentHitPoints;
}

int Character::getRemainingHp() {
	return remainingHitPoints;
}
//stuff to control the items

void Character::pushItem(Item* a) {
	inventory.push_back(a); 
}
void Character::deleteInventoryItem(int position) {
	inventory.erase(inventory.begin() + (position));
}

void Character::displayInventory() {
	int count = 0;
	std::cout << "********************CHARACTER INVENTORY********************";
	std::cout << std::endl << std::endl;
	for (Item* i : inventory) {
		std::cout << "*****IVENTORY ITEM*****: ";
		std::cout << i->getItem();
		std::cout << std::endl;
		std::cout << "Item Number #: " << count;
		std::cout << std::endl;
		std::cout << "Type :" << i->getType();
		std::cout << std::endl;

		if (!(i->getArmorClass() == NULL)) {
			std::cout << "Armor:";
			std::cout << i->getArmorClass();
			std::cout << std::endl;

		}
		if (!(i->getAttack() == NULL)) {
			std::cout << "Attack:";
			std::cout << i->getAttack();
			std::cout << std::endl;


		}
		if (!(i->getCharisma() == NULL)) {
			std::cout << "Charisma:";
			std::cout << i->getConstitution();
			std::cout << std::endl;


		}
		if (!(i->getDamage() == NULL)) {
			std::cout << "Damage:";
			std::cout << i->getDamage();
			std::cout << std::endl;


		}
		if (!i->getDexterity() == NULL) {
			std::cout << "Dexterity:";
			std::cout << i->getDexterity();
			std::cout << std::endl;


		}
		if (!(i->getIntelligence() == NULL)) {
			std::cout << "Intelligence:";
			std::cout << i->getIntelligence();
			std::cout << std::endl;

		}
		if (!(i->getStrength() == NULL)) {
			std::cout << "Strength:";
			std::cout << i->getStrength();
			std::cout << std::endl;


		}
		if (!(i->getWisdom() == NULL)) {
			std::cout << "Wisdom:";
			std::cout << i->getWisdom();
			std::cout << std::endl;


		}
		std::cout << std::endl;
		std::cout << std::endl;

		count++; 
	}
}
void Character::addToInventory(Item *a) {
	inventory.push_back(a);
	std::cout << "Item added to the character's Inventory";
}
void Character::useItem(Character *a, int position) {
	std::cout << "FOLLOWING ITEM HAS BEEN USED";
	std::cout << std::endl;
	if (a->inventory.at(position)->getItem() == "helmet") {
		std::cout << "*****Item ***** : " << a->inventory.at(position)->getItem();
		std::cout << std::endl;
		std::cout << "Type : " << a->inventory.at(position)->getType();
		std::cout << std::endl;
		std::cout << "Intelligence : " << a->inventory.at(position)->getIntelligence();
		std::cout << std::endl;
		std::cout << std::endl;

		//set new stat for the character
		a->setIntelligence(a->getIntelligence() + a->inventory.at(position)->getIntelligence());
	}
	else if (a->inventory.at(position)->getItem() == "belt") {
		std::cout << "Item : " << a->inventory.at(position)->getItem();
		std::cout << std::endl;
		std::cout << "Type : " << a->inventory.at(position)->getType();
		std::cout << std::endl;
		std::cout << "Stength : " << a->inventory.at(position)->getStrength();
		std::cout << std::endl;
		std::cout << "Constitution : " << a->inventory.at(position)->getConstitution();
		std::cout << std::endl;
		std::cout << std::endl;

		//set new stat for the character
		a->setConstitution(a->getConstitution() + a->inventory.at(position)->getConstitution());
		a->setStrength(a->getStrength() + a->inventory.at(position)->getStrength());


	}
	else if (a->inventory.at(position)->getItem() == "boots") {
		std::cout << "*****Item***** : " << a->inventory.at(position)->getItem();
		std::cout << std::endl;
		std::cout << "Type : " << a->inventory.at(position)->getType();
		std::cout << std::endl;
		std::cout << "Armor class : " << a->inventory.at(position)->getArmorClass();
		std::cout << std::endl;
		std::cout << "Dexterity : " << a->inventory.at(position)->getDexterity();
		std::cout << std::endl;
		std::cout << std::endl;

		//set new stat for the character
		a->setArmor(a->getArmor() + a->inventory.at(position)->getArmorClass());
		a->setDexterity(a->getDexterity() + a->inventory.at(position)->getDexterity());
	}
	else if (a->inventory.at(position)->getItem() == "ring") {
		std::cout << "*****Item***** : " << a->inventory.at(position)->getItem();
		std::cout << std::endl;
		std::cout << "Type : " << a->inventory.at(position)->getType();
		std::cout << std::endl;
		std::cout << "Armor class : " << a->inventory.at(position)->getArmorClass();
		std::cout << std::endl;
		std::cout << "Wisdom : " << a->inventory.at(position)->getWisdom();
		std::cout << std::endl;
		std::cout << "Constitution : " << a->inventory.at(position)->getConstitution();
		std::cout << std::endl;
		std::cout << "Charisma : " << a->inventory.at(position)->getCharisma();
		std::cout << std::endl;
		std::cout << "Strength : " << a->inventory.at(position)->getStrength();
		std::cout << std::endl;
		std::cout << std::endl;

		//set new stat for the character
		a->setArmor(a->getArmor() + a->inventory.at(position)->getArmorClass());
		a->setWisdom(a->getWisdom() + a->inventory.at(position)->getWisdom());
		a->setConstitution(a->getConstitution() + a->inventory.at(position)->getConstitution());
		a->setCharisma(a->getCharisma() + a->inventory.at(position)->getCharisma());
		a->setStrength(a->getStrength() + a->inventory.at(position)->getStrength());

	}
	else if (a->inventory.at(position)->getItem() == "shield") {
		std::cout << "*****Item***** : " << a->inventory.at(position)->getItem();
		std::cout << std::endl;
		std::cout << "Type : " << a->inventory.at(position)->getType();
		std::cout << std::endl;
		std::cout << "Armor class : " << a->inventory.at(position)->getArmorClass();
		std::cout << std::endl;

		//set new stat for the character
		a->setArmor(a->getArmor() + a->inventory.at(position)->getArmorClass());


	}
	else if (a->inventory.at(position)->getItem() == "weapon") {
		std::cout << "*****Item***** : " << a->inventory.at(position)->getItem();
		std::cout << std::endl;
		std::cout << "Type : " << a->inventory.at(position)->getType();
		std::cout << std::endl;
		std::cout << "Attack Bonus : " << a->inventory.at(position)->getAttack();
		std::cout << std::endl;
		std::cout << "Damage : " << a->inventory.at(position)->getDamage();
		std::cout << std::endl;


		//set new stat for the character 
		a->setDamage(a->getDamage() + a->inventory.at(position)->getDamage());



	}
	deleteInventoryItem(position);
}
void Character::loadDefaultInventory(Character *c) {
	new Boots(c);
	new Weapon(c);
}
