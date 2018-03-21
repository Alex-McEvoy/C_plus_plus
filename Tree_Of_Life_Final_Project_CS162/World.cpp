/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Implementation file for class World. This is the base class from which
* other worlds are derived. This class contains objects of type
* Character for the player to interact with. The role of worlds is basically to
* create and contain Characters and pointers to other worlds. All interaction
* is done through the characters and their special abilities. This class returns
* the vector of Characters for treeOfLife to handle the interactions.
*******************************************************************************/

#include<vector>
using std::vector;

#include "World.hpp"


/***********************************************************************
* Default Constructor for class World
***********************************************************************/

World::World()
{
  north = NULL;
  south = NULL;
  east = NULL;
  west = NULL;
}

/***********************************************************************
* Returns the linked worlds for any particular world. It does this by
* removing all pointers that are nullptr from its linkedWorlds vector
***********************************************************************/

vector<World*> World::getLinkedWorlds()
{
  vector<World*> possibleWorlds {north,south,east,west};

  for (int i = 0; i < possibleWorlds.size(); i++) {
    if(possibleWorlds.at(i) == NULL)
    { possibleWorlds.erase(possibleWorlds.begin() + i); }
  }
  // This redundant check seemed necessary since one 0x0 always seemed to sneak
  // through the first check and cause problems
  for (int i = 0; i < possibleWorlds.size(); i++) {
    if (possibleWorlds.at(i) == 0x0)
    { possibleWorlds.erase(possibleWorlds.begin() + i); }
  }

  return possibleWorlds;
}
