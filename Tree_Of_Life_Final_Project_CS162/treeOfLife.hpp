/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Implementation file for class treeOfLife. This class creates all
* objects of type World and the Player object. It then controls the interactions
* between the player and the World objects until the Player either wins or loses.
* It does this by calling playGame, which will get all possible player options
* from World and Player.
*******************************************************************************/

#ifndef TREEOFLIFE_HPP
#define TREEOFLIFE_HPP

#include<iostream>
using std::cout;
using std::endl;

#include<vector>
using std::vector;

#include<string>
using std::string;

#include<fstream>
using std::ifstream;

#include"Player.hpp"
#include"Item.hpp"
#include"Character.hpp"
#include"World.hpp"
#include"homeWorld.hpp"
#include"Utilities.hpp"
#include"DwarfKingdom.hpp"
#include"FireWorld.hpp"
#include"Metropolis.hpp"
#include"Jungle.hpp"
#include"Swamp.hpp"

// Use this for return value of enterWorld, which lets playGame know it needs to
// travel, and to which world.
enum WhichWorld {HOME, DWARF, FIRE, METRO, JUNGLE, SWAMP, QUIT};

class treeOfLife
{
private:
  Player * currentPlayer;
  World * currentWorld;

  homeWorld home_world;
  DwarfKingdom dwarf_kingdom;
  FireWorld fire_world;
  Metropolis metropolis;
  Jungle jungle;
  Swamp swamp;

  int gameOver();   // Returns 1 if won, 2 if dead, 3 if out of time.
  void wait();
  string outputMap (string); // reads ascii files and outputs their contents

public:
  treeOfLife();
  WhichWorld enterWorld(World *, Player *);
  ~treeOfLife();

  void playGame();


};


#endif
