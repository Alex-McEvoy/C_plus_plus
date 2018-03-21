/***********************************************************************************
* Author: Alex McEvoy
* Date: 03/01/18
* Description: Client code file for Combat class, which creates three containters
* for two teams and a loser pile of objects of type character. Prompts the user to
* enter the characer types and their names, as well as how many fighters per team.
* Utilitzes classes Character, Barbarian, BlueMen, HarryPotter, Medusa, Vampire and
* Utilities.
************************************************************************************/


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include"Utilities.hpp"
#include"Combat.hpp"
using std::vector;
using std::string;

int main()
{
    vector<string> optionsStr {"Play", "Exit"};
    vector<int> optionsInt {1,2};

    string msg = "Please choose from the options below";

    int userInput = menuInts(msg, optionsStr, optionsInt);

    while (userInput != 2)
    {
        Combat * combatGame = new Combat;
        combatGame->getTeamSize();

        combatGame->getFighters();

        combatGame->tournament();

        delete combatGame;
        optionsStr.clear();
        optionsStr.push_back("Play Again");
        optionsStr.push_back("Quit");

        userInput = menuInts(msg, optionsStr, optionsInt);

    }

    return 0;
}
