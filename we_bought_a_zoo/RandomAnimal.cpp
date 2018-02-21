/***********************************************************************************
* Author: Alex McEvoy
* Date: 01/29/18
* Description: Implementation file for RandomAnimal class. A RandomAnimal is a
* derived class from animal which has a cost, number of babies, payoff and base
* food cost that is set by the user.
************************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include"RandomAnimal.hpp"
#include"Utilities.hpp"
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::cin;

/***********************************************************************
* Gets our animal type from the user. This can be any valid string.
***********************************************************************/

void RandomAnimal::getAnimalName()
{
    string animalType;
    cout << "\nPlease enter the type of animal you'd like to create. " << endl;
    cout << "Any name will do here (they don't even have to be real)" << endl;
    cout << "These species are so exotic, you won't be able to buy them after this, " << endl;
    cout << "but they can give birth to new ones." << endl;


    cin.clear();
    cin.ignore(256, '\n');
    getline(cin, animalType);

    animalName = animalType;
}

/***********************************************************************
* Gets the number of babies for the new animal from the user. Uses Utility
* function validIntInput() to verify an int between 1 and 20
***********************************************************************/

void RandomAnimal::getNumBabies()
{
    const int MIN_BABIES = 1;
    const int MAX_BABIES = 3;
    int babies;

    string msg = "\nPlease enter how many babies the animal produces at once (1-3)";
    std::vector<int> range = numRange(MIN_BABIES, MAX_BABIES);

    babies = validIntInput(msg, range);

    numberOfBabies = babies;
}

/***********************************************************************
* Gets the cost of one of the new animals. The Utility function isDouble()
* is used for input validation.
***********************************************************************/

void RandomAnimal::getAnimalCost()
{
    double animalCost;
    vector<int> range = numRange(1, 1000);
    string msg = "\nPlease enter how much one of these beasts costs.(1-1,000)";


    animalCost = validIntInput(msg, range);

    cost = animalCost;

}

/***********************************************************************
* Gets the food price for the animal, this is a percentage of the base
* food cost, which is $10.
***********************************************************************/

void RandomAnimal::getfoodPrice()
{
    double foodMultiplier;

    string msg = "\nPlease enter how many times the base food price this animal's food costs.\n"
    "For example, if you want it to cost the base price, enter 1. \nIf you want it to cost 10 times"
    " the base price, enter 10.";

    foodMultiplier = isDouble(msg);

    foodCost = baseFoodCost * foodMultiplier;
}

/***********************************************************************
* Gets the payout of one of the new animals. The user enters a percentage
* of base cost. isDouble() is used for input validation and the daily
* payoff is calculated.
***********************************************************************/

void RandomAnimal::getPayoff()
{
    double animalPayoff;
    vector<int> range = numRange(1,25);
    string msg = "\nPlease enter what percentage of the base animal cost this animal makes per day(1-25)";

    animalPayoff = validIntInput(msg, range);

    payoff = cost * (animalPayoff / 100.00);
}


/***********************************************************************
* Default constructor. Calls all private functions to populate member
* variables for an animal object of the user's choice.
***********************************************************************/

RandomAnimal::RandomAnimal(int animalAge)
    : Animal(animalAge)         // Call our base class constructor with the age of the animal
{
    getAnimalName();
    getNumBabies();
    getAnimalCost();
    getfoodPrice();
    getPayoff();

}
