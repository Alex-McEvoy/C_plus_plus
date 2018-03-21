/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Client code for TreeOfLife. Creates a game for Tree of Life.
*******************************************************************************/

#include<iostream>
using std::cout;
using std::endl;

#include<string>
using std::string;

#include<vector>
using std::vector;

#include"Utilities.hpp"   // For menuInts(), isInt() and validIntInput()
#include"treeOfLife.hpp"


int main()
{
    // These vectors are all for function menuInts, which takes a vector of both string options and viable int user input options
    string msg = "Welcome to The Tree of Life. Would you like to play?";
    vector<string> optionsStr {"Yes", "No"};
    vector<int> optionsInt {1,2};

    int playOrNot;

    cout <<
    "          .     .  .      +     .      .          .                \n"
    "     .       .      .     #       .           .                    \n"
    "        .      .         ###            .      .      .            \n"
    "      .      .   ##:. .:#####:. .:##  .      .                     \n"
    "    Fire      . ###############  .          Metropolis             \n"
    "    World    ##:.    .:#######:.    .:##  .        .       .       \n"
    "  .             ########|The|########        .        .            \n"
    "        .    ##:.  ####|Tree|#####  .:##   .       .               \n"
    "     .     .  ##########|of|###########                  .         \n"
    "                .######|Life|#######           .      .            \n"
    "    . Dwarf  ...  .:#############:.  ... .:##Jungles               \n"
    "    Kingdom #############################      of    .             \n"
    "    .    .     #######################    .  Elra.                 \n"
    "            .     #      000      #    .     .                     \n"
    "       .         .   .   000     .        .       .                \n"
    "..Home World............O000O..............Swamps of Mon.....      \n"
     << endl;

     playOrNot = menuInts(msg, optionsStr, optionsInt);

     if ( playOrNot == 1)
     {
       treeOfLife tree;
       tree.playGame();
     }

return 0;
}
