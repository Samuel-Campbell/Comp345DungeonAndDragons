#include "weapon.h" 

Weapon::Weapon() {
	srand(time(NULL));
	attack_bonus = rand() % 15;
	damage_bonus = rand() % 11;
	itemName = randomName();

}
Weapon::Weapon(Character *decoratedCharacter) {
	attack_bonus = rand() % 15;
	damage_bonus = rand() % 11;
	itemName = randomName();
	decoratedCharacter->pushItem(this);
}
Weapon::Weapon(Character *decoratedCharacter, int ar, int dam, int l) {
	attack_bonus = ar;
	damage_bonus = dam;
	level = l;
	itemName = randomName();
	decoratedCharacter->pushItem(this);
}
std::string Weapon::getItem() {
	return "weapon";
}

double Weapon::getAttack() {
	return attack_bonus;
}
double Weapon::getLevel()
{
	return level;
}
//return the damage amount for this item
double Weapon::getDamage() {
	return damage_bonus;
}
double Weapon::getIntelligence()
{
	return NULL;
}
double Weapon::getWisdom()
{
	return NULL;
}
double Weapon::getArmorClass()
{
	return NULL;
}
double Weapon::getStrength()
{
	return NULL;
}
double Weapon::getConstitution()
{
	return NULL;
}
double Weapon::getCharisma()
{
	return NULL;
}
double Weapon::getDexterity()
{
	return NULL;
}
void Weapon::levelStat(int level) {
	attack_bonus = (level*0.3)*attack_bonus;
	damage_bonus = (level*0.3)*damage_bonus;
}
std::string Weapon::getType()
{
	return itemName;

}
std::string Weapon::randomName() {
	names = std::vector<std::string>();
	double r = 0;
	r = rand() % 3;
	names.push_back("Light Blade");
	names.push_back("Knife");
	names.push_back("Spear");


	itemName = names.at(r);
	return itemName;
}