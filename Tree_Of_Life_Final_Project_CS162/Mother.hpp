/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Header file for class Mother. This class inherits from Character
* and has a few short responses. It has a special ability to give the player
* a family jewel.
*******************************************************************************/

#ifndef MOTHER_HPP
#define MOTHER_HPP

#include<string>
using std::string;


#include"Character.hpp"
#include"Player.hpp"

class Mother : public Character
{
private:


public:
  Mother();
  ~Mother();

  virtual void interact(Player*);
  virtual void specialAction(Player*);
};
#endif
