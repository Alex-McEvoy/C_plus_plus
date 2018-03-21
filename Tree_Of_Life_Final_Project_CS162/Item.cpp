/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Implementation file for class Item. This class represents the base class
* for all other items the player will receive and interact with. Some have
* special abilities to alter the players stats, others are needed to further
* the story.
*******************************************************************************/

#include<string>
using std::string;

#include"Item.hpp"


/***********************************************************************
* Default Constructor for class Item
***********************************************************************/

Item::Item()
{
}

/***********************************************************************
* Normal Constructor for class Item. Current design requires an item
* number for Player.addItem(), a string name, and description
***********************************************************************/

Item::Item(int IdentifyNumber, string nameIn, string descriptionIn)
{
  ID = IdentifyNumber;
  name = nameIn;
  description = descriptionIn;
}

/***********************************************************************
* Default Deconstructor for class Item
***********************************************************************/

Item::~Item()
{
}
