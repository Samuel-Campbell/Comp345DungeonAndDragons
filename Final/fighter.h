#ifndef FIGHTER_H
#define FIGHTER_H
#include "class.h"

/**
 * @brief The Fighter class: Concrete Class of Class
 */
class Fighter : public Class{
public:
    Fighter();
    void setDice(int);
    void setAttackBonus(int*);
    void setBaseAttackBonus(int*);
    void setAttackBonusRate(int);
	void setClassName(std::string name);
};

#endif // FIGHTER_H
