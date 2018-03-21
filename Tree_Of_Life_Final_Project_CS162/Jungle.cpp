/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Header file for class Jungle. This derived World object contains
* one Character, ElfRanger.
*******************************************************************************/

#include<string>
using std::string;

#include"Jungle.hpp"
#include"ElfRanger.hpp"


/***********************************************************************
* Default Constructor for class Jungle. Creates a new ElfRanger character
***********************************************************************/

Jungle::Jungle()
{
  ElfRanger * elfRanger = new ElfRanger();

  characters.push_back(elfRanger);

  worldName = "Jungles of Elra";
  description = "The Jungles of Elra is a densely vegetated planet with trees \n"
                "growing up as high as the eye can see. The elves call this world \n"
                "home, and have built magnificent cities in the treetops. You \n"
                "find yourself standing beside a hardened elven ranger.";


}

Jungle::~Jungle()
{
  for (int i = 0; i < characters.size(); i++) {
    if (characters.at(i) != nullptr)
    { delete characters.at(i);  }
  }
}
