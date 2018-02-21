/***********************************************************************************
* Author: Alex McEvoy
* Date: 01/29/18
* Description: Implementation file for Penguin class. A Penguin is a derived class from animal
* which has a set cost, number of babies, payoff and base food cost.
************************************************************************************/


#include"Penguin.hpp"

Penguin::Penguin(int animalAge)
    : Animal(animalAge)         // Call our base class constructor with the age of the animal
{
    numberOfBabies = 5;
    cost = 1000.00;
    foodCost = baseFoodCost;
    payoff = cost * .10;
    animalName = "Penguin";
}
