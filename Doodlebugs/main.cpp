
#include<iostream>
#include<vector>
#include<string>
#include"Critter.hpp"
#include"Ant.hpp"
#include"Doodlebug.hpp"
#include"Board.hpp"

#include"Utilities.hpp"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int userSteps;

    int test = 1;
    while (test != 2) {
	   cout << "We completed the extra credit portion of this assignment" << std::endl;
	   cout << "How many steps, (1-100), would you like to make in the game?\n";
	   cin >> userSteps;
	   if (userSteps < 1 || userSteps > 100 || ((int)userSteps != userSteps)) {
		  cout << "That is an unacceptable entry.  Please choose 1 or 2.";
		  cin.clear();
		  cin.ignore(80, '\n');

	   }
	   else if (userSteps >= 1) {

		  Board board1;
		  Board board2 = board1;

		  while (userSteps > 0)
		  {

			 board1.moveBugs();
			 board2 = board1;
			 userSteps--;
		  }

	   }

       std::string msg = "Would you like to play again?";
       std::vector<std::string> optionsStr {"Yes", "No"};
       std::vector<int> optionsInt {1,2};

       test = menuInts(msg, optionsStr, optionsInt);
    }
    return 0;
}
