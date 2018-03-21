/***********************************************************************************
* Author: Alex McEvoy
* Date: 03/01/18
* Description: Header file for Queue class, which creates a container with queue like
* behavior and using Node classes as its elements. These nodes contain a pointer to the
* next element and a pointer to type Character. The linked list will be implemented
* in a circularly linked list structure.
************************************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include<string>
#include"Node.hpp"
using std::string;

class Queue
{
private:
    Node * head;


public:
    Queue();
   bool isEmpty();
   Node * removeFront();
   void addBack(playerType, string);
   void loserPile(Node *);
   Character * getFront();
   void moveToBack();
   void printQueue();
   ~Queue();
};


#endif
