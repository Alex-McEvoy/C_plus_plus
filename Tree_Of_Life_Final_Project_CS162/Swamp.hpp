/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Header file for class Swamp. This derived World object contains
* one Character, Dreadwind.
*******************************************************************************/

#ifndef SWAMP_HPP
#define SWAMP_HPP

#include<string>
using std::string;

#include"World.hpp"

class Swamp: public World
{
protected:

public:
  Swamp();
  ~Swamp();

};
#endif
