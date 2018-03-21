/***********************************************************************************
* Author: Alex McEvoy
* Date: 02/10/18
* Description: Implementation file for BlueMen class. This class is inherited from Character
* and has the additional ability of Mob. It has a High defense depending in how many
* strength points it has. For every 4 strength points it loses, it loses a defense
* die roll.
************************************************************************************/


#include<string>
#include"BlueMen.hpp"
#include"Utilities.hpp"


/***********************************************************************
* Blue Men normal Constructor
***********************************************************************/


BlueMen::BlueMen(std::string nameIn)
    : Character(nameIn)
{
    type = "Blue Man";
    armor = MAX_ARMOR;
    strength = MAX_STRENGTH;
    dead = false;
}


/***********************************************************************
* Use this function to apply damage directly to Blue Men
***********************************************************************/

void BlueMen::doDamage(int damage)
{
    strength -= damage;

    if(strength < 1)
    {   dead = true;    }

}

/***********************************************************************
* Blue Men default attack function
***********************************************************************/

int BlueMen::attack()
{
    const int ATTACK_DIE = 10;
    const int NUM_DICE = 2;

    int attackRoll = diceRoll(ATTACK_DIE, NUM_DICE);

    return attackRoll;
}

/***********************************************************************
* Blue Men's defense function. Blue men Lose 1 defense die for every 4
* hit points they lose.
***********************************************************************/

int BlueMen::defense(int damage)
{
    const int DEFENSE_DIE = 6;
    int NUM_DICE;
    if ( strength > 8)
    {   NUM_DICE = 3;   }
    else if (strength > 4 )
    {   NUM_DICE = 2;   }
    else
    {   NUM_DICE = 1;   }

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

void BlueMen::recover()
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
* Blue Men's default deconstructor
***********************************************************************/

BlueMen::~BlueMen()
{
}
