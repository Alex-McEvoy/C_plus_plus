/***********************************************************************************
* Author: Alex McEvoy
* Date: 01/29/18
* Description: Implementation file for Turtle class. A Turtle is a derived class from animal
* which has a set cost, number of babies, payoff and base food cost.
************************************************************************************/


#include"Turtle.hpp"

Turtle::Turtle(int animalAge)
    : Animal(animalAge)         // Call our base class constructor with the age of the animal
{
    numberOfBabies = 10;
    cost = 100.00;
    foodCost = baseFoodCost * .5;
    payoff = cost * .05;
    animalName = "Turtle";
}
