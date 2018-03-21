/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Header file for class Gromdrin. This class inherits from Character
* and has a few short responses. It has a special ability to give the player
* fire Arrows, but only if the player has the fire lizards skin.
*******************************************************************************/


#ifndef GROMDRIN_HPP
#define GROMDRIN_HPP

#include<string>
using std::string;


#include"Character.hpp"
#include"Player.hpp"

class Gromdrin : public Character
{
private:


public:
  Gromdrin();
  ~Gromdrin();

  virtual void interact(Player*);
  virtual void specialAction(Player*);
};
#endif
