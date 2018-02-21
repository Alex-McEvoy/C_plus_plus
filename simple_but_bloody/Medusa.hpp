/***********************************************************************************
* Author: Alex McEvoy
* Date: 02/10/18
* Description: Header file for Medusa class. This class is inherited from Character
* and has the additional ability of Gaze, where if it rolls a 12 on attack, the defender
* is instantly killed (unless a vampire charms her into not attacking).
************************************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include<string>
#include"Character.hpp"

class Medusa : public Character
{
private:
    // All private member variables inherited from Character class

public:
    Medusa(std::string);

    virtual int attack();   // Our overrided attack function
    virtual int defense();  // Our overrided defense function
    virtual void doDamage(int); // Overrided doDamage function
    virtual ~Medusa();
};

#endif
