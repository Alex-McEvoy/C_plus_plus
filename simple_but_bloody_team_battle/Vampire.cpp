/***********************************************************************************
* Author: Alex McEvoy
* Date: 02/10/18
* Description: Implementation file for Vampire class. This class is inherited from Character
* and has the additional ability of charm, where it gets a chance every turn to have
* a character not attack it.
************************************************************************************/

#include<string>
#include"Vampire.hpp"
#include"Utilities.hpp"


/***********************************************************************
* Normal Constructor
***********************************************************************/

Vampire::Vampire(std::string nameIn)
    : Character(nameIn)
{
    type = "Vampire";
    armor = MAX_ARMOR;
    strength = MAX_STRENGTH;
    dead = false;
}

/***********************************************************************
* Use this function to apply damage directly to Vampire character.
***********************************************************************/

void Vampire::doDamage(int damage)
{
    strength -= damage;

    if(strength < 1)
    {   dead = true;    }

}


/***********************************************************************
* Vampire default attack function
***********************************************************************/

int Vampire::attack()
{
    const int ATTACK_DIE = 12;
    const int NUM_DICE = 1;

    int attackRoll = diceRoll(ATTACK_DIE, NUM_DICE);

    return attackRoll;
}

/***********************************************************************
* Vampire's defense function, has a 50% chance of charming the opponent,
* which means they don't attack. This is performed by returning a large
* enough defense value to null and attack points dealt.
***********************************************************************/

int Vampire::defense(int damage)
{
    const int DEFENSE_DIE = 6;
    const int NUM_DICE = 1;
    const int CHARM_DIE = 2;

    int defenseRoll = diceRoll(DEFENSE_DIE, NUM_DICE);

    defenseRoll += armor;       // Add our armor to the defense roll

    int charm = diceRoll(CHARM_DIE, NUM_DICE);

    if(charm == 1)                      // If we roll a charm roll
    {   return 1000 + defenseRoll; }    // Return our high defense roll
    else                                // If we didn't charm
    {
        if (damage - defenseRoll <= 0)  // Check to see our damage isn't zero with just our defense roll
        {   damage = 0; }

        doDamage(damage);               // Do whatever damage got through defense
        return defenseRoll;             // return our defense roll
    }

}

/***********************************************************************
* Recovers a percentage of hit points lost. Calculates a percentage of
* maximum strength and adds that to current strength. If above max strength,
* character is fully healed but does not exceed MAX_STRENGTH
***********************************************************************/

void Vampire::recover()
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


Vampire::~Vampire()
{
}
