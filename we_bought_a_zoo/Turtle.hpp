/***********************************************************************************
* Author: Alex McEvoy
* Date: 01/29/18
* Description: Header file for Turtle class. A Turtle is a derived class from animal
* which has a set cost, number of babies, payoff and base food cost.
************************************************************************************/

#ifndef TURTLE_HPP
#define TURTLE_HPP

#include"Animal.hpp"
#include<string>

class Turtle : public Animal
{

public:
    Turtle(int);

};

#endif
