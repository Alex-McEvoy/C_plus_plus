/***********************************************************************************
* Author: Alex McEvoy
* Date: 03/01/18
* Description: Implementation file for Queue class, which creates a container with queue like
* behavior and using Node classes as its elements. These nodes contain a pointer to the
* next element and a pointer to type Character. The linked list will be implemented
* in a circularly linked list structure.
************************************************************************************/

#include<iostream>
#include<string>
#include"Queue.hpp"
using std::cout;
using std::endl;
using std::string;

/***********************************************************************
* Constructor for Queue. Sets head to nullptr
***********************************************************************/

Queue::Queue()
{
    head = nullptr;
}

/***********************************************************************
* Checks to see if the queue is empty by checking head, which should point
* to an address if there is an item. If no address, the list is empty
***********************************************************************/

bool Queue::isEmpty()
{
    if (head == nullptr)
    {   return true;    }
    else
    {   return false;   }
}

/***********************************************************************
* Adds a Node item to the back of our linked list. First checks to
* see if there are no nodes, then check for only one node and handle the
* situations accordingly. For all other situations, add a new node to the
* back of the list by allocating an item at the end of the list. This version
* creates new Nodes using Character descriptions. It is for when we are
* initially populating the team lists.
***********************************************************************/

void Queue::addBack(playerType type, string name)
{
    if (isEmpty())                                                  // If there are no items in the list
    {
        head = new Node(type, name, head);                          // create the first Node, next is currently nullptr
        head->next = head;                                          // Set the next pointer to itself (circularly linked list)
    }
    else if (head->next == head)                                    // Check to see if only one Node
    {
        head->next = new Node(type, name, head);                    // Create new Node that points with next to head
    }
    else                                                            // For all other list sizes
    {
        Node * tail = head;                                         // Set a temp tail node to set the last elements next pointer to the new Node

        while (tail->next != head)                                  // Position tail at the end of the list
        {   tail = tail->next;  }
        tail->next = new Node(type, name, head);                    // Create a new node at the end of the list

    }
}

/***********************************************************************
* Adds a Node item to the top (front) of our loser pile. First checks to
* see if there are no nodes, then check for only one node and handle the
* situations accordingly. For all other situations, add a new node to the
* back of the list by allocating an item at the front of the list. This version
* uses an existing Node object to add to the front of a list.
***********************************************************************/

void Queue::loserPile(Node * nodeIn)
{
    if (isEmpty())                                                  // If there are no items in the list
    {
        head = nodeIn;                                              // Set our head to the incoming Node
        head->next = head;                                          // Set the next pointer to itself (circularly linked list)
    }
    else if (head->next == head)                                    // Check to see if only one Node
    {
        nodeIn->next = head;                                        // Set our new head's next pointer to the current head
        head->next = nodeIn;                                        // Set our one Node's next to the new Node (circularly linked)

        head = nodeIn;                                              // Set our new head to nodeIn
    }
    else                                                            // For all other list sizes
    {
        Node * tail = head;                                         // Set a temp tail node to set the last elements next pointer to the new Node

        while (tail->next != head)                                  // Position tail at the end of the list
        {   tail = tail->next;  }
        tail->next = nodeIn;                                        // Set our last Node's next equal to nodeIn

        nodeIn->next = head;                                        // Set our new head's next pointer to the current head

        head = nodeIn;                                              // reset current head

    }
}

/***********************************************************************
* Remove the first element in the Queue from that queue, since we don't
* want to delete any Nodes while game is running, we just return the
* pointer to that Node to be transferred to the loser pile.
***********************************************************************/

Node * Queue::removeFront()
{
    if (isEmpty())
    {
        cout << "No Nodes in Queue!" << endl;
        return nullptr;
    }
    else if (head->next == head)             // Check to see if only one Node
    {
        Node * ejectNode = head;
        head = nullptr;
        ejectNode->next = nullptr;          // Break ejectNode out of the list completely
        return ejectNode;

    }
    else if (head->next->next == head)      // Check to see if there are 2 Nodes
    {
        Node * ejectNode = head;

        head = head->next;
        head->next = head;                  // Now there's only one node, set next pointer to itself

        ejectNode->next = nullptr;          // Break ejectNode out of the list completely
        return ejectNode;
    }
    else                                    // We've got more than 2 nodes
    {
        Node * ejectNode = head;            // Set our Node to be ejected
        Node * tail = head;                 // Set a temp tail node to set the last elements next pointer to the new head

        while (tail->next != head)          // Position tail at the end of the list
        {   tail = tail->next;  }
        tail->next = head->next;            // Set the last positions next to the new head

        head = head->next;

        ejectNode->next = nullptr;          // Break ejectNode out of the list completely
        return ejectNode;

    }

}

/***********************************************************************
* Prints the Character info for all characters in the Queue
***********************************************************************/

void Queue::printQueue()
{
    if (isEmpty())
    { cout << "No Nodes in List!" << endl;  }
    else
    {
        Node * temp = head;
        cout << temp->player->getType() << " " << temp->player->getName() << endl;
        cout << "Strength: " << temp->player->getStrength() << "\n" << endl;
        temp = head->next;
        while (temp != head)
        {
            cout << temp->player->getType() << " " << temp->player->getName() << endl;
            cout << "Strength: " << temp->player->getStrength() << "\n" << endl;
            temp = temp->next;
        }
    }
}

/***********************************************************************
* Returns the pointer to Character located at the front of the Queue
***********************************************************************/

Character * Queue::getFront()
{
    if (isEmpty())
    {
        cout << "No Character in Queue" << endl;
        return nullptr;
    }
    else
    {
        return head->getPlayer();
    }
}

/***********************************************************************
* Moves the winner of each round to the back of the circularly linked
* container by moving the head one item back.
***********************************************************************/

void Queue::moveToBack()
{
    head = head->next;
}

/***********************************************************************
* Default deconstructor for class Queue
***********************************************************************/

Queue::~Queue()
{
    while (!isEmpty())
    {
        Node * temp;
        temp = removeFront();
        delete temp;
    }

}
