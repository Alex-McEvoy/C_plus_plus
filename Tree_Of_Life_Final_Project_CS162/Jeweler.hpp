/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Header file for class Jeweler. This class is derived from Character
* and has the special ability to buy the players Pearl.
*******************************************************************************/


#ifndef JEWELER_HPP
#define JEWELER_HPP

#include<string>
using std::string;

#include"Character.hpp"
#include"Player.hpp"

class Jeweler : public Character
{
private:

public:
  Jeweler();
  ~Jeweler();

  virtual void interact(Player*);
  virtual void specialAction(Player*);

};

#endif
