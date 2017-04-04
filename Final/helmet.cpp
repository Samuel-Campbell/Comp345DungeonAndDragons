#include "helmet.h" 

Helmet::Helmet() {
	srand(time(NULL));
	armor_class = rand() % 4;
	wisdom_amount = rand() % 11;
	intelligence_amount = rand() % 45;
	itemName = randomName();

}
Helmet::Helmet(Character *decoratedCharacter) {
	armor_class = rand() % 4;
	wisdom_amount = rand() % 11;
	intelligence_amount = rand() % 66;
	itemName = randomName();
	decoratedCharacter->pushItem(this);
}
Helmet::Helmet(Character *decoratedCharacter, int intelligence, int wisdom, int armor, int level) {
	this->armor_class = armor;
	this->wisdom_amount = wisdom;
	this->intelligence_amount = intelligence;
	this->level = level;
	this->itemName = randomName();
	decoratedCharacter->pushItem(this);

}

std::string Helmet::getItem() {
	return  "helmet";
}
void Helmet::levelStat(int level) {
	armor_class = (level*0.3)*armor_class;
	wisdom_amount = (level*0.3)*wisdom_amount;
	intelligence_amount = (level*0.3)*intelligence_amount;

}
double Helmet::getIntelligence() {
	return intelligence_amount;
}
double Helmet::getWisdom() {
	return wisdom_amount;
}
double Helmet::getArmorClass() {
	return armor_class;
}
std::string Helmet::getType() {
	return itemName;
}
std::string Helmet::randomName() {
	names = std::vector<std::string>();
	double r = 0;
	r = rand() % 3;
	names.push_back("bronze");
	names.push_back("silver");
	names.push_back("diamond");


	itemName = names.at(r);
	return itemName;
}
double Helmet::getStrength() {
	return NULL;
}
double Helmet::getConstitution() {
	return NULL;
}

double Helmet::getCharisma()
{
	return NULL;
}

double Helmet::getDexterity()
{
	return NULL;
}

double Helmet::getDamage()
{
	return NULL;
}

double Helmet::getAttack()
{
	return NULL;
}

double Helmet::getLevel()
{
	return level;
}
