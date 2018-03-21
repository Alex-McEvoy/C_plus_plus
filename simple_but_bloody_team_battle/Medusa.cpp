/***********************************************************************************
* Author: Alex McEvoy
* Date: 02/10/18
* Description: Implementation file for Medusa class. This class is inherited from Character
* and has the additional ability of Gaze, where if it rolls a 12 on attack, the defender
* is instantly killed (unless a vampire charms her into not attacking).
************************************************************************************/

#include<string>
#include"Medusa.hpp"
#include"Utilities.hpp"

/***********************************************************************
* Normal Constructor
***********************************************************************/

Medusa::Medusa(std::string nameIn)
    : Character(nameIn)
{
    type = "Medusa";
    armor = MAX_ARMOR;
    strength = MAX_STRENGTH;
    dead = false;
}

/***********************************************************************
* Use this function to apply damage directly to Medusa character.
***********************************************************************/

void Medusa::doDamage(int damage)
{
    strength -= damage;

    if(strength < 1)
    {   dead = true;    }

}

/***********************************************************************
* Medusa's attack function returns a very large number if she rolls a 12,
* this is to represent her Glare attack, which turns enemies to stone instantly
***********************************************************************/

int Medusa::attack()
{
    const int ATTACK_DIE = 6;
    const int NUM_DICE = 2;

    int attackRoll = diceRoll(ATTACK_DIE, NUM_DICE);

    if (attackRoll == 12)
    {   return 1000;    }
    else
    {   return attackRoll;  }
}

/***********************************************************************
* Medusa's defense function
***********************************************************************/

int Medusa::defense(int damage)
{
    const int DEFENSE_DIE = 6;
    const int NUM_DICE = 1;

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

void Medusa::recover()
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
* Medusa's default deconstructor
***********************************************************************/

Medusa::~Medusa()
{
}
