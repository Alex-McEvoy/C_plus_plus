/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Header file for class Item. This class represents the base class
* for all other items the player will receive and interact with. Some have
* special abilities to alter the players stats, others are needed to further
* the story.
*******************************************************************************/


#ifndef ITEM_HPP
#define ITEM_HPP

#include<string>
using std::string;

class Item
{
protected:
    int ID;
    string name, description;

public:
    Item();
    Item(int, string, string);
    virtual ~Item();

    int getID()
    { return ID;  }
    string getName()
    { return name;  }
    string getDescription()
    { return description; }



};

#endif
