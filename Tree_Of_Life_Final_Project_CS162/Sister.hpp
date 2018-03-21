/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Header file for class Sister. This class inherits from Character
* and has a few short responses. It has no special ability
*******************************************************************************/


#ifndef SISTER_HPP
#define SISTER_HPP

#include<string>
using std::string;


#include"Character.hpp"
#include"Player.hpp"

class Sister : public Character
{
private:


public:
  Sister();
  ~Sister();

  virtual void interact(Player*);
  virtual void specialAction(Player*);
};
#endif
