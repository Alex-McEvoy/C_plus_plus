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



Vampire::Vampire(std::string nameIn)
    : Character(nameIn)
{
    type = "Vampire";
    armor = 1;
    strength = 18;
    dead = false;
}


void Vampire::doDamage(int damage)
{
    strength -= damage;

    if(strength < 1)
    {   dead = true;    }

}


int Vampire::attack()
{
    const int ATTACK_DIE = 12;
    const int NUM_DICE = 1;

    int attackRoll = diceRoll(ATTACK_DIE, NUM_DICE);

    return attackRoll;
}

int Vampire::defense()
{
    const int DEFENSE_DIE = 6;
    const int NUM_DICE = 1;
    const int CHARM_DIE = 2;

    int defenseRoll = diceRoll(DEFENSE_DIE, NUM_DICE);

    defenseRoll += armor;       // Add our armor to the defense roll

    int charm = diceRoll(CHARM_DIE, NUM_DICE);

    if(charm == 1)
    {   return 1000 + defenseRoll; }
    else
    {   return defenseRoll; }

}
Vampire::~Vampire()
{
}
