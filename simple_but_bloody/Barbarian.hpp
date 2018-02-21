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
        // All private member variables inherited from Character class

public:
    Barbarian(std::string);

    virtual int attack();   // Our overrided attack function
    virtual int defense();  // Our overrided defense function
    virtual void doDamage(int); // Overrided doDamage function
    ~Barbarian();
};

#endif
