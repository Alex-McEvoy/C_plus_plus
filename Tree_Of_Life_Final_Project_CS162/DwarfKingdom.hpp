/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Header file for class dwarfKingdom. This derived World
* object contains one Character of class gromdrin.
*******************************************************************************/

#ifndef DWARFKINGDOM_HPP
#define DWARFKINGDOM_HPP

#include<string>
using std::string;

#include"World.hpp"

class DwarfKingdom : public World
{
protected:

public:
  DwarfKingdom();
  ~DwarfKingdom();

};
#endif
