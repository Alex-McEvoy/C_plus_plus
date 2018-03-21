/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Implementation file for class Character. This class provides a
* virtual base class for all NPCs in the game that the player will be
* interacting with.
*******************************************************************************/

#include<iostream>
using std::cout;
using std::cin;

#include<string>
using std::string;

#include"Character.hpp"


/***********************************************************************************
* Default constructor for class Character
************************************************************************************/

Character::Character()
{
}

/***********************************************************************************
* Allows the user to read the characters output before continuing. Taken from
* final project of Ryan McCann, CS162.
************************************************************************************/

void Character::wait()
{
  string temp;
  cout << "\nPress enter";
  std::cin.clear();
  std::cin.ignore(256,'\n');
  getline(cin, temp);

}



/***********************************************************************************
* Default deconstructor for class Character
************************************************************************************/

Character::~Character()
{
}
