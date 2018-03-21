/***********************************************************************************
* Author: Alex McEvoy
* Date: 02/10/18
* Description: Header file for Vampire class. This class is inherited from Character
* and has the additional ability of charm, where it gets a chance every turn to have
* a character not attack it.
************************************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP
#include<string>
#include"Character.hpp"

class Vampire : public Character
{
private:
    const int MAX_ARMOR = 1;
    const int MAX_STRENGTH = 18;

public:
    Vampire(std::string);

    virtual int attack();   // Our overrided attack function
    virtual int defense(int);  // Our overrided defense function
    virtual void doDamage(int); // Overrided doDamage function
    virtual void recover();     // Recovers some hit points lost
    virtual ~Vampire();
};

#endif
