/***********************************************************************************
* Author: Alex McEvoy
* Date: 01/29/18
* Description: Header file for RandomAnimal class. A RandomAnimal is a
* derived class from animal which has a cost, number of babies, payoff and base
* food cost that is set by the user.
************************************************************************************/

#ifndef RANDOMANIMAL_HPP
#define RANDOMANIMAL_HPP

#include"Animal.hpp"

class RandomAnimal : public Animal
{
private:

    void getAnimalName();
    void getNumBabies();
    void getAnimalCost();
    void getfoodPrice();
    void getPayoff();
public:
    RandomAnimal(int);

};


#endif
