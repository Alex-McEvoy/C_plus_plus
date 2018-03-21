/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Header file for class Metropolis. This derived World object contains
* two characters, Innkeeper and jeweler.
*******************************************************************************/

#ifndef METROPOLIS_HPP
#define METROPOLIS_HPP

#include<string>
using std::string;

#include"World.hpp"

class Metropolis : public World
{
protected:

public:
  Metropolis();
  ~Metropolis();

};
#endif
