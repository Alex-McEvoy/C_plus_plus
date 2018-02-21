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
    armor = 3;
    strength = 8;
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

int Medusa::defense()
{
    const int DEFENSE_DIE = 6;
    const int NUM_DICE = 1;

    int defenseRoll = diceRoll(DEFENSE_DIE, NUM_DICE);

    defenseRoll += armor;       // Add our armor to the defense roll

    return defenseRoll;

}

/***********************************************************************
* Medusa's default deconstructor
***********************************************************************/

Medusa::~Medusa()
{
}
