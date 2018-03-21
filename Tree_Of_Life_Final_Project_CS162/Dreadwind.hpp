/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Header file for class Dreadwind. This class is inherited from class
* character and has three additional member functions attack() defense() and
* combat() so it can battle with Player. This takes the place of interact.
* The Dreadwind gives up it's poison tooth when defeated.
*******************************************************************************/

#ifndef DREADWIND_HPP
#define DREADWIND_HPP

#include<string>
using std::string;

#include"Character.hpp"
#include"Player.hpp"

class Dreadwind : public Character
{
private:
  bool combat(Player*);    // returns true of won, false if lost
  int attack();
  int defend();
public:
  Dreadwind();
  ~Dreadwind();

  virtual void interact(Player*);
  virtual void specialAction(Player*);

};

#endif
