/***********************************************************************************
* Author: Alex McEvoy
* Date: 03/01/18
* Description: Header file for Combat class, which creates three containters
* for two teams and a loser pile of objects of type character. Prompts the user to
* enter the characer types and their names, as well as how many fighters per team.
* Utilitzes classes Character, Barbarian, BlueMen, HarryPotter, Medusa, Vampire and
* Utilities.
************************************************************************************/


#ifndef COMBAT_HPP
#define COMBAT_HPP

#include"Character.hpp"
#include"Vampire.hpp"
#include"Barbarian.hpp"
#include"BlueMen.hpp"
#include"Medusa.hpp"
#include"HarryPotter.hpp"
#include"Queue.hpp"
#include"Node.hpp"


class Combat
{
private:
    int numPlayers;
    int scoreTeam1, scoreTeam2;

    Queue team1, team2, losers;
    void battle(Character *, Character *);
    bool isWinner();

public:
    Combat();
    void getTeamSize();
    void getFighters();
    void tournament();
    ~Combat();

};

#endif
