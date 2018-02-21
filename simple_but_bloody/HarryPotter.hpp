/***********************************************************************************
* Author: Alex McEvoy
* Date: 02/10/18
* Description: Header file for HarryPotter class. This class is inherited from Character
* and has the additional ability of Hogwarts, where he gets one time to die, before being
* brought back to life with 20 hit points instead of his original 10.
************************************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include<string>
#include"Character.hpp"

class HarryPotter : public Character
{
private:
    bool Hogwarts;

public:
    HarryPotter(std::string);

    virtual int attack();   // Our overrided attack function
    virtual int defense();  // Our overrided defense function
    virtual void doDamage(int); // Overrided doDamage function
    virtual ~HarryPotter();
};

#endif
