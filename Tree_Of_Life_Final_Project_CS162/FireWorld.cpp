/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Implementation file for class fireWorld. This derived World object contains
* one Character, fireBasilisk.
*******************************************************************************/

#include<string>
using std::string;

#include"FireWorld.hpp"
#include"Basilisk.hpp"


/***********************************************************************
* Default Constructor for class FireWorld. Creates a new basilisk character
***********************************************************************/

FireWorld::FireWorld()
{
  Basilisk* basilisk = new Basilisk();

  characters.push_back(basilisk);

  worldName = "Fire World";
  description = "The Fire World is a cruel place, devoid of any life except for \n"
                "deadly Fire basilisks and sparse vegetation. You see dozens of \n"
                " the fire basilisks but one begins to approach you.";


}

FireWorld::~FireWorld()
{
  for (int i = 0; i < characters.size(); i++) {
    if (characters.at(i) != nullptr)
    { delete characters.at(i);  }
  }
}
