/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Header file for class Innkeeper. This class is derived from Character
* and has the special ability to let the player rest and regenerate hit points
* in exchange for 5 gold.
*******************************************************************************/


#ifndef INNKEEPER_HPP
#define INNKEEPER_HPP

#include<string>
using std::string;

#include"Character.hpp"
#include"Player.hpp"

class Innkeeper : public Character
{
private:

public:
  Innkeeper();
  ~Innkeeper();

  virtual void interact(Player*);
  virtual void specialAction(Player*);

};

#endif
