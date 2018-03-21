/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Implementation file for class Innkeeper. This class is derived
* from Character and has the special ability to let the player rest and
* regenerate hit points in exchange for 5 gold.
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
#include"Innkeeper.hpp"
#include"Utilities.hpp"


Innkeeper::Innkeeper()
{
  name = "Innkeeper";

  // Create all the possible things Innkeeper can say and add them to our map
  // of initial and later responses
  string greeting1 = "I have several rooms available, though from the looks of \n"
                    "you it seems like the stables might be a better place to \n"
                    "put you. Nevertheless, a good nights rest here will get \n"
                    "you back in tip top shape. It's 5 gold for the night";

  string greeting2 = "Recent advances in tempur-pedic mattresses have given"
                    "beds the ability to heal even the most grevious of wounds!"
                    "Poison bites? No Problem! Lost an arm? A quick nap will "
                    "fix you right up! Seriously, it's only 5 gold, just do it.";

  string farewell = "You'll be back.....";

  string stayTheNight = "Room's upstairs and to the right";

  string noMoney = "It costs 5 gold to stay here. If you don't have any money \n"
                    "why not give the dwarf mines a try? It's good, back \n"
                    "breaking labor at its finest";

  string option1 = "Talk to the Innkeeper";
  string option2 = "Stay at the Inn";
  string option3 = "Leave";

  // Map our responses with the previous strings
  initialResponses["greeting"] = greeting1;
  initialResponses["farewell"] = farewell;


  laterResponses["greeting"] = greeting2;
  laterResponses["farewell"] = farewell;
  laterResponses["stay"] = stayTheNight;
  laterResponses["noMoney"] = noMoney;

  playerOptionsString.push_back(option1);
  playerOptionsString.push_back(option2);
  playerOptionsString.push_back(option3);

  playerOptionsInt.push_back(1);
  playerOptionsInt.push_back(2);
  playerOptionsInt.push_back(3);


  visited = false;

}

/***********************************************************************
* Innkeeper Special action is to allow the player to rest, restoring their
* hit points and taking 5 gold.
***********************************************************************/

void Innkeeper::specialAction(Player* playerIn)
{
  const int ROOM_COST = 5;
  const int HEALING_POINTS = 10;
  if (!playerIn->hasMoney(ROOM_COST))
  {
    cout << laterResponses["noMoney"] << endl;
    wait();
  }
  else
  {
    cout << laterResponses["stay"] << endl;
    wait();
    playerIn->removeMoney(ROOM_COST);
    playerIn->heal(HEALING_POINTS);
  }

}

/***********************************************************************
* Interact with Innkeeper.
***********************************************************************/

void Innkeeper::interact(Player* playerIn)
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
                        break;
                      }

              case 2: {
                        specialAction(playerIn);
                        visited = true;
                        break;
                      }

              case 3: {
                        cout << initialResponses["farewell"] << endl;
                        wait();
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
                        break;
                      }

              case 2: {
                        specialAction(playerIn);
                        break;
                      }

              case 3: {
                        cout << laterResponses["farewell"] << endl;
                        wait();
                      }


            }
          }
      } while(userChoice != 3);

}

/***********************************************************************************
* Default deconstructor for class Innkeeper
************************************************************************************/

Innkeeper::~Innkeeper()
{
}
