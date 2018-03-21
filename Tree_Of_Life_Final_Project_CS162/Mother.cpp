/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Implementation file for class Mother. This class inherits from
* Character and has a few short responses. It has a special ability to give the
* player a family jewel.
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
#include"Mother.hpp"
#include"Utilities.hpp"



Mother::Mother()
{
  name = "Mother";

  // Create all the possible things mother can say and add them to our map
  // of initial and later responses
  string greeting1 = "My son, I know the responsibility you bear is great, but we \n"
                    "have faith that you will kill this creature, and bring back \n"
                    "that which your sister, Aisha, needs to survive. Trust in \n"
                    "the tree, and it will guide you on your journey";
  string greeting2 = "I am glad to see you, though I do fear that Aisha will \n"
                      "not be able to hold on much longer";
  string farewell = "Farewell my child, all our hopes lie with you";
  string specialAct = "Take this with you, it's a small pearl that has been \n"
                          "with our family for years. It's not worth much, but \n"
                          "it may help you on your journey. You should also \n"
                          "remember to take your knife with you, you'll surely \n"
                          " need it";

  string option1 = "Speak with Mother";
  string option2 = "Leave Mother";


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
* Mother gives the player a small pearl
***********************************************************************/

void Mother::specialAction(Player* playerIn)
{
    // Set the item ID's of our new items
    const int PEARL_ID = 1;
    const int KNIFE_ID = 2;
    Item * pearl = new Item(PEARL_ID, "pearl", "This item is small but somewhat valuable");
    Item * knife = new Item(KNIFE_ID, "knife",
                          "A small knife which gives you an attack of 1 die 10");

    playerIn->addItem(pearl);
    playerIn->addItem(knife);

}


/***********************************************************************
* Interact with Mother. Mother gives you a small pearl when you say
* farewell the first time.
***********************************************************************/

void Mother::interact(Player* playerIn)
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
* Default deconstructor for class Mother
************************************************************************************/

Mother::~Mother()
{
}
