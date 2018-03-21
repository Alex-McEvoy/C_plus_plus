/***********************************************************************************
* Author: Alex McEvoy
* Date: 03/01/18
* Description: Implementation file for Combat class, which creates three containters
* for two teams and a loser pile of objects of type character. Prompts the user to
* enter the characer types and their names, as well as how many fighters per team.
* Utilitzes classes Character, Barbarian, BlueMen, HarryPotter, Medusa, Vampire and
* Utilities.
************************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>     // For std::max in ignore()
#include<sstream>       // For output string in getFighters()
#include"Combat.hpp"
#include"Character.hpp"
#include"Vampire.hpp"
#include"Barbarian.hpp"
#include"BlueMen.hpp"
#include"Medusa.hpp"
#include"HarryPotter.hpp"
#include"Utilities.hpp"
using std::cout;
using std::endl;
using std::string;
using std::vector;

/***********************************************************************
* Default constructor for class Combat
***********************************************************************/

Combat::Combat()
{
    scoreTeam1 = scoreTeam2 = 0;
}

/***********************************************************************
* Gets the team size for the user, uses Utility function validIntInput
* to validate user input
***********************************************************************/

void Combat::getTeamSize()
{
    string msg = "Please enter how many fighters you want on each team (1-15)";

    vector<int> range = numRange(1,15);

    int userInput = validIntInput(msg, range);

    numPlayers = userInput;
}

/***********************************************************************
* Instantiates the fighters for each team. For each fighter, it gets the
* name and type of character. It then instantiates the node in the appropriate
* team Queue.
***********************************************************************/

void Combat::getFighters()
{
    const int NUM_TEAMS = 2;
    string msg;
    string name;                                                                                 // For our Utility function menuInts
    vector<string> optionsStr {"Vampire", "Medusa", "Blue Men", "Barbarian", "Harry Potter"};   // For our Utility function menuInts
    vector<int> optionsInt {1,2,3,4,5};                                                          // For our Utility function menuInts

    std::ostringstream oss;                 // Alows us t dynamically output which fighter and team we are getting input for


    for (int i = 0; i < NUM_TEAMS; i++) {
        for (int j = 0; j < numPlayers; j++) {
            oss << "For team " << i + 1 << ", ";
            oss << "please enter the type for player " << j + 1;
            msg = oss.str();
            int userInput = menuInts(msg, optionsStr, optionsInt) - 1;

            playerType typeIn = static_cast<playerType>(userInput);   // Change our int value to type playerType

            oss.clear();        // Clear the os stream for the next message
            oss.str("");

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


            cout << "For team " << i + 1 << ", ";
            cout << "please enter the name for player " << j + 1 << ": ";

            std::getline(std::cin, name, '\n');

            if(i + 1 == 1)
            {
                team1.addBack(typeIn, name);
                team1.printQueue();
            }
            else if (i + 1 == 2)
            {
                team2.addBack(typeIn, name);
                team2.printQueue();
            }
        }
        }
}

/***********************************************************************
* This Function takes in pointers to two character objects and has them
* fight. First the attacker rolls an attack and the defender rolls a defense
* roll. The damage inflicted is calculated and applied to the defender with their
* doDamage function(). If the damage is very high, then Medusa has turned a victim
* to stone. If the defense is very high, then a Vampire must have charmed
* and attacker.
***********************************************************************/

void Combat::battle(Character * attacker, Character * defender)
{
    int attackRoll = attacker->attack();
    int defenseRoll = defender->defense(attackRoll);

    // Find our damage inflicted
    int damageInflicted = attackRoll - defenseRoll;
    if(damageInflicted <= 0)
    {   damageInflicted = 0;    }

}


/***********************************************************************
* This Function checks to see if there is a winner, if so, it outputs the
* winner, score and gives the user the option to output the loser pile
***********************************************************************/

bool Combat::isWinner()
{
    if(team1.isEmpty() || team2.isEmpty())          // If either team is empty
    {
        if(scoreTeam1 > scoreTeam2)
        {
            cout << "Team 1 Won!" << endl;
        }
        else
        {
            cout << "Team 2 Won!" << endl;
        }

        cout << "Final Scores.." << endl;
        cout << "Team 1: " << scoreTeam1 << endl;
        cout << "Team 2: " << scoreTeam2 << endl;

        string msg = "Would you like to see the loser pile?";
        vector<string> optionsStr {"Yes", "No"};   // For our Utility function menuInts
        vector<int> optionsInt {1,2};

        int userInput = menuInts(msg, optionsStr, optionsInt);

        if(userInput == 1)
        {
            cout << "Loser pile is..." << endl;
            losers.printQueue();
        }

        return true;
    }

    else
    {   return false;   }
}

/***********************************************************************
* This Function takes the two fully formed teams and pits them against
* one another, one fighter at a time. It uses the battle function to fight
* first two fighters in each team Queue. The loser is removed to the loser
* and the winner has their recover() function called and is moved to the back
* of the pile.
***********************************************************************/

void Combat::tournament()
{
    int roundCounter = 0;
    while(!isWinner())
    {
        roundCounter++;
        Character * fighter1;
        Character * fighter2;
        bool death = false;

        fighter1 = team1.getFront();
        fighter2 = team2.getFront();

        while(!death)
        {
            battle(fighter1, fighter2);

            if(fighter2->isDead())
            {
                death = true;
                Node * temp = team2.removeFront();
                losers.loserPile(temp);
                fighter1->recover();
                team1.moveToBack();
                cout << "\nRound " << roundCounter << ": " << fighter1->getType() << " " << fighter1->getName() << " vs. ";
                cout << fighter2->getType() << " " << fighter2->getName() << ":  " << endl;
                cout << fighter1->getName() << " Won!" << endl;
                scoreTeam1++;
            }
            else
            {
                battle(fighter2, fighter1);
                if(fighter1->isDead())
                {
                    death = true;
                    Node * temp = team1.removeFront();
                    losers.loserPile(temp);
                    fighter2->recover();
                    team2.moveToBack();
                    cout << "\nRound " << roundCounter << ": " << fighter1->getType() << " " << fighter1->getName() << " vs. ";
                    cout << fighter2->getType() << " " << fighter2->getName() << ":  " << endl;
                    cout << fighter2->getName() << " Won!" << endl;
                    scoreTeam2++;
                }
            }

        }
    }
}


/***********************************************************************
* Default constructor for class Combat
***********************************************************************/

Combat::~Combat()
{
}
