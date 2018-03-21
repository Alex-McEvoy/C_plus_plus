/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Implementation file for class ElfRanger. This class is derived
* from Character and has the special ability to give the Player a special
* tree branch
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
#include"ElfRanger.hpp"
#include"Utilities.hpp"



ElfRanger::ElfRanger()
{
  name = "ElfRanger";

  // Create all the possible things ElfRanger can say and add them to our map
  // of initial and later responses
  string greeting1 = "I have heard of your people, and I know of the attack on \n"
                    "your world by the twisted creature they call the Dreadwind. \n"
                    "If there is any way that I may assist you in your journey, \n"
                    "please let me know.";
  string greeting2 = "It is good to see you young hunter";

  string farewell = "Tread lightly, the foe you seek is not known to be merciful";

  string specialAct = "Take this with you, it's a branch of Ironwood which, \n"
                          "if given to the right person, could make a fine bow. \n"
                          "I wish you luck, hunter. You may well need it.";


  string option1 = "Speak with ElfRanger";
  string option2 = "Leave ElfRanger";


  // Map our responses with the previous strings
  initialResponses["greeting"] = greeting1;
  initialResponses["farewell"] = specialAct;

  laterResponses["greeting"] = greeting2;
  laterResponses["farewell"] = farewell;

  playerOptionsString.push_back(option1);
  playerOptionsString.push_back(option2);

  playerOptionsInt.push_back(1);
  playerOptionsInt.push_back(2);

  visited = false;

}

/***********************************************************************
* ElfRanger gives the player a wood branch
***********************************************************************/

void ElfRanger::specialAction(Player* playerIn)
{
    // Set the item ID's of our new items
    const int BRANCH_ID = 7;

    Item * branch = new Item(BRANCH_ID, "Strong Branch",
                              "This tree limb from the Jungles of Elra is of strong Ironwood, and would make a fine Bow");

    playerIn->addItem(branch);

}


/***********************************************************************
* Interact with ElfRanger. ElfRanger gives you a small pearl when you say
* farewell the first time.
***********************************************************************/

void ElfRanger::interact(Player* playerIn)
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
                        break;
                      }

              case 2: {
                        cout << initialResponses["farewell"] << endl;
                        wait();
                        visited = true;
                        specialAction(playerIn);
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
                        cout << laterResponses["farewell"] << endl;
                        wait();
                        break;
                      }

            }
          }
      } while(userChoice != 2);

}

/***********************************************************************************
* Default deconstructor for class ElfRanger
************************************************************************************/

ElfRanger::~ElfRanger()
{
}
