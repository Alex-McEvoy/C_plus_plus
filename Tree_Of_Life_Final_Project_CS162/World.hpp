/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Header file for class World. This is the base class from which
* other worlds are derived. This class contains objects of type
* Character for the player to interact with. The role of worlds is basically to
* create and contain Characters and pointers to other worlds. All interaction
* is done through the characters and their special abilities. This class returns
* the vector of Characters for treeOfLife to handle the interactions.
*******************************************************************************/


#ifndef   WORLD_HPP
#define WORLD_HPP

#include<string>
using std::string;

#include<vector>
using std::vector;

#include"Player.hpp"
#include"Character.hpp"


class World
{
protected:
  World * north;
  World * south;
  World * east;
  World * west;

  vector<Character*> characters;
  string worldName;
  string description;


public:
  World();
  virtual ~World() {};
  // Getters
  vector<Character*> getCharacters()
  { return characters;  }

  World * getNorth()
  { return north; }
  World * getEast()
  { return east;  }
  World * getSouth()
  { return south; }
  World * getWest()
  { return west;  }

  string getWorldName()
  { return worldName; }
  string getDescription()
  { return description; }

  vector<World*> getLinkedWorlds(); // Check to see where we can travel to from here

  // Setters
  void setNorth(World * northIn)
  { north = northIn;  }
  void setSouth(World * southIn)
  { south = southIn;  }
  void setEast(World * eastIn)
  { east = eastIn;  }
  void setWest(World * westIn)
  { west = westIn;  }




};


#endif
