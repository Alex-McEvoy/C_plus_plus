/***********************************************************************************
* Author: Alex McEvoy
* Date: 02/10/18
* Description: Implementation file for Barbarian class. This class is inherited from Character
* and has no special abilities.
************************************************************************************/


#include<string>
#include"Barbarian.hpp"
#include"Utilities.hpp"

/***********************************************************************
* Barbarian normal Constructor
***********************************************************************/

Barbarian::Barbarian(std::string nameIn)
    : Character(nameIn)
{
    type = "Barbarian";
    armor = MAX_ARMOR;
    strength = MAX_STRENGTH;
    dead = false;
}

/***********************************************************************
* Use this function to apply damage directly to Barbarians
***********************************************************************/

void Barbarian::doDamage(int damage)
{
    strength -= damage;

    if(strength < 1)
    {   dead = true;    }
}

/***********************************************************************
* Barbarian default attack function
***********************************************************************/

int Barbarian::attack()
{
    const int ATTACK_DIE = 6;
    const int NUM_DICE = 2;

    int attackRoll = diceRoll(ATTACK_DIE, NUM_DICE);

    return attackRoll;
}

/***********************************************************************
* Barbarian defense function
***********************************************************************/

int Barbarian::defense(int damage)
{
    const int DEFENSE_DIE = 6;
    const int NUM_DICE = 2;

    int defenseRoll = diceRoll(DEFENSE_DIE, NUM_DICE);

    defenseRoll += armor;       // Add our armor to the defense roll

    if (damage - defenseRoll <= 0)
    {   damage = 0; }

    doDamage(damage);

    return defenseRoll;

}

/***********************************************************************
* Recovers a percentage of hit points lost. Calculates a percentage of
* maximum strength and adds that to current strength. If above max strength,
* character is fully healed but does not exceed MAX_STRENGTH
***********************************************************************/

void Barbarian::recover()
{
    const int DICE_SIDES = 10;
    const int NUM_DICE = 1;
    double multiplier = diceRoll(DICE_SIDES, NUM_DICE);

    int hitPoints = MAX_STRENGTH * (multiplier / 100);  // adds a random percentage of MAX_STRENGTH

    if(strength += hitPoints > MAX_STRENGTH)
    {   strength = MAX_STRENGTH;    }
    else
    {   strength += hitPoints;  }

}


/***********************************************************************
* Barbarian's default deconstructor
***********************************************************************/

Barbarian::~Barbarian()
{
}
