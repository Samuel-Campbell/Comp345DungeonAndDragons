#include "belt.h" 

Belt::Belt() {
	srand(time(NULL));
	strength_amount = rand() % 5;
	constitution_amount = rand() % 2;
	itemName = randomName();

}

Belt::Belt(Character *decoratedCharacter) {
	strength_amount = rand() % 5;
	constitution_amount = rand() % 2;
	itemName = randomName();
	decoratedCharacter->pushItem(this);
}



Belt::Belt(Character *decoratedCharacter, int c, int s, int level) {
	this->strength_amount = c;
	this->constitution_amount = s;
	this->level = level;
	itemName = randomName();
	decoratedCharacter->pushItem(this);
}

std::string Belt::getItem() {
	return "belt";
}
void Belt::levelStat(int level) {
	strength_amount = (level*0.3)*strength_amount;
	constitution_amount = (level*0.3)*constitution_amount;

}
//return the constitution amount for this item
double Belt::getConstitution() {
	return constitution_amount;
}
//return the strength amount for this item
double Belt::getStrength() {
	return strength_amount;
}
double Belt::getWisdom() {
	return NULL;
}
double Belt::getArmorClass() {
	return NULL;
}
double Belt::getIntelligence() {
	return NULL;
}
double Belt::getCharisma() {
	return NULL;
}
double Belt::getDexterity()
{
	return NULL;
}
double Belt::getDamage()
{
	return NULL;
}
double Belt::getAttack()
{
	return NULL;
}
double Belt::getLevel()
{
	return level;
}
std::string Belt::getType() {
	return itemName;
}

std::string Belt::randomName() {
	names = std::vector<std::string>();
	double r = 0;
	r = rand() % 3;
	names.push_back("Epic");
	names.push_back("Giant");
	names.push_back("Dwaverkind");


	itemName = names.at(r);
	return itemName;
}