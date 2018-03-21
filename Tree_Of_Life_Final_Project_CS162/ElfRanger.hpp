/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Header file for class ElfRanger. This class is derived from Character
* and has the special ability to give the Player a special tree branch
*******************************************************************************/


#ifndef ELFRANGER_HPP
#define ELFRANGER_HPP

#include<string>
using std::string;

#include"Character.hpp"
#include"Player.hpp"

class ElfRanger : public Character
{
private:

public:
  ElfRanger();
  ~ElfRanger();

  virtual void interact(Player*);
  virtual void specialAction(Player*);

};

#endif
