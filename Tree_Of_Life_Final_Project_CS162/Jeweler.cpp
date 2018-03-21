/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Implementation file for class Jeweler. This class is derived from
* Character and has the special ability to buy the players Pearl.
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
#include"Jeweler.hpp"
#include"Utilities.hpp"


Jeweler::Jeweler()
{
  name = "Jeweler";

  // Create all the possible things Jeweler can say and add them to our map
  // of initial and later responses
  string greeting1 = "Good day sir! Welcome to the Golden Calf! I deal in fine "
                    "Jewelry and precious metals. How can I help you?";

  string greeting2 = "Have you brought me anything worth looking at?";
  string farewell = "Please bring me something worthwhile next time";

  string sellPearl = "Well, it's not the most valuable specimen I've seen, \n"
                    "but I do suppose I could give you about 50 gold for it, \n"
                    "and not a penny more!";
  string noPearl = "You don't have anything like that to sell me.";

  string option1 = "Talk to the Jeweler";
  string option2 = "Sell the Jeweler your pearl";
  string option3 = "Leave";

  // Map our responses with the previous strings
  initialResponses["greeting"] = greeting1;
  initialResponses["farewell"] = farewell;


  laterResponses["greeting"] = greeting2;
  laterResponses["farewell"] = farewell;
  laterResponses["sell"] = sellPearl;
  laterResponses["noPearl"] = noPearl;

  playerOptionsString.push_back(option1);
  playerOptionsString.push_back(option2);
  playerOptionsString.push_back(option3);

  playerOptionsInt.push_back(1);
  playerOptionsInt.push_back(2);
  playerOptionsInt.push_back(3);


  visited = false;

}

/***********************************************************************
* Jeweler Special action is to buy the player's pearl.
***********************************************************************/

void Jeweler::specialAction(Player* playerIn)
{
  const int PEARL_COST = 50;

  if (  playerIn->hasItem("pearl") )
  {
    cout << laterResponses["sell"] << endl;
    wait();
    playerIn->removeItem("pearl");
    playerIn->addMoney(PEARL_COST);
  }
  else
  {
    cout << laterResponses["noPearl"] << endl;
    wait();
  }


}

/***********************************************************************
* Interact with Jeweler.
***********************************************************************/

void Jeweler::interact(Player* playerIn)
{
  int userChoice;
  string temp;
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
                        cout << initialResponses["farewell"] << endl;
                        wait();
                        visited = true;
                        break;
                      }

              case 3: {
                        cout << laterResponses["farewell"] << endl;
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
                        wait();
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
* Default deconstructor for class Jeweler
************************************************************************************/

Jeweler::~Jeweler()
{
}
