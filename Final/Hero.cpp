#include "stdafx.h"
#include "Hero.h"


Hero::Hero()
{
}

Hero::Hero(std::string characterClass, std::string subClass) {
	hero = new CharacterBuilder(characterClass, subClass);
	f;
}

void Hero::displayStats() {
	hero->displayStats();
}

void Hero::levelUp() {
	hero->levelUp();
}

//////////////////////////
// Items


//get vector of items
vector<Item> Hero::getVector() {
	return f.getVector();
}

void Hero::displayAvailableItems() {
	for (int i = 0; i< f.getVector().size(); i++) {
		cout << "Item #" << i << " ";
		displayItems(f.getVector().at(i).getType());
	}

}
//display available items by type
void Hero::displayItems(string type) {
	cout << type << endl;
	cout << "Armor : " << f.getItemFromType(type).getArmor() << endl;
	cout << "Attack : " << f.getItemFromType(type).getAttack() << endl;
	cout << "Intelligence : " << f.getItemFromType(type).getIntelligence() << endl;
	cout << "Wisdom : " << f.getItemFromType(type).getWisdom() << endl;
	cout << "Strength : " << f.getItemFromType(type).getStrength() << endl;
	cout << "Constitution : " << f.getItemFromType(type).getConstitution() << endl;
	cout << "Dexterity : " << f.getItemFromType(type).getDexterity() << endl;
	cout << "Charisma : " << f.getItemFromType(type).getCharisma() << endl;
	cout << "Damage : " << f.getItemFromType(type).getDamage() << endl;
	cout << endl << endl;
}


/*
void Character::setAttackBonus(int amountBonus){
attackBonus += amountBonus;
}
*/



void Hero::useItem(int itemNum) {
	// add up item power to current character health

	//set new armor amount with the item used
	hero->returnCharacter()->setArmor(f.getVector().at(itemNum).getArmor());

	//set new attack
	////////////////// FIX THIS/////////////////////////
	//hero->returnClass()->setAttackBonus(f.getVector().at(itemNum).getAttack());

	//set new intelligence with the item used
	hero->returnCharacter()->setIntelligence(f.getVector().at(itemNum).getIntelligence());

	//set new wisdom with the item used
	hero->returnCharacter()->setWisdom(f.getVector().at(itemNum).getWisdom());

	//set new strength with the item used
	hero->returnCharacter()->setStrength(f.getVector().at(itemNum).getStrength());

	//set new constitution with the item used
	hero->returnCharacter()->setConstitution(f.getVector().at(itemNum).getConstitution());

	//set new dexterity with the item used
	hero->returnCharacter()->setDexterity(f.getVector().at(itemNum).getDexterity());

	//set new charisma with the item used
	hero->returnCharacter()->setCharisma(f.getVector().at(itemNum).getCharisma());

	//set new damage with the item used
	////////////////// FIX THIS/////////////////////////
	//hero->returnClass()->setDamage(f.getVector().at(itemNum).getDamage());

	//delete as well the item from the vector
	f.deleteItem(itemNum);

	//notify view
	Notify();
}

