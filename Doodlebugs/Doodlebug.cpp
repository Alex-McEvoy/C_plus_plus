/*********************************************************************
 ** File name: Doodlebug.cpp
 ** Author: Group 44
 ** Date: 02/12/18
 ** Description: The Doodlebug class is used within Board class objects.
 ** The Doodlebug class is a child class of the Critter class, and
 ** inherits public variables from the Critter class.
 *********************************************************************/

#include "Doodlebug.hpp"

Doodlebug::Doodlebug()
{
    type = 2;               // Label Doodlebug type
    age = 0;                // Start age at 0
    starveNum = 0;
    moved = false;          // Doodlebug has not moved yet
}


/******************************************************************
 ** Tries to find adjacent cell with ant to eat and move into.
 ** Checks North & clockwise. If no ants, move like an ant & starve
 *****************************************************************/
void Doodlebug::move(bool eat)
{
    if (eat)
    {
        starveNum = 0;
        age++;
        moved = true;
    }
    else
    {
        age++;
        starveNum++;
        moved = true;
    }

}

/******************************************************************
 ** Every 8th day a Doodlebug will make a new one. This checks
 ** for every instance of 8. Returns true to board
 *****************************************************************/
void Doodlebug::breed()
{
    age = 0;
}

/******************************************************************
 ** Checks if Doodlebug is to die from starvation. Returns true
 ** to board and false otherwise
 *****************************************************************/
bool Doodlebug::starve()
{
    if (starveNum >= 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Doodlebug::~Doodlebug()
{

}
