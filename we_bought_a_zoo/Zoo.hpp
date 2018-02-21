/***********************************************************************************
* Author: Alex McEvoy
* Date: 01/30/18
* Description: Header file for class Zoo. This object uses class Animal and its
* derived classes to create a money making zoo. It stores the animals in dynamic
* arrays of pointers to type Animal.
************************************************************************************/

#ifndef ZOO_HPP
#define ZOO_HPP

#include<iostream>
#include<string>
#include"Animal.hpp"
#include"Tiger.hpp"
#include"Penguin.hpp"
#include"Turtle.hpp"
#include"RandomAnimal.hpp"

enum Species {tigers, penguins, turtles, randomAnimals, speciesSize};
enum Event {sickness, boom, baby, nothing};

class Zoo
{
private:
    double money, feedModifier, bonus;
    int feedType;

    Animal*** animals;                 // This is a pointer, to an array of pointers, to pointers.
    int animalCount[speciesSize];      // Use the enum flag speciesSize to indicate how many species types we have
    int maxAnimals[speciesSize];       // Use this to keep track of maximum animals in dynamic array

    double addAnimal(Species, int);      // Takes species and how many days old
    bool oneDay();
    void getFeedType();
    Event randomEvent();
    void heDied();
    void attendanceBoom();
    void newBaby();
    void buyAnimal();


public:
    Zoo();
    void playGame();
    ~Zoo();



};


#endif
