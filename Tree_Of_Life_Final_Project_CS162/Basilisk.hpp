/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Header file for class Basilisk. This class is inherited from class
* character and has two additional member functions attack() and defense() for
* combat with the player. This takes the place of interact
*******************************************************************************/

#ifndef BASILISK_HPP
#define BASILISK_HPP

#include<string>
using std::string;

#include"Character.hpp"
#include"Player.hpp"

class Basilisk : public Character
{
private:
  bool combat(Player*);    // returns true of won, false if lost
  int attack();
  int defend();
public:
  Basilisk();
  ~Basilisk();

  virtual void interact(Player*);
  virtual void specialAction(Player*);

};

#endif
