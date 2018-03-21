/***********************************************************************************
* Author: Alex McEvoy
* Date: 03/01/18
* Description: Implementation file for Node class, which contains a pointer to the next node,
* and a pointer to type Character. This class is used in a Queue class and further more
* in class Combat.
************************************************************************************/


#include"Node.hpp"

/***********************************************************************
* Normal constructor for class Node. Takes in an enum of character type, a
* string for the characters name, and a pointer to Node for the next item
* in the linked list.
***********************************************************************/

Node::Node(playerType type, std::string name, Node* nextPtr)
{
    if(type == vampire)
    {   player = new Vampire(name); }
    else if(type == medusa)
    {   player = new Medusa(name);  }
    else if(type == bluemen)
    {   player = new BlueMen(name);  }
    else if(type == barbarian)
    {   player = new Barbarian(name);  }
    else if(type == harrypotter)
    {   player = new HarryPotter(name);  }

    next = nextPtr;
}


/***********************************************************************
* Returns a pointer to a Character type object stored in the Node.
***********************************************************************/

Character * Node::getPlayer()
{
    return player;
}


/***********************************************************************
* Default deconstructor for Node class. Delete's the object of type
* Character it holds and sets pointer value to nullptr.
***********************************************************************/

Node::~Node()
{
    delete player;
//    player = nullptr;
//    next = nullptr;
}
