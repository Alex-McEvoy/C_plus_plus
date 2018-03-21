/***********************************************************************************
* Author: Alex McEvoy
* Date: 02/10/18
* Description: Header file for Barbarian class. This class is inherited from Character
* and has no special abilities.
************************************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include<string>
#include"Character.hpp"

class Barbarian : public Character
{
private:
    const int MAX_ARMOR = 0;
    const int MAX_STRENGTH = 12;

public:
    Barbarian(std::string);

    virtual int attack();   // Our overrided attack function
    virtual int defense(int);  // Our overrided defense function
    virtual void doDamage(int); // Overrided doDamage function
    virtual void recover();     // Recovers some hit points lost
    ~Barbarian();
};

#endif
