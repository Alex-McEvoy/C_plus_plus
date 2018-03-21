/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Header file for class Jungle. This derived World object contains
* one Character, ElfRanger.
*******************************************************************************/

#ifndef JUNGLE_HPP
#define JUNGLE_HPP

#include<string>
using std::string;

#include"World.hpp"

class Jungle : public World
{
protected:

public:
  Jungle();
  ~Jungle();

};
#endif
