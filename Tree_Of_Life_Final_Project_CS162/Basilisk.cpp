/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Implementation file for class Basilisk. This class is inherited from class
* character and has two additional member functions attack() and defense() for
* combat with the player. This takes the place of interact
*******************************************************************************/

#include<iostream>
using std::cout;
using std::endl;
using std::cin;

#include<map>
using std::map;

#include<vector>
using std::vector;

#include<string>
using std::string;

#include"Player.hpp"
#include"Basilisk.hpp"
#include"Utilities.hpp"




Basilisk::Basilisk()
{
  name = "Basilisk";
  armor = 1;
  hitPoints = 5;

  // Create all the possible things Basilisk can say and add them to our map
  // of initial and later responses
  string greeting1 = "Grrr, snap! HISS!";

  string greeting2 = "Grrr, snap! HISS";
  string farewell = "The basilisk prowls angrily around the smoky lava pools nearby\n";



  string option1 = "Fight the Basilisk";
  string option2 = "Hide from the Basilisk";

  string combatWin = "You have defeated the Fire Basilisk!";
  string combatLose = "The Fire Basilisk has badly injured you and you limp away!";

  // Map our responses with the previous strings
  initialResponses["greeting"] = greeting1;
  initialResponses["farewell"] = farewell;

  laterResponses["greeting"] = greeting2;
  laterResponses["farewell"] = farewell;
  laterResponses["win"] = combatWin;
  laterResponses["lose"] = combatLose;

  playerOptionsString.push_back(option1);
  playerOptionsString.push_back(option2);

  playerOptionsInt.push_back(1);
  playerOptionsInt.push_back(2);

  visited = false;

}

/***********************************************************************
* Basilisk Special action is to fight the player. If player wins they
* receive the fire skin.
***********************************************************************/

void Basilisk::specialAction(Player* playerIn)
{
    if (  combat(playerIn) == true )
    {
      cout << laterResponses["win"] << endl;
      const int FIRESKIN_ID = 4;
      Item* fireSkin = new Item(FIRESKIN_ID, "Fire Skin",
                        "A scaly, warm to the touch pelt that glows bright");
      playerIn->addItem(fireSkin);
      hitPoints = 5;          // Revive the Basilisk. The basilisk can be fought multiple times
    }
    else
    {
      cout << laterResponses["lose"] << endl;
    }
}

/***********************************************************************
* Attack function. Returns 1d4 attack and starts with 5 health
***********************************************************************/

int Basilisk::attack()
{
  const int ATTACK_DIE = 4;

  return diceRoll(ATTACK_DIE, 1);
}

/***********************************************************************
* defend function. Basilisk had 1d4 defense
***********************************************************************/

int Basilisk::defend()
{
  const int DEFENSE_DIE = 4;

  return diceRoll(DEFENSE_DIE, 1) + armor;
}

/***********************************************************************
* Fight the two characters, Player and Basilisk
***********************************************************************/

bool Basilisk::combat(Player* playerIn)
{
  bool playerWon = true;
  while(hitPoints > 0 && playerIn->getHitPoints() > 0)
  {
    int attackRoll = playerIn->attack();
    int defenseRoll = defend();

    int damage = attackRoll - defenseRoll;

    if (damage >= 0)
    {
      hitPoints -= damage;
      cout << "You attacked causing " << damage << " damage!" << endl;
      wait();
    }


    // Check to see if Basilisk is still alive and attack if so
    if(hitPoints > 0)
    {
      attackRoll = attack();
      defenseRoll = playerIn->defend();

      damage = attackRoll - defenseRoll;

      if (damage >= 0)
      {
        playerIn->doDamage(damage);
        cout << "Basilisk attacks causing " << damage << " damage!" << endl;
        wait();
      }

      // Check to see if our player died
      if (playerIn->getHitPoints() <= 0)
      { playerWon = false; }
    }

  }
return playerWon;

}

/***********************************************************************
* Interact with Basilisk.
***********************************************************************/

void Basilisk::interact(Player* playerIn)
{
  int userChoice;
  string msg = "Please choose from one of the options below";



  do {
          userChoice = menuInts(msg, playerOptionsString, playerOptionsInt);

          if (!visited) // If this is our first time visiting the character
          {
            switch (userChoice) {
              case 1: {
                        cout << initialResponses["greeting"] << endl;
                        wait();
                        visited = true;
                        specialAction(playerIn);
                        userChoice = 2;
                        break;
                      }

              case 2: {
                        cout << initialResponses["farewell"] << endl;
                        wait();
                        visited = true;
                        break;
                      }

            }
          }
          // If this is our second time visiting the character
          else
          {
            switch (userChoice) {
              case 1: {
                        cout << laterResponses["greeting"] << endl;
                        wait();
                        specialAction(playerIn);
                        userChoice = 2;
                        break;
                      }

              case 2: {
                        cout << laterResponses["farewell"] << endl;
                        wait();
                        break;
                      }

            }
          }
      } while(userChoice != 2);

}

/***********************************************************************************
* Default deconstructor for class Basilisk
************************************************************************************/

Basilisk::~Basilisk()
{
}
