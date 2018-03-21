/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Header file for class treeOfLife. This class creates all
* objects of type World and the Player object. It then controls the interactions
* between the player and the World objects until the Player either wins or loses.
*******************************************************************************/

#include<iostream>
using std::cout;
using std::endl;
using std::cin;

#include<vector>
using std::vector;

#include<string>
using std::string;

#include<fstream>
using std::ifstream;

#include"Player.hpp"
#include"Item.hpp"
#include"Character.hpp"
#include"World.hpp"
#include"homeWorld.hpp"
#include"Mother.hpp"
#include"Sister.hpp"
#include"treeOfLife.hpp"
#include"Utilities.hpp"

/***********************************************************************
* Default Constructor for treeOfLife. Links all the worlds together,
* creates our new Player,
***********************************************************************/

treeOfLife::treeOfLife()
{
  currentPlayer = new Player();

  // Link the worlds together
  home_world.setNorth(&dwarf_kingdom);
  home_world.setEast(&swamp);

  dwarf_kingdom.setSouth(&home_world);
  dwarf_kingdom.setNorth(&fire_world);
  dwarf_kingdom.setEast(&jungle);

  fire_world.setSouth(&dwarf_kingdom);
  fire_world.setEast(&metropolis);

  metropolis.setWest(&fire_world);
  metropolis.setSouth(&jungle);

  jungle.setNorth(&metropolis);
  jungle.setWest(&dwarf_kingdom);
  jungle.setSouth(&swamp);

  swamp.setNorth(&jungle);
  swamp.setWest(&home_world);



}

/***********************************************************************
* Takes the Player and the currentWorld and gives Player the chance to
* interact with the Characters received from World, check their stats
* (including Inventory) or Travel based on the pointers in the currentWorld.
* Takes in the current world and the current Player, outputs which world
* the player should travel to next, or Quit.
***********************************************************************/

WhichWorld treeOfLife::enterWorld(World * worldIn, Player * playerIn)
{
  int firstMenu, userChoice;
  WhichWorld travelTo = QUIT;
  string travelToString;

  // Greet the Player to the new World
  cout << "You teleport via the Tree of Life to " << worldIn->getWorldName() << "\n" << endl;
  cout << "__________________________________________________________________________" << endl;
  cout << worldIn->getDescription() << endl;
  cout << "__________________________________________________________________________" << endl;
  wait();


  // Our Menu function takes a vector of string options with corresponding
  // integer options for the player to choose. Populate those vectors now
  string msg = "Please choose one option of the following options";
  vector<string> optionsStr {"Explore World", "Check Player Stats/Items", "Travel", "Show Map", "Quit"};
  vector<int> optionsInt {1,2,3,4,5};
  firstMenu = menuInts(msg, optionsStr, optionsInt);

  // Get our Characters from the World
  vector<Character*> characters = worldIn->getCharacters();

  // While our user doesnt want to Quit
  while (firstMenu != 5 && gameOver() == 0)
  {
    switch (firstMenu) {
      // The user wants to Interact with the Characters in World.
      case 1: {
                string msg = "Please select which Character you'd like to interact with: ";
                optionsStr.clear();     // Clear our string options vector for re-use here
                optionsInt.clear();
                for (int i = 0; i < characters.size(); i++) {
                    optionsStr.push_back(characters.at(i)->getName());
                    optionsInt.push_back(i + 1);
                }

                userChoice = menuInts(msg, optionsStr, optionsInt);

                // Have the player interact with that Character
                characters.at(userChoice - 1)->interact(playerIn);
                break;
              }
      // Check player stats
      case 2: {
                string msg = "Please select which Player info you'd like to see: ";
                optionsStr.clear();     // Clear our string options vector for re-use here
                optionsInt.clear();

                optionsStr.push_back("Show Items");
                optionsStr.push_back("Show Stats");
                optionsStr.push_back("back");

                optionsInt.push_back(1);
                optionsInt.push_back(2);
                optionsInt.push_back(3);

                userChoice = menuInts(msg, optionsStr, optionsInt);
                while (userChoice != 3) {
                  switch (userChoice) {
                    case 1:
                        playerIn->showItems();
                        break;
                    case 2:
                        playerIn->showStats();
                        break;
                  }

                  userChoice = menuInts(msg, optionsStr, optionsInt);
                }
                break;
              }
      // Travel
      case 3: {
                string msg = "Please choose which area you'd like to travel to..";
                // Get the vector of possible world choices
                vector<World*> linkedWorlds = worldIn->getLinkedWorlds();
                optionsStr.clear();
                optionsInt.clear();

                // Populate the player's output options with the linked Worlds,
                // and an int for the player to choose
                for (int i = 0; i < linkedWorlds.size(); i++) {
                  if (linkedWorlds.at(i) != nullptr)
                  {
                    optionsStr.push_back(linkedWorlds.at(i)->getWorldName());
                    optionsInt.push_back(i + 1);
                  }
                }

                // Add a quit option for travel
                optionsStr.push_back("Quit");
                optionsInt.push_back(linkedWorlds.size() + 1);

                userChoice = menuInts(msg, optionsStr, optionsInt);

                // If our user chose a world to travel to (not quit)
                if(userChoice <= linkedWorlds.size())
                {
                  travelToString = linkedWorlds.at(userChoice - 1)->getWorldName();
                }
                else    // If user wants to quit
                {
                  break;
                }

                if ( travelToString == "Home World" )
                { travelTo = HOME;  }
                else if ( travelToString == "Dwarf Kingdom")
                { travelTo = DWARF; }
                else if ( travelToString == "Fire World")
                { travelTo = FIRE; }
                else if ( travelToString == "Metropolis")
                { travelTo = METRO; }
                else if ( travelToString == "Jungles of Elra")
                { travelTo = JUNGLE; }
                else if ( travelToString == "Swamps of Mon")
                { travelTo = SWAMP; }

                cout << "One day has passed while you travel" << endl;
                playerIn->oneDay();

                return travelTo;
              }
        case 4: {
                    string map;
                    if(worldIn->getWorldName() == "Home World")
                    {
                        // Largeley taken from
                        // http://www.cplusplus.com/forum/general/58945/
                        map = outputMap("homeworld.txt");
                        cout << map << endl;
                        wait();
                    }
                    else if (worldIn->getWorldName() == "Dwarf Kingdom")
                    {
                        map = outputMap("dwarfkingdom.txt");
                        cout << map << endl;
                        wait();
                    }
                    else if (worldIn->getWorldName() == "Fire World")
                    {
                        map = outputMap("fireworld.txt");
                        cout << map << endl;
                        wait();
                    }
                    else if (worldIn->getWorldName() == "Metropolis")
                    {
                        map = outputMap("metropolis.txt");
                        cout << map << endl;
                        wait();
                    }
                    else if (worldIn->getWorldName() == "Jungles of Elra")
                    {
                        map = outputMap("junglesofelra.txt");
                        cout << map << endl;
                        wait();
                    }
                    else if (worldIn->getWorldName() == "Swamps of Mon")
                    {
                        map = outputMap("swampsofmon.txt");
                        cout << map << endl;
                        wait();
                    }
                    break;
                }
        }         // end of switch statement

        optionsStr.clear();
        optionsInt.clear();

        optionsStr.push_back("Explore World");
        optionsStr.push_back("Check Player Stats/Items");
        optionsStr.push_back("Travel");
        optionsStr.push_back("Show Map");
        optionsStr.push_back("Quit");

        optionsInt.push_back(1);
        optionsInt.push_back(2);
        optionsInt.push_back(3);
        optionsInt.push_back(4);
        optionsInt.push_back(5);


        firstMenu = menuInts(msg, optionsStr, optionsInt);

    }

    return travelTo;
}


/***********************************************************************
* This function controls which World our Player is interacting with, when
* enterWorld() returns, it lets playGame() know which world we should
* travel to.
***********************************************************************/

void treeOfLife::playGame()
{
  WhichWorld world = HOME;
  bool endGame = false;

  cout << "__________________________________________________________________________" << endl;
  cout << "                             *Tree of life*" << endl;
  cout << "Long ago the people of your planet were visited by a noble and" << endl;
  cout << "benevolent race of creatures called the Ben’ai who revealed to us that " << endl;
  cout << "there are many worlds besides your own and they are connected by a" << endl;
  cout << "great conduit called the tree of life. This conduit runs through" << endl;
  cout << "everything and allows creatures of all races to be transported instantly" << endl;
  cout << "from one world to the next. While this has ushered in a great age" << endl;
  cout << "of cooperation and knowledge, great evil too has spread through the universe." << endl;
  cout << "Wild, raging beasts have been known to traverse the tree and" << endl;
  cout << "violently attack any life they come across. You are a young hunter" << endl;
  cout << "from a remote planet who’s village was attacked by one of these creatures," << endl;
  cout << "a great many armed beast known as a Dreadwind. The beasts attacks come" << endl;
  cout << "with a poison edge, and your young sister has been poisoned." << endl;
  cout << "You must find the creature, kill it, and bring back it’s tooth to save her!" << endl;
  cout << "__________________________________________________________________________" << endl;

  wait();


  while (!endGame) {
      switch (gameOver()) {
        // Player has not lost, keep playing
        case 0: {
                    switch (world) {
                      case HOME:
                        currentWorld = &home_world;
                        world = enterWorld(currentWorld, currentPlayer);
                        break;
                      case DWARF:
                        currentWorld = &dwarf_kingdom;
                        world = enterWorld(currentWorld, currentPlayer);
                        break;
                      case FIRE:
                        currentWorld = &fire_world;
                        world = enterWorld(currentWorld, currentPlayer);
                        break;
                      case METRO:
                        currentWorld = &metropolis;
                        world = enterWorld(currentWorld, currentPlayer);
                        break;
                      case JUNGLE:
                        currentWorld = &jungle;
                        world = enterWorld(currentWorld, currentPlayer);
                        break;
                      case SWAMP:
                        currentWorld = &swamp;
                        world = enterWorld(currentWorld, currentPlayer);
                        break;
                      case QUIT:
                        string msg = "Are you sure you want to quit?";
                        vector<string> optionsStr = {"Yes", "No"};
                        vector<int> optionsInt = {1,2};
                        int userChoice = menuInts(msg, optionsStr, optionsInt);
                        if (userChoice == 1)
                        { endGame = true;}
                        else
                        { world = enterWorld(currentWorld, currentPlayer);  }
                        break;
                      }
                      break;
                }
        // Player has died
        case 1: {
                    cout << "\n_________________________________________________" << endl;
                    cout << "You wounds overcome you as you try to leave the world" << endl;
                    cout << "the tree envelops your body as you drift away to" << endl;
                    cout << "eternal rest" << endl;
                    cout << "Game Over" << endl;
                    cout << "_________________________________________________" << endl;
                    wait();
                    endGame = true;
                    break;
                }
        case 2: {   cout << "\n_________________________________________________" << endl;
                    cout << "With the setting of the sun you realize that your " << endl;
                    cout << "sisters last moments have come and gone. You are too late." << endl;
                    cout << "Game Over" << endl;
                    cout <<"_________________________________________________" << endl;
                    wait();
                    endGame = true;
                    break;
                }
        case 3: {
                    cout << "\n_________________________________________________" << endl;
                    cout << "Your mother quickly makes the antidote to the " << endl;
                    cout << "Dreadwinds poison with the beasts tooth. After " << endl;
                    cout << "giving your sister the murky solution her eyes" << endl;
                    cout << "flutter and open and she sees you and your mother " << endl;
                    cout << "standing by her bed. It looks as though she's" << endl;
                    cout << "going to be ok. You win" << endl;
                    cout << "_________________________________________________" << endl;
                    wait();
                    endGame = true;
                    break;
                }
      }

  }

}

/***********************************************************************************
* Allows the user to read output before continuing. Taken from
* final project of Ryan McCann, CS162.
************************************************************************************/

void treeOfLife::wait()
{
  string temp;
  cout << "\nPress enter";
  std::cin.clear();
  std::cin.ignore(256,'\n');
  getline(cin, temp);

}

/***********************************************************************
* Checks to see if the game has ended. Returns 0 if still going, 1 if
* player has died, 2 if time is up, and 3 if player has won.
***********************************************************************/

int treeOfLife::gameOver()
{
  if (  currentPlayer->getHitPoints() <= 0  )
  { return 1; }
  else if (  currentPlayer->getTimeLeft() <=0  )
  { return 2;}
  else if (currentPlayer->hasItem("Poison Tooth") && currentWorld->getWorldName() == "Home World")
  { return 3; }
  else
  { return 0; }
}

/***********************************************************************
* Used to read in ASCII files for map output. Function taken from
* http://www.cplusplus.com/forum/general/58945/ TheMassiveChipmunk's
* answer.
***********************************************************************/

string treeOfLife::outputMap (string fileName)
{
    ifstream Reader(fileName);


    string Lines = "";        //All lines

    if (Reader)                      //Check if everything is good
    {
	while (Reader.good ())
	{
	    string TempLine;                       //Temp line
	    std::getline (Reader , TempLine);      //Get temp line
	    TempLine += "\n";                      //Add newline character

	    Lines += TempLine;                     //Add newline
	}

        Reader.close();
	    return Lines;
    }
    else                           //Return error
    {
	return "ERROR File does not exist.";
    }

}

/***********************************************************************
* Deconstructor for tree of life
***********************************************************************/

treeOfLife::~treeOfLife()
{
    delete currentPlayer;
}
