/***********************************************************************************
* Author: Alex McEvoy
* Date: 03/01/18
* Description: Header file for Node class, which contains a pointer to the next node,
* and a pointer to type Character. This class is used in a Queue class and further more
* in class Combat.
************************************************************************************/

#ifndef NODE_HPP
#define NODE_HPP

#include<string>
#include"Character.hpp"
#include"Vampire.hpp"
#include"Barbarian.hpp"
#include"BlueMen.hpp"
#include"Medusa.hpp"
#include"HarryPotter.hpp"

enum playerType {vampire, medusa, bluemen, barbarian, harrypotter};

class Node
{
friend class Queue;
private:
    Character * player;
    Node * next;

public:
    Node(playerType, std::string, Node*);
    Character * getPlayer();
    ~Node();
};

#endif
