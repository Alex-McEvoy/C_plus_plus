/************************************************************************
 * *Program Name: Predator-Prey Game, Critter class implementation file
 * *Author: Group 44
 * *Date: 2/12/18
 * *Description: Critter is the base class for Ant and Doodlebug.
 * *The member variable "type" designates each Critter as an Ant or
 * *Doodlebug (Ant = 1, Dooblebug = 2). The member variable "age" tracks
 * *each Critter's age used to determine breeding potential.
 * *********************************************************************/

#include "Critter.hpp"

Critter::Critter()
{
}

int Critter::getType()
{
   return type;
}

int Critter::getAge()
{
   return age;
}

bool Critter::hasMoved()
{
    return moved;
}

void Critter::setMoved(bool moveIn)
{
    moved = moveIn;
}

Critter::~Critter()
{
}
