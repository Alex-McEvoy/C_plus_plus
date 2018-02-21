/***********************************************************************************
* Author: Alex McEvoy
* Date: 02/10/18
* Description: Client code file for Character class an it's inhereited classes. This
* program creates 2 vectors of dynamically allocated pointers to type Character.
* It gives the user a menu to choose two characters to fight and lets them duke it out
* until all but one are dead or the user chooses to exit.
************************************************************************************/


#include<iostream>
#include<string>
#include<vector>
#include"Character.hpp"
#include"Vampire.hpp"
#include"Barbarian.hpp"
#include"BlueMen.hpp"
#include"Medusa.hpp"
#include"HarryPotter.hpp"
#include"Utilities.hpp"

/***********************************************************************
* This Function takes in pointers to two character objects and has them
* fight. First the attacker rolls an attack and the defender rolls a defense
* roll. The damage inflicted is calculated and applied to the defender with their
* doDamage function(). If the damage is very high, then Medusa has turned a victim
* to stone. If the defense is very high, then a Vampire must have charmed
* and attacker.
***********************************************************************/

void battle(Character * attacker, Character * defender)
{
    int attackRoll = attacker->attack();
    int defenseRoll = defender->defense();

    // Find our damage inflicted
    int damageInflicted = attackRoll - defenseRoll;
    if(damageInflicted <= 0)
    {   damageInflicted = 0;    }


    if(defenseRoll > 1000)              // See if Vampire charmed anyone
    {
        std::cout << "Attacker type: " << attacker->getType() << std::endl;
        std::cout << "Defender type: " << defender->getType() << std::endl;
        std::cout << attacker->getType() << " " << attacker->getName() <<
                            " was charmed and did not attack!" << std::endl;
    }
    else if (attackRoll == 1000)        // See if Medusa turned anyone to stone
    {
        std::cout << attacker->getType() << " " << attacker->getName() <<
                " used a glare attack and turned " << defender->getType() << " "
                << defender->getName() << " to stone!" << std::endl;

        defender->doDamage(attackRoll);
    }
    else                                // If neither special case happened
    {
        defender->doDamage(damageInflicted);
        std::cout << "*********************************************************" << std::endl;
        std::cout << "** " << attacker->getType() << " attacker " << attacker->getName() << std::endl;
        std::cout << "** " << defender->getType() << " defender " << defender->getName() << std::endl;
        std::cout << "** " << "Attacker's dice roll: " << attackRoll << std::endl;
        std::cout << "** " << "Defender's dice roll: " << defenseRoll << std::endl;
        std::cout << "** " << "Total damage inflicted: " << damageInflicted << std::endl;
        std::cout << "** " << "Defender's new strength points: " << defender->getStrength() << std::endl;
        std::cout << "*********************************************************" << std::endl;
    }


}
int main()
{
    std::vector<Character *> gladiators;
    std::vector<Character *> backupGladiators;

    Vampire * v1 = new Vampire("Von Carstein");
    Vampire * v2 = new Vampire("Drakkenhoff");

    gladiators.push_back(v1);
    backupGladiators.push_back(v2);

    Barbarian * b1 = new Barbarian("Ug");
    Barbarian * b2 = new Barbarian("Lug");

    gladiators.push_back(b1);
    backupGladiators.push_back(b2);

    BlueMen * bm1 = new BlueMen("Unity");
    BlueMen * bm2 = new BlueMen("PartyPeople");

    gladiators.push_back(bm1);
    backupGladiators.push_back(bm2);

    Medusa * m1 = new Medusa("Becky");
    Medusa * m2 = new Medusa("Tammy");

    gladiators.push_back(m1);
    backupGladiators.push_back(m2);

    HarryPotter * hp1 = new HarryPotter("Little Harry");
    HarryPotter * hp2 = new HarryPotter("Dirty Harry");

    gladiators.push_back(hp1);
    backupGladiators.push_back(hp2);

    std::string msg = "Please Select One Character to Fight...";
    int playAgain;


    do{
        std::string msg = "Please Select Another Character to Fight...";
        std::vector<int> choicesInt = numRange(1, gladiators.size());
        std::vector<std::string> choicesStr;
        choicesStr.clear();

        // Populate our choicesStr vector with the names and types of our contestants
        for (int i = 0; i < gladiators.size(); i++) {
            choicesStr.push_back(gladiators[i]->getType() + " " + gladiators[i]->getName());
        }

        int firstFighter = menuInts(msg, choicesStr, choicesInt) - 1;

        choicesStr.clear();
        // If user wants two of same type of contestants to fight, we need to use a backup contestant
        for (int i = 0; i < backupGladiators.size(); i++) {
            if (i == firstFighter)
            {   choicesStr.push_back(backupGladiators[i]->getType() + " " + backupGladiators[i]->getName());  }
            else
            {choicesStr.push_back(gladiators[i]->getType() + " " + gladiators[i]->getName()); }
        }

        int secondFighter = menuInts(msg, choicesStr, choicesInt) - 1;

        if (firstFighter == secondFighter)
        {
            battle(gladiators[firstFighter], backupGladiators[secondFighter]);
            if (backupGladiators[secondFighter]->isDead())
            {   std::cout << "Defender has Died!" << std::endl; }
            else
            {
                battle(backupGladiators[secondFighter], gladiators[firstFighter]);
                std::cout << '\n';
            }
        }
        else
        {
            battle(gladiators[firstFighter], gladiators[secondFighter]);
            if (gladiators[secondFighter]->isDead())
            {   std::cout << "Defender has Died!" << std::endl; }
            else
            {
                battle(gladiators[secondFighter], gladiators[firstFighter]);
                std::cout << '\n';
            }

        }

        for (int i = 0; i < gladiators.size(); i++) {
            if (gladiators[i]->isDead())
            {
                delete gladiators.at(i);
                gladiators.erase(gladiators.begin() + i);

                delete backupGladiators.at(i);
                backupGladiators.erase(backupGladiators.begin() + i);
            }
        }

        for (int i = 0; i < backupGladiators.size(); i++) {
            if (backupGladiators[i]->isDead())
            {
                delete backupGladiators.at(i);
                backupGladiators.erase(backupGladiators.begin() + i);
            }
        }
        if (gladiators.size() <= 1)
        {
            std::cout << gladiators[0]->getName() << " arises victorious!" << std::endl;
            playAgain = 2;
        }
        else
        {
            msg = "Would you like to play again?";
            choicesStr.clear();
            choicesStr.push_back("Yes");
            choicesStr.push_back("No");
            choicesInt  = numRange(1,2);

            playAgain = menuInts(msg, choicesStr, choicesInt);
        }
    }while (playAgain != 2);

    // Free memory for each gladiator
    for (int i = 0; i < gladiators.size(); i++) {
        delete gladiators.at(i);
    }
    for (int i = 0; i < backupGladiators.size(); i++) {
        delete backupGladiators.at(i);
    }

}
