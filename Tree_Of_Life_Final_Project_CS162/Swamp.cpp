/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Implementation file for class Swamp. This derived World object
* contains one Character, Dreadwind.
*******************************************************************************/

#include<string>
using std::string;

#include"Swamp.hpp"
#include"Dreadwind.hpp"


/***********************************************************************
* Default Constructor for class Swamp. Creates a new Dreadwind character
***********************************************************************/

Swamp::Swamp()
{
  Dreadwind* dreadwind = new Dreadwind();

  characters.push_back(dreadwind);

  worldName = "Swamps of Mon";
  description = "The Swamps of Mon are a stinking, dangerous place, with poison \n"
                "snakes and large bats flying overhead. A mist engulfs the trees\n"
                "though through the dense fog you catch glimpses of a hulking, \n"
                "many armed beast making it's way through the muck. It's the \n"
                "Dreadwind. Be careful and do not attack unless you are ready";


}

Swamp::~Swamp()
{
  for (int i = 0; i < characters.size(); i++) {
    if (characters.at(i) != nullptr)
    { delete characters.at(i);  }
  }
}
