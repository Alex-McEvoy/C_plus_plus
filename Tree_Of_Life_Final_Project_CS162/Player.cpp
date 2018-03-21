/*******************************************************************************
* Author: Alex McEvoy
* Date: 03/14/18
* Description: Implementation file for class Player. This class represents the person
* who will be playing the game. They will have a vector of type Item which
* will represent their inventory. They will also have int values for money,
* hitPoints, armor, weapon and poisonCounter. PoisonCounter will count down
* each day or travel that happens, and if it reaches 0 before the player
* kills the Dreadwind and returns home, the game is lost. If the player
* dies, the game is also lost.
*******************************************************************************/

#include<iostream>
using std::cout;
using std::endl;
using std::cin;

#include<iomanip>
using std::setw;

#include<string>
using std::string;

#include<vector>
using std::vector;

#include"Player.hpp"
#include"Item.hpp"
#include"Utilities.hpp"


/***********************************************************************************
* Default constructor for class Character. Starts the character out with an Item
* small knife.
************************************************************************************/

Player::Player()
{
  const int STARTING_LIFE = 10;
  const int STARTING_ARMOR = 2;
  const int MAXIMUM_TURNS = 12;
  const int STARTING_WEAPON = 3;
  const int STARTING_DEFENSE = 3;
  max_Life = STARTING_LIFE;
  hitPoints = max_Life;
  money = 0;
  armor = STARTING_ARMOR;
  defense = STARTING_DEFENSE;
  weapon = STARTING_WEAPON;
  weaponBonus = 0;
  timeLeft = MAXIMUM_TURNS;

}

/***********************************************************************************
* Adds an item to the Player's inventory. This function uses a master list of item ID
* numbers to identify the item and change the player's stats accordingly. The list is

1- small pearl
2 - hunting Knife
3 - Long Bow
4 - Fire Skin
5 - Poison Tooth (needed to win game)
6 - Fire Arrows
7- Tree Branch
************************************************************************************/

void Player::addItem(Item * itemIn)
{
  if (inventory.size() >= INVENTORY_MAX)
  {
    cout << "You have too many things in your inventory, sell something before \
            adding more" << endl;
  }
  else
  {
    cout << "______________________________________" << endl;
    switch (itemIn->getID()) {
      case 1:
        inventory.push_back(itemIn);
        cout << "Received small pearl!" << endl;
        break;

      case 2:                    // Raises Player's weapon attack to 1 die 6
        inventory.push_back(itemIn);
        weapon = 10;
        cout << "Received Hunting Knife!" << endl;
        break;

      case 3:                      // Adds 20 to players roll.
        inventory.push_back(itemIn);
        weaponBonus += 20;
        cout << "Received Long Bow!" << endl;
          // Apply fire arrow bonus if not already applied and Player has fire arrows
          if (hasItem("Fire Arrows"))
          { weaponBonus += 100; }
        break;

      case 4:
        inventory.push_back(itemIn);
        cout << "Received fireskin!" << endl;
        break;

      case 5:
        inventory.push_back(itemIn);
        cout << "Received the poison tooth!" << endl;
        break;
      case 6:
        inventory.push_back(itemIn);
        cout << "Received the fire Arrows!" << endl;
          // Only boost stats if we have the bow as well
          if(hasItem("Bow"))
          { weaponBonus += 100; }
          else
          { cout << "Get the bow to use the fire arrows" << endl;}
        break;
      case 7:       // Call this item name "Wood"
        inventory.push_back(itemIn);
        cout << "Received Strong tree limb" << endl;
    }
    cout << "______________________________________" << endl;

  }

}

/***********************************************************************************
* Checks to see if a player has an item in their inventory using the item's name.
* Returns true if found and false if not.
************************************************************************************/

bool Player::hasItem(string itemName)
{
  bool isFound = false;
  for (int i = 0; i < inventory.size(); i++) {
    if (inventory.at(i)->getName() == itemName)
    { isFound = true;}
  }

  return isFound;
}

/***********************************************************************************
* Removes an item from the player
************************************************************************************/

void Player::removeItem(string itemName)
{
  for (int i = 0; i < inventory.size(); i++) {
    if (inventory.at(i)->getName() == itemName)
    {
        Item* temp = inventory.at(i);
        inventory.erase(inventory.begin() + i);
        delete temp;
    }
  }
}

/***********************************************************************************
* Checks to see if a player has a select amount of money available
************************************************************************************/

bool Player::hasMoney(int amount)
{
  if (money >= amount)
  { return true;  }
  else
  { return false; }

}

/***********************************************************************************
* Subtract money from the player
************************************************************************************/

void Player::removeMoney(int amount)
{
  money -= amount;
}

/***********************************************************************************
* Add money to the Player
************************************************************************************/

void Player::addMoney(int amount)
{
  money += amount;
}

/***********************************************************************************
* Causes one day to pass by subtracting 1 from timeLeft
************************************************************************************/

void Player::oneDay()
{
  timeLeft -= 1;
}

/***********************************************************************************
* Player attacks, returns their attack roll plus weaponBonus
************************************************************************************/

int Player::attack()
{
  return diceRoll(weapon, 1) + weaponBonus;
}

/***********************************************************************************
* returns Player's defense roll plus their armor
************************************************************************************/

int Player::defend()
{
  return diceRoll(defense, 1) + armor;
}

/***********************************************************************************
* Does damage to the player
************************************************************************************/

void Player::doDamage(int damage)
{
  hitPoints -= damage;
}

/***********************************************************************************
* Heals the player up to their max_health
************************************************************************************/

void Player::heal(int healingPoints)
{
  if (hitPoints + healingPoints <= max_Life)
  { hitPoints += healingPoints; }
  else
  { hitPoints = max_Life; }
}

/***********************************************************************************
* Goes through the Player's inventory and displays the items they have
************************************************************************************/

void Player::showItems()
{

  cout << setw(15) << "*Inventory*" << endl;
  cout << "__________________________________________________________________________" << endl;
  if (inventory.size() == 0)
  { cout << "No items in Inventory!" << endl; }

  else
  {
    for (int i = 0; i < inventory.size(); i++) {
      cout << i + 1 << ": " << setw(8) << inventory.at(i)->getName() << " - " <<
            inventory.at(i)->getDescription() << "\n" << endl;
    }
  }

  cout << "__________________________________________________________________________" << endl;
  cout << "Inventory max = " << INVENTORY_MAX << endl;
  cout << "Gold: " << money << endl;

}

/***********************************************************************************
* Shows the player's stats
************************************************************************************/

void Player::showStats()
{
  string temp;

  cout << setw(15) << "*Player Stats*" << endl;
  cout << "_________________________________________________" << endl;
  cout << setw(30) << std::left << "< Maximum Hit Points: " << setw(7) << std::right << max_Life << setw(12) << std::right <<  ">" << endl;
  cout << setw(30) << std::left << "< Current Hit Points: " << setw(7) << std::right << hitPoints << setw(12) << std::right <<  ">" << endl;
  cout << setw(30) << std::left << "< Gold: " << setw(7) << std::right << money << setw(12) << std::right <<  ">" << endl;
  cout << setw(30) << std::left << "< Armor: " << setw(7) << std::right << armor << setw(12) << std::right <<  ">" << endl;
  cout << setw(30) << std::left << "< Attack Roll: " << setw(7) << std::right << "1d" << weapon << setw(11) << std::right <<  ">" << endl;
  cout << setw(30) << std::left << "< Attack Roll Bonus: " << setw(7) << std::right << weaponBonus << setw(12) << std::right <<  ">" << endl;
  cout << setw(30) << std::left << "< Days Until Sister Dies: " << setw(7) << std::right << timeLeft << setw(12) << std::right <<  ">" << endl;
  cout << "_________________________________________________" << endl;

  getline(cin, temp); // Pause so Player can read stats
}



/***********************************************************************************
* Default deconstructor for class Character
************************************************************************************/

Player::~Player()
{
  for (int i = 0; i < inventory.size(); i++) {
    delete inventory.at(i);
  }
}
