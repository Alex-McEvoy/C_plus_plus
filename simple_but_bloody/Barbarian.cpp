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
    armor = 0;
    strength = 12;
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

int Barbarian::defense()
{
    const int DEFENSE_DIE = 6;
    const int NUM_DICE = 2;

    int defenseRoll = diceRoll(DEFENSE_DIE, NUM_DICE);

    defenseRoll += armor;       // Add our armor to the defense roll

    return defenseRoll;

}

/***********************************************************************
* Barbarian's default deconstructor
***********************************************************************/

Barbarian::~Barbarian()
{
}
