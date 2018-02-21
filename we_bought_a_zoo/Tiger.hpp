/***********************************************************************************
* Author: Alex McEvoy
* Date: 01/29/18
* Description: Header file for Tiger class. A Tiger is a derived class from animal
* which has a set cost, number of babies, payoff and base food cost.
************************************************************************************/

#ifndef TIGER_HPP
#define TIGER_HPP

#include"Animal.hpp"

class Tiger : public Animal
{

public:
    Tiger(int);
};

#endif
