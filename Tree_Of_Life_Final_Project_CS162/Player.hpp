/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Header file for class Player. This class represents the person
* who will be playing the game. They will have a vector of type Item which
* will represent their inventory. They will also have int values for money,
* hitPoints, armor, weapon and poisonCounter. PoisonCounter will count down
* each day or travel that happens, and if it reaches 0 before the player
* kills the Dreadwind and returns home, the game is lost. If the player
* dies, the game is also lost.
*******************************************************************************/


#ifndef PLAYER_HPP
#define PLAYER_HPP

#include<vector>
using std::vector;

#include<string>
using std::string;

#include"Item.hpp"

class Player
{
private:
  const int INVENTORY_MAX = 4;
  vector<Item *> inventory;

  int max_Life,
      hitPoints,
      money,
      armor,
      defense,
      weapon,
      weaponBonus,
      timeLeft;

public:

  Player();
  ~Player();

  void showItems();
  void showStats();
  bool hasItem(string);    // Check to see if Player has a specific item
  void addItem(Item *);
  void removeItem(string);
  void oneDay();
  bool hasMoney(int);
  void addMoney(int);
  void removeMoney(int);
  int attack();
  int defend();
  void doDamage(int);
  void heal(int);

  int getHitPoints()
  { return hitPoints; }
  int getTimeLeft()
  { return timeLeft;  }



};


#endif
