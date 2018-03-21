/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Header file for class Dreadwind. This class is inherited from class
* character and has three additional member functions attack() defense() and
* combat() so it can battle with Player. This takes the place of interact.
* The Dreadwind gives up it's poison tooth when defeated.
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
#include"Dreadwind.hpp"
#include"Utilities.hpp"




Dreadwind::Dreadwind()
{
  name = "Dreadwind";
  armor = 10;
  hitPoints = 30;

  // Create all the possible things Dreadwind can say and add them to our map
  // of initial and later responses
  string greeting1 = "The Beast turns and glares at you with flaring nostrils. \n"
                    "You're struck by how intelligently the creature seems to \n"
                    "assess how threatening you are. Seemingly unimpressed, the \n"
                    "Dreadwind charges you";

  string greeting2 = "The creatures turns and glares at you with green poison \n"
                    "dripping from it's razor sharp fangs. It seems to notice the \n"
                    "weapon you carry and hesitates. As you raise your bow the \n"
                    "beast lowers it's head, growls, and charges.";

  string farewell = "The monster continues prowling through the murky shallows, \n"
                    "smoke rising from the places where it's poisonous drool \n"
                    "hits the ground. It doesn't seem to notice you";

  string dead = "The dreadwind lies dead, a magical arrow embedded deep in its hide \n"
                "You take another tooth from the monster";

  string combatWin = "You have defeated the Dreadwind!";
  string combatLose = "The Dreadwind has badly injured you and you limp away";

  string option1 = "Fight the Dreadwind";
  string option2 = "Hide from the Dreadwind";



  // Map our responses with the previous strings
  initialResponses["angry"] = greeting1;
  initialResponses["scared"] = greeting2;
  initialResponses["farewell"] = farewell;
  initialResponses["dead"] = dead;

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
* Dreadwind Special action is to fight the player. If player wins they
* receive the fire skin.
***********************************************************************/

void Dreadwind::specialAction(Player* playerIn)
{
    if (  combat(playerIn) == true )
    {
      cout << laterResponses["win"] << endl;
      wait();
      const int POISONTOOTH_ID = 5;
      Item* poisonTooth = new Item(POISONTOOTH_ID, "Poison Tooth",
                        "An acrid, festering tooth which can be use to make an antidote to poison");
      playerIn->addItem(poisonTooth);

    }
    else
    {
      cout << laterResponses["lose"] << endl;
      wait();
    }
}

/***********************************************************************
* Attack function. Returns 1d10 attack
***********************************************************************/

int Dreadwind::attack()
{
  const int ATTACK_DIE = 10;

  return diceRoll(ATTACK_DIE, 1);
}

/***********************************************************************
* defend function. Dreadwind had 1d8 defense plus 10 armor
***********************************************************************/

int Dreadwind::defend()
{
  const int DEFENSE_DIE = 8;

  return diceRoll(DEFENSE_DIE, 1) + armor;
}

/***********************************************************************
* Fight the two characters, Player and Dreadwind
***********************************************************************/

bool Dreadwind::combat(Player* playerIn)
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
    else
    {
      cout << "You don't even pierce the thick hide of the creature" << endl;
      wait();
    }


    // Check to see if Dreadwind is still alive and attack if so
    if(hitPoints > 0)
    {
      attackRoll = attack();
      defenseRoll = playerIn->defend();

      damage = attackRoll - defenseRoll;

      if (damage >= 0)
      {
        playerIn->doDamage(damage);
        cout << "Dreadwind attacks causing " << damage << " damage!" << endl;
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
* Interact with Dreadwind.
***********************************************************************/

void Dreadwind::interact(Player* playerIn)
{
  int userChoice;
  string msg = "Please choose from one of the options below";



  do {
          userChoice = menuInts(msg, playerOptionsString, playerOptionsInt);
          // Check to see if the player has already killed the DreadWind
          if (hitPoints <= 0)
          {
              cout << initialResponses["dead"] << endl;
              wait();
              const int POISONTOOTH_ID = 5;
              Item* poisonTooth = new Item(POISONTOOTH_ID, "Poison Tooth",
                                "An acrid, festering tooth which can be use to make an antidote to poison");
              playerIn->addItem(poisonTooth);
              userChoice = 2;

          }

          if (!visited) // If this is our first time visiting the character
          {
            switch (userChoice) {
              case 1: {
                        if (playerIn->hasItem("Bow") && playerIn->hasItem("Fire Arrows"))
                        {
                          cout << initialResponses["scared"] << endl;
                          wait();
                        }
                        else
                        {
                          cout << initialResponses["angry"] << endl;
                          wait();
                        }
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
                        if (playerIn->hasItem("Bow") && playerIn->hasItem("Fire Arrows"))
                        {
                          cout << initialResponses["scared"] << endl;
                          wait();
                        }
                        else
                        {
                          cout << initialResponses["angry"] << endl;
                          wait();
                        }
                        visited = true;
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
* Default deconstructor for class Dreadwind
************************************************************************************/

Dreadwind::~Dreadwind()
{
}
