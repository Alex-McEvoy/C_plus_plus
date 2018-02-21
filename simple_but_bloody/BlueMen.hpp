/***********************************************************************************
* Author: Alex McEvoy
* Date: 02/10/18
* Description: Header file for BlueMen class. This class is inherited from Character
* and has the additional ability of Mob. It has a High defense depending in how many
* strength points it has. For every 4 strength points it loses, it loses a defense
* die roll.
************************************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include<string>
#include"Character.hpp"

class BlueMen : public Character
{
private:
        // All private member variables inherited from Character class

public:
    BlueMen(std::string);

    virtual int attack();   // Our overrided attack function
    virtual int defense();  // Our overrided defense function
    virtual void doDamage(int); // Overrided doDamage function
    virtual ~BlueMen();

};

#endif
