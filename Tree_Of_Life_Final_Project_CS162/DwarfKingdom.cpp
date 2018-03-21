/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Implementation file for class dwarfKingdom. This derived World
* object contains one Character of class gromdrin.
*******************************************************************************/

#include<string>
using std::string;

#include"DwarfKingdom.hpp"
#include"Gromdrin.hpp"



/***********************************************************************
* Default Constructor for class dwarfKingdom. Instantiates Gromdrin
***********************************************************************/

DwarfKingdom::DwarfKingdom()
{
  Gromdrin * gromdrin = new Gromdrin();

  characters.push_back(gromdrin);

  worldName = "Dwarf Kingdom";
  description = "The Dwarf Kingdom is an ancient mountain stringhold, where \n"
                "giant statues hewn into the towering rocks portend of powerful\n"
                "empires built on ingenuity and skill. These people are great \n"
                "craftsman and builders. After much exploration you find yourself \n"
                " back at the home of an inviting shop owned by Gromdrin, a  \n"
                " great weaponsmith. You would be wise to seek his help";


}

DwarfKingdom::~DwarfKingdom()
{
  for (int i = 0; i < characters.size(); i++) {
    if (characters.at(i) != nullptr)
    { delete characters.at(i);  }
  }
}
