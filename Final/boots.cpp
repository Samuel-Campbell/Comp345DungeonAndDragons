#include "boots.h" 

Boots::Boots() {
	srand(time(NULL));
	armor_class = rand() % 11;
	dexterity_amount = rand() % 11;
	itemName = randomName();
}
Boots::Boots(Character *decoratedCharacter)
{
	armor_class = rand() % 11;
	dexterity_amount = rand() % 11;
	itemName = randomName();
	decoratedCharacter->pushItem(this);

}
Boots::Boots(Character *decoratedCharacter, int armor_class, int dexterity, int level) {
	this->armor_class = armor_class;
	this->dexterity_amount = dexterity;
	this->level = level;
	itemName = randomName();
	decoratedCharacter->pushItem(this);
}
double Boots::getIntelligence()
{
	return NULL;
}
std::string Boots::getItem() {
	return "boots";
}
double Boots::getDexterity() {
	return dexterity_amount;
}
double Boots::getDamage()
{
	return NULL;
}
double Boots::getAttack()
{
	return NULL;
}
double Boots::getLevel()
{
	return level;
}
double Boots::getArmorClass() {
	return armor_class;
}
double Boots::getStrength() {
	return NULL;
}
double Boots::getWisdom() {
	return NULL;
}
double Boots::getConstitution() {
	return NULL;
}
double Boots::getCharisma()
{
	return NULL;
}
void Boots::levelStat(int level) {
	armor_class = (level*0.3)*armor_class;
	dexterity_amount = (level*0.3)*dexterity_amount;

}
std::string Boots::getType() {
	return itemName;
}
std::string Boots::randomName() {
	names = std::vector<std::string>();
	double r = 0;
	r = rand() % 3;
	names.push_back("spped");
	names.push_back("dancing");
	names.push_back("teleportation");


	itemName = names.at(r);
	return itemName;
}