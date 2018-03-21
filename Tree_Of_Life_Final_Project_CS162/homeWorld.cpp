/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Implementation file for class homeWorld. This derived World object contains
* two characters, Mother and Aisha.
*******************************************************************************/

#include<string>
using std::string;

#include"homeWorld.hpp"
#include"Mother.hpp"
#include"Sister.hpp"


/***********************************************************************
* Default Constructor for class homeWorld. Calls World's default constructor
* to set name.
***********************************************************************/

homeWorld::homeWorld()
{
  Mother * mother = new Mother();
  Sister * sister = new Sister();
  characters.push_back(mother);
  characters.push_back(sister);

  worldName = "Home World";
  description = "Your homeworld is a peaceful place, with vast green fields \n"
                "where thousands of elk roam freely. It is upon these creatures \n"
                "that your village depends. You find yourself back in your home \n"
                "with your Mother and sister.";

}

homeWorld::~homeWorld()
{
  for (int i = 0; i < characters.size(); i++) {
    if (characters.at(i) != nullptr)
    { delete characters.at(i);  }
  }
}
