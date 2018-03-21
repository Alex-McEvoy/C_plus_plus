/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Implementation file for class Gromdrin. This class inherits from Character
* and has a few short responses. It has a special ability to give the player
* fire Arrows, but only if the player has the fire lizards skin.
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
#include"Gromdrin.hpp"
#include"Utilities.hpp"



Gromdrin::Gromdrin()
{
  name = "Gromdrin";

  // Create all the possible things Gromdrin can say and add them to our map
  // of initial and later responses
  string greeting1 = "Well I'll be! We don't see many travelers from your part \n"
                    "of the tree, which I have to say is a little surprising, considering \n"
                    "how close we are! I heard of the attack on your world recently by \n"
                    "the dreadwind, and I'm very sorry for your people's loss. Foul creatures \n"
                    "the dreadwinds are. The trick is you don't want to get anywhere close to \n"
                    "them when you fight. Arrows work best, and not just any arrows, fire arrows.\n"
                    "I can make the arrows for you, and a mighty bow too, but I'll need a few things first.\n"
                    "Wood is scarce around here, and a bow should be made of only the best wood. \n"
                    "For the fire arrows, I'll need the skin of a fire basilisk from the world just north \n"
                    "of here. My service aren't free however, and it'll cost you for both. If you're \n"
                    "short on money we could use a hand for day working in the mines. \n"
                    "The pay is 5 gold a day. What say you?";

  string greeting2 = "Did you bring me some timber? Or maybe the basilisk's skin? \n"
                      "The bow will cost 50 gold, and the fire arrows I could make for 10\n"
                      "Or perhaps you've come to work a day in the mines? We could always use good help \n"
                      "down there";
  string farewell = "Go North to find the fire basilisk, and the elves may know where good lumber may be found";
  string work = "Thanks for your help, here's the 5 gold promised to you";
  string noSkin = "You don't have the Fire Basilisk Skin I need";
  string noMoney = "You don't have enough money for that right now.";
  string makeArrows = "These arrows will make short work of any creature, big or small";
  string noWood = "You don't have the Wood I need for the bow";
  string makeBow = "Here you go lad, a fine bow to pierce even the thickest armor";

  string option1 = "Speak with Gromdrin";
  string option2 = "Work in Mines (Takes 1 day, pays 5 gold)";
  string option3 = "Leave Gromdrin";


  // Map our responses with the previous strings
  initialResponses["greeting"] = greeting1;
  initialResponses["farewell"] = farewell;
  initialResponses["work"] = work;

  laterResponses["greeting"] = greeting2;
  laterResponses["farewell"] = farewell;
  laterResponses["noSkin"] = noSkin;
  laterResponses["noMoney"] = noMoney;
  laterResponses["makeArrows"] = makeArrows;
  laterResponses["noWood"] = noWood;
  laterResponses["makeBow"] = makeBow;

  playerOptionsString.push_back(option1);
  playerOptionsString.push_back(option2);
  playerOptionsString.push_back(option3);


  playerOptionsInt.push_back(1);
  playerOptionsInt.push_back(2);
  playerOptionsInt.push_back(3);


  visited = false;

}

/***********************************************************************
* Gromdrin gives the player the options of making the fire arrows, making
* the bow, or working a day in the mines. The function checks whether or not
* the player has the necessary items and money to make the weapons, and removes
* them if they do, replacing them with the weapons.
***********************************************************************/

void Gromdrin::specialAction(Player* playerIn)
{
    const int ARROW_COST = 10;
    const int BOW_COST = 50;
    string msg = "Please choose from the options below";
    vector <string> optionsStr = {"Make arrows",
                                "Make Bow",
                                "Quit"};
    vector<int> optionsInt = {1,2,3};
    int userChoice = menuInts(msg, optionsStr, optionsInt);
    while (userChoice != 3)
    {
      switch (userChoice) {
        case 1: {
                    if (!playerIn->hasItem("Fire Skin"))
                    {
                      cout << laterResponses["noSkin"] << endl;
                      wait();
                      break;
                    }

                    else if (!playerIn->hasMoney(ARROW_COST))
                    {
                      cout << laterResponses["noMoney"] << endl;
                      wait();
                      break;
                    }

                    else
                    {
                        const int FIRE_ARROW_ID = 6;

                        cout << laterResponses["makeArrows"] << endl;
                        wait();
                        playerIn->removeMoney(ARROW_COST);      // Pay Gromdrin
                        playerIn->removeItem("Fire Skin");

                        Item * fireArrows = new Item(FIRE_ARROW_ID, "Fire Arrows",    // Create the arrows
                                                    "Magical arrows imbued with powerful runes of fire.");
                        playerIn->addItem(fireArrows);    // Give them to player
                        break;
                    }
                }
        case 2: {
                    if (!playerIn->hasItem("Strong Branch"))
                    {
                      cout << laterResponses["noWood"] << endl;
                      wait();
                      break;
                    }

                    else if (!playerIn->hasMoney(BOW_COST))
                    {
                      cout << laterResponses["noMoney"] << endl;
                      wait();
                      break;
                    }

                    else
                    {
                        const int BOW_ID = 3;
                        cout << laterResponses["makeBow"] << endl;
                        playerIn->removeMoney(BOW_COST);    // Pay Gromdrin
                        playerIn->removeItem("Strong Branch");

                        Item * bow = new Item(BOW_ID, "Bow",
                                                    "Powerful longbow with the strength to pierce armor.");
                        playerIn->addItem(bow);
                        break;
                    }
                }

      }

    userChoice = menuInts(msg, optionsStr, optionsInt);

    }




}


/***********************************************************************
* Interact with Gromdrin. Gromdrin gives you a small pearl when you say
* farewell the first time.
***********************************************************************/

void Gromdrin::interact(Player* playerIn)
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
                        break;
                      }

              case 2: {
                        const int WORK_PAY = 5;
                        cout << initialResponses["work"] << endl;
                        wait();
                        playerIn->oneDay();       // Cause one day to pass
                        playerIn->addMoney(WORK_PAY);
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
                        specialAction(playerIn);
                        break;
                      }

              case 2: {
                        const int WORK_PAY = 5;
                        cout << initialResponses["work"] << endl;
                        wait();
                        playerIn->oneDay();       // Cause one day to pass
                        playerIn->addMoney(WORK_PAY);
                        break;
                      }

              case 3: {
                        cout << laterResponses["farewell"] << endl;
                        wait();
                        break;
                      }

            }
          }
      } while(userChoice != 3);

}

/***********************************************************************************
* Default deconstructor for class Gromdrin
************************************************************************************/

Gromdrin::~Gromdrin()
{
}
