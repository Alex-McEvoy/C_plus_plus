/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Implementation file for class Sister. This class inherits from
* Character and has a few short responses. It has no special ability
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
#include"Sister.hpp"
#include"Utilities.hpp"



Sister::Sister()
{
  name = "Sister";

  // Create all the possible things Sister can say and add them to our map
  // of initial and later responses
  string greeting1 = "Your sister groans in pain and appears dazed. It's difficult to \n"
                      " tell is she knows you're even there";
  string greeting2 = "Your sister lies still in a feverish sleep";
  string farewell = "";
  string specialAct = "";

  string option1 = "Speak with Sister";
  string option2 = "Leave Sister";


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
* Sister Has no special action
***********************************************************************/

void Sister::specialAction(Player* playerIn)
{
}


/***********************************************************************
* Interact with Sister. Sister gives you a small pearl when you say
* farewell the first time.
***********************************************************************/

void Sister::interact(Player* playerIn)
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
                        break;
                      }

              case 2: {
                        cout << initialResponses["farewell"] << endl;
                        visited = true;
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
                        cout << laterResponses["farewell"] << endl;
                        wait();
                        break;
                      }

            }
          }
      } while(userChoice != 2);

}

/***********************************************************************************
* Default deconstructor for class Sister
************************************************************************************/

Sister::~Sister()
{
}
