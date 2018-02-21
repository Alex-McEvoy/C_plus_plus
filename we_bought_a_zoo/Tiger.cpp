/***********************************************************************************
* Author: Alex McEvoy
* Date: 01/29/18
* Description: Implementation file for Tiger class. A Tiger is a derived class from animal
* which has a set cost, number of babies, payoff and base food cost.
************************************************************************************/


#include"Tiger.hpp"


Tiger::Tiger(int animalAge)
    : Animal(animalAge)         // Call our base class constructor with the age of the animal
{

    numberOfBabies = 1;
    cost = 10000.00;
    foodCost = baseFoodCost * 10;
    payoff = cost * .20;
    animalName = "Tiger";
}
