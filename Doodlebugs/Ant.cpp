/*********************************************************************
 ** File name: Ant.cpp
 ** Author: Group 44
 ** Date: 2/12/18
 ** Description: The Ant class is used within Board class
 ** objects. The Ant class is a child class of the Critter class,
 ** and inherits public variables from the Critter class.
 *********************************************************************/

#include "Ant.hpp"

// Default Constructor
Ant::Ant()
{
	// Label Ant object as Ant type
	type = 1;

	// Ant has not moved yet
	moved = false;

	// Start age at 0
	age = 0;
}

/*********************************************************************
 ** move: Function increments age of Ant object and is used within the
 ** board class to test for breeding ability (Age 3)
 *********************************************************************/
void Ant::move(bool eat)
{
	age++;
	moved = true;
}

bool Ant::starve()
{
	return true;
}


/*********************************************************************
 ** breed: Function represents the end of an ant breeding cylce, and
 ** therefore a reset of age (Back to 0)
 *********************************************************************/
void Ant::breed()
{
	age = 0;
}

// Deconstructor
Ant::~Ant()
{

}
