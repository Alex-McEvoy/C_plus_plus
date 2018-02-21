/***********************************************************************************
* Author: Alex McEvoy
* Date: 02/10/18
* Description: Header file for Character class. This class is the abstract class which
* provides the base class for classes Vampire, Barbarian, BlueMen, Medusa and HarryPotter.
* It contains member variables for armor and strength points, and virtual functions for
* attack and defense.
************************************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include<string>

class Character
{
protected:
    std::string name;
    std::string type;
    int armor;
    int strength;
    bool dead;

public:
    Character(std::string);
    virtual int attack() = 0;
    virtual int defense() = 0;
    virtual void doDamage(int) = 0;


    std::string getName()
    {   return name;    }
    std::string getType()
    {   return type;    }
    int getArmor()
    {   return armor;   }
    int getStrength()
    {   return strength;    }
    bool isDead()
    {   return dead;    }

    virtual ~Character();


};

#endif
