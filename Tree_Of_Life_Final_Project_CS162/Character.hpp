/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Header file for class Character. This class provides a virtual
* base class for all NPCs in the game that the player will be interacting with.
*******************************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include<string>
using std::string;

#include<vector>
using std::vector;

// For character responses. Makes it easier to call character responses
#include<map>
using std::map;

#include"Player.hpp"

class Character
{
protected:
  string name;

  // initial for when we first meet characters, later for after visited = true
  map<string, string> initialResponses;
  map<string, string> laterResponses;

  // options String gives the player their choices during interaction, the ints
  // are what they select
  vector<string> playerOptionsString;
  vector<int> playerOptionsInt;

  // These are for the combat based characters
  int armor,
      hitPoints;
  // Allows for interaction to change after first visit
  bool visited, dead;

public:
  Character();
  virtual ~Character();

  void wait();
  string getName()
  { return name;  }

  virtual void interact(Player*) = 0;
  // Special action allows characters to give player items
  virtual void specialAction(Player*) = 0;






};

#endif
