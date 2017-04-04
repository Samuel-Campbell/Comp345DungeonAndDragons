#include "itemsSaving.h" 
#include <string>
#include <fstream>
ItemsSaving::ItemsSaving() {
	gameVector = std::vector<Item*>();

}
void ItemsSaving::displayGameItems() {
	int count = 0;
	std::cout << "********************ITEMS IN THE GAME********************";
	std::cout << std::endl << std::endl;
	for (Item* i : gameVector) {
		std::cout << "*****ITEMS IN THE GAME*****: ";
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
void ItemsSaving::deleteItem(int position) {
}
void ItemsSaving::push_Game(Item* a) {
	gameVector.push_back(a);
}
void ItemsSaving::loadGameItems(int level) {
	// ****************read inventory from file*****************
	std::cout << "*********************items in the map have been generated based on the level" << level << "************************";
	std::cout << std::endl;
	std::string word;
	std::ifstream myReadFile;
	std::string path;
	//check level when loading game items
	if (level < 6) { 
		path = "gameItems.txt";
	}
	else if (level < 13) {
		path = "gameItems_L6.txt";

	}
	else{
		path = "gameItems_L13.txt";
	}

	myReadFile.open(path);

	while (myReadFile >> word) // To get you all the lines.
	{
		if (word == "boots") {
			push_Game(new Boots());
		}
		else if (word == "belt") {
			push_Game(new Belt());
		}
		else if (word == "helmet") {
			push_Game(new Helmet());
		}
		else if (word == "ring") {
			push_Game(new Ring());
		}
		else if (word == "shield") {
			push_Game(new Shield());
		}
		else if (word == "weapon") {
			push_Game(new Weapon());
		}

	}

	myReadFile.close();

}

void ItemsSaving::loadInventoryItems(Character *c, std::string path) {

	// ****************read inventory from file***************** 
	std::string pathLong = "C:\\Users\\Charmander\\Desktop\\SavedInstances\\Items\\" + path + ".txt";

	std::ifstream file(pathLong, std::ios::in);


	std::string word;
	double level;
	double intelligence;
	double wisdom;
	double armorClass;
	double strength;
	double constitution;
	double charisma;
	double dexterity;
	double damage;
	double attack;

	while (file >> word >> intelligence >> wisdom >> armorClass >> strength >> constitution >> charisma >> dexterity >> damage >> attack >> level) // To get you all the lines.
	{
 
		if (word == "boots") {
			new Boots(c, armorClass, dexterity, level);
		}
		if (word == "belt") {
			new Belt(c, constitution, strength, level);
		}
		if (word == "helmet") {
			new Helmet(c, intelligence, wisdom, armorClass, level);
		}
		if (word == "ring") {
			new Ring(c, armorClass, strength, charisma, wisdom, constitution, level);
		}
		if (word == "shield") {
			new Shield(c, armorClass, level);
		}
		if (word == "weapon") {
			new Weapon(c, attack, damage, level);
		}
		file.close();
	}
}

void ItemsSaving::saveInventoryPlayer(Character *c) {
	std::string pathLong = "C:\\Users\\Charmander\\Desktop\\SavedInstances\\Items\\" + c->getCharacterName() + ".txt";

	// ****************save inventory from file***************** 
	std::ofstream file2;
	file2.open(pathLong); 

	int count = 0;

	if (file2.is_open()) {
		std::cout << c->inventory.size();

		for (Item* i : c->inventory) {
			file2 << i->getItem() << " ";
			file2 << i->getIntelligence() << " ";
			file2 << i->getWisdom() << " ";
			file2 << i->getArmorClass() << " ";
			file2 << i->getStrength() << " ";
			file2 << i->getConstitution() << " ";
			file2 << i->getCharisma() << " ";
			file2 << i->getDexterity() << " ";
			file2 << i->getDamage() << " ";
			file2 << i->getAttack() << " ";
			file2 << i->getLevel(); 
			file2 << std::endl;
		}
	}
	file2.close();

}