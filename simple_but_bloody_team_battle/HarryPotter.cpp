/***********************************************************************************
* Author: Alex McEvoy
* Date: 02/10/18
* Description: Implementation file for HarryPotter class. This class is inherited from Character
* and has the additional ability of Hogwarts, where he gets one time to die, before being
* brought back to life with 20 hit points instead of his original 10.
************************************************************************************/

#include<iostream>
#include<string>
#include"HarryPotter.hpp"
#include"Utilities.hpp"

/***********************************************************************
* Normal Constructor
***********************************************************************/

HarryPotter::HarryPotter(std::string nameIn)
    : Character(nameIn)
{
    type = "Harry Potter";
    armor = MAX_ARMOR;
    strength = MAX_STRENGTH;
    dead = false;
    Hogwarts = false;
}

/***********************************************************************
* Use this function to apply damage directly to Harry Potter character. If
* Harry Potter has not used his Hogwarts ability yet, raise him from the
* dead if he is killed.
***********************************************************************/

void HarryPotter::doDamage(int damage)
{
    strength -= damage;

    if(strength < 1 && Hogwarts == false)   // If we haven't used Hogwarts yet
    {
        strength = 20;                      // Resurrect Potter and set Hogwarts to true
        Hogwarts = true;
        std::cout << "Harry Potter is Killed and Rises from the Dead!!" << std::endl;
    }
    else if ( strength < 1 && Hogwarts == true) // If we've already used Hogwarts
    {   dead = true;    }                       // Kill HARRY POTTER!!!

}

/***********************************************************************
* Harry Potter default attack function
***********************************************************************/

int HarryPotter::attack()
{
    const int ATTACK_DIE = 6;
    const int NUM_DICE = 2;

    int attackRoll = diceRoll(ATTACK_DIE, NUM_DICE);

    return attackRoll;
}

/***********************************************************************
* Harry Potter's defense function
***********************************************************************/

int HarryPotter::defense(int damage)
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

void HarryPotter::recover()
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
* Harry Potter's default deconstructor
***********************************************************************/

HarryPotter::~HarryPotter()
{
}
