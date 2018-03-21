/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Header file for class FireWorld. This derived World object contains
* one Character, fireBasilisk.
*******************************************************************************/

#ifndef FIREWORLD_HPP
#define FIREWORLD_HPP

#include<string>
using std::string;

#include"World.hpp"

class FireWorld : public World
{
protected:

public:
  FireWorld();
  ~FireWorld();

};
#endif
