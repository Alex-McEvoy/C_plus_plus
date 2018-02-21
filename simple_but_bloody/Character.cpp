/***********************************************************************************
* Author: Alex McEvoy
* Date: 02/10/18
* Description: Implementation file for Character class. This class is the abstract class which
* provides the base class for classes Vampire, Barbarian, BlueMen, Medusa and HarryPotter.
* It contains member variables for armor and strength points, and virtual functions for
* attack and defense.
************************************************************************************/


#include<string>
#include"Character.hpp"


/***********************************************************************
* Normal Constructor for Character
***********************************************************************/

Character::Character(std::string nameIn)
{
    name = nameIn;
}


/***********************************************************************
* Default deconstructor
***********************************************************************/

Character::~Character()
{
}
