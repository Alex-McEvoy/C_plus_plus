/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Header file for class homeWorld. This derived World object contains
* two characters, Mother and Aisha.
*******************************************************************************/

#ifndef HOMEWORLD_HPP
#define HOMEWORLD_HPP

#include<string>
using std::string;
#include"World.hpp"

class homeWorld : public World
{
protected:

public:
  homeWorld();
  ~homeWorld();

};
#endif
