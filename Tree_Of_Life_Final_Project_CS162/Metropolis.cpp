/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Implementation file for class Metropolis. This derived World object contains
* two characters, Innkeeper and jeweler.
*******************************************************************************/


#include<string>
using std::string;

#include"Metropolis.hpp"
#include"Jeweler.hpp"
#include"Innkeeper.hpp"


/***********************************************************************
* Default Constructor for class Metropolis. Creates a new Jeweler and
* Innkeeper Characters
***********************************************************************/

Metropolis::Metropolis()
{
  Jeweler* jeweler = new Jeweler();
  Innkeeper* innkeeper = new Innkeeper();

  characters.push_back(jeweler);
  characters.push_back(innkeeper);

  worldName = "Metropolis";
  description = "Metropolis is a bustling city, with densely populated urban\n"
                "sprawl dpreading for miles in all directions. You find yourself \n"
                "standing next to a small Jewelers Boutique and an Inn.";


}

Metropolis::~Metropolis()
{
  for (int i = 0; i < characters.size(); i++) {
    if (characters.at(i) != nullptr)
    { delete characters.at(i);  }
  }
}
