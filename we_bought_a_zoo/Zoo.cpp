/***********************************************************************************
* Author: Alex McEvoy
* Date: 01/30/18
* Description: Implementation file for class Zoo. This object uses class Animal and its
* derived classes to create a money making zoo. It stores the animals in dynamic
* arrays of pointers to type Animal.
************************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>       // for rand() and srand()
#include"Zoo.hpp"
#include"Tiger.hpp"
#include"Turtle.hpp"
#include"RandomAnimal.hpp"
#include"Utilities.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;


/***********************************************************************
* Default constructor for Zoo. Initializes a 2d array of pointers of type
* Animal to arrays of pointers to type Tiger, Penguin Turtle and
* randomAnimal.
***********************************************************************/

Zoo::Zoo()
{


    const int MAX_ANIMALS = 10;
    const int ANIMAL_TYPES = 4;
    const double STARTING_FUNDS = 100000.00;
    // Inititalize 2d array of pointers
    animals = new Animal**[ANIMAL_TYPES];
    for (int i = 0; i < ANIMAL_TYPES; i++) {
        animals[i] = new Animal*[MAX_ANIMALS];  // Each row is an array of pointers to type Animal
    }
    // set all pointers to NULL
    for (int i = 0; i < ANIMAL_TYPES; i++) {
        for (int j = 0; j < MAX_ANIMALS; j++) {
            animals[i][j] = NULL;
        }
    }

    money = STARTING_FUNDS;
    feedType = 2;
    bonus = 0;

    // Initialize all our animal counts to 0
    for (int i = 0; i < speciesSize; i++) {
        animalCount[i] = 0;
    }

    // Set our maximum animals of each species
    for (int i = 0; i < speciesSize; i++) {
        maxAnimals[i] = MAX_ANIMALS;
    }
}

/***********************************************************************
* Adds a new animal object to animals. Checks to see if the array of
* pointers for that species is full, and if so, adds an additional 10
* spots to that species' array.
***********************************************************************/

double Zoo::addAnimal(Species species, int daysOld)
{
    animalCount[species]++;              // Increment our animal count
    Animal * tempPtr;
    double tempCost;            // Keep track of cost of new animal to adjust Zoo money
    if(species == tigers)
    {   tempPtr = new Tiger(daysOld);   }
    else if (species == penguins)
    {   tempPtr = new Penguin(daysOld); }
    else if (species == turtles)
    {   tempPtr = new Turtle(daysOld);   }
    else if (species == randomAnimals)
    {   tempPtr = new RandomAnimal(daysOld);    }

    tempCost = tempPtr-> getCost();


    // Check to see if our dynamic array is full, If so expand it by 10 spaces
    if (animalCount[species] >= maxAnimals[species])
    {
        maxAnimals[species] += 10;                                  // Increase the max value for that species
        Animal ** tempAnimals = new Animal*[maxAnimals[species]];   // Create temporary array of pointers
        for (int i = 0; i < maxAnimals[species]; i++) {             // Initialize this array of pointers to NULL
            tempAnimals[i] = NULL;                                  // This is necessary for adding the animal object later
        }
        // Transfer our old values over to our new temporary array of pointers
        for (int i = 0; i < maxAnimals[species] - 10; i++) {
            tempAnimals[i] = animals[species][i];
        }

        // Free dynamically allocated memory for old species array of pointers
        delete [] animals[species];

        animals[species] = tempAnimals; // Assign that species array of pointers to the temp array

    }

    // Assign our new animal to a space
    for (int i = 0; i < maxAnimals[species]; i++) {
        if (animals[species][i] == NULL)        // find the first free pointer in that species array
        {
            animals[species][i] = tempPtr;       // Assign to our temp animal to that location and exit the for loop
            tempPtr = NULL;
            break;
        }
    }


    return tempCost;

}

/***********************************************************************
* Gets the feed type from the user using Utility function menuInts().
* It then uses this type to set a feed modifier variable which will be used
* to modify both the cost of feed and chance of sickness.
***********************************************************************/

void Zoo::getFeedType()
{
    string msg = "What kind of feed would you like to give the animals?";
    vector<string> optionsStr {"Cheap: Half as expensive for all animals, sickness becomes twice as likely to occur.",
                                "Generic: behaves normally.",
                                "Premium: Twice as expensive for all animals, sickness becomes half as likely to occur."};
    vector<int> optionsInt {1,2,3};

    int feedType = menuInts(msg, optionsStr, optionsInt);

    if(feedType == 1)
    {   feedModifier = 0.5; }
    else if(feedType == 2)
    {   feedModifier = 1;   }
    else if (feedType == 3)
    {   feedModifier = 2;   }

}

/***********************************************************************
* Returns a random event, baby born, boom day or animal sickness. animal
* sickness is affected by feed type. chance of nothing happening is slighlty
* higher than average to allow room for chance of sickness to double if
* cheap feed is chosen.
***********************************************************************/

Event Zoo::randomEvent()
{
    const int BASENUM = 4;
    srand(time(0));
    int randNum = rand() % 20;
    int babyChance, boomChance, sickChance;

    babyChance = boomChance = sickChance = BASENUM;

    // Using division here, low cost feed increases chance of sickness,
    // high cost feed decreases chance
    sickChance /= feedModifier;

    if (randNum <= babyChance)                                  // If num is between 0-4
    {   return baby;  }
    else if (randNum <= babyChance + boomChance)                // If num between 4-8
    {   return boom;    }
    else if (randNum <= babyChance + boomChance + sickChance)   // If num between 8-12 for normal feed, 8-10 for premium feed
    {   return sickness;    }                                   // and 8-16 for cheap feed
    else                                                        // else nothing happened
    {   return nothing; }
}

/***********************************************************************
* Kills one animal of a random species. Sets the pointer of that Animal
* to NULL.
***********************************************************************/

void Zoo::heDied()
{
    cout << "Oh no! An animal has fallen sick and died!" << endl;
    bool success = false;
    while(!success)
    // Taken largely from https://stackoverflow.com/questions/2999012/generating-random-enums
    {Species species = static_cast<Species>(rand() % speciesSize);    // Get a random species
    if(animalCount[species] > 0)                  // If there are any of that species in the zoo
    {
        delete animals[species][animalCount[species] - 1];
        animals[species][animalCount[species] - 1] = NULL;
        animalCount[species]--;
        success = true;
    }
    }
}

/***********************************************************************
* Provides a random bonus between $250-500 per tiger in the Zoo.
***********************************************************************/

void Zoo::attendanceBoom()
{
    cout << "Hooray! We have an attendance boom!" << endl;
    int theBonus = rand() % 250 + 250;  // Gives numbers between 250-500

    theBonus *= animalCount[tigers];
    bonus = theBonus;
}

/***********************************************************************
* Creates a new baby of a random species. It creates a vector of possible
* animal species which are slowly removed as species are tested for animals
* aged 3 days and above. If no animals are older than 3 days the function
* outputs an error message and exits.
***********************************************************************/

void Zoo::newBaby()
{
    cout << "Hooray! One of our animals has given birth!" << endl;
    bool success = false;
    vector<Species> speciesVect {tigers, penguins, turtles, randomAnimals};
    while(!success)
    {
        int randomIndex = rand() % speciesVect.size();      // Get a random index based on speciesVect size
        Species species = speciesVect[randomIndex];     // Use that index to get a random species
        speciesVect.erase(speciesVect.begin() + randomIndex);                 // Remove that species from the vector

        // Check to see if we have an adult animal of that type, and make a baby
        for (int i = 0; i < animalCount[species]; i++) {
            if(animals[species][i]->getAge() >= 3)
            {
                int numAnimals = animals[species][i]-> getNumberOfBabies();
                for (int i = 0; i < numAnimals; i++) {
                    addAnimal(species, 0);              // Since these babies are being born, do not subtract their cost from money
                }
                success = true;
                break;
            }
        }

        if(speciesVect.size() <= 0)
        {
            success = true;
            cout << "No animals able to give birth." << endl;
        }
    }
}

/***********************************************************************
* Asks the user to select an animal to buy, then checks to see if they
* have enough money. The user only gets one chance to pick an animal.
***********************************************************************/

void Zoo::buyAnimal()
{
    string msg = "Please select which animal you'd like to buy";
    vector<string> choicesStr {"Tiger - $10,000", "Penguin - $1,000", "Turtle - $100.00"};
    vector<int> choicesInt {1,2,3};
    vector<double> costs {10000, 1000, 100};
    int userSelection = menuInts(msg, choicesStr, choicesInt);

    if(money < costs.at(userSelection - 1))
    {   cout << "You don't have enough money for that animal" << endl; }
    else
    {
        Species species = static_cast<Species>(userSelection - 1);
        double tempCosts = addAnimal(species, 3);
        money -= tempCosts;
    }


}

/***********************************************************************
* Executes one day of the Zoo being open.
***********************************************************************/

bool Zoo::oneDay()
{


    // Increase animals age by 1
    for (int i = 0; i < speciesSize; i++) {
        for (int j = 0; j < animalCount[i]; j++) {
            animals[i][j]->incrementAge();
        }
    }

    // Get the feed type from the user and adjust food prices accordingly
    getFeedType();
    double feedCost = 0;
    // Add all feed costs per animal
    for (int i = 0; i < speciesSize; i++) {
        for (int j = 0; j < animalCount[i]; j++) {
            feedCost += (animals[i][j]->getFoodCost()) * feedModifier;
        }
    }
    // Subtract feed costs from money
    money -= feedCost;

    cout << "\nYou spent $" << feedCost << " on feed." << endl;
    
    // Have a random event happen
    Event event = randomEvent();

    if(event == sickness)
    {   heDied();    }
    else if(event == boom)
    {   attendanceBoom(); }
    else if(event == baby)
    {   newBaby();  }

    // Add our bonus, if any
    money += bonus;

    cout << "Your bonus was $" << bonus << endl;

    // Add our payoff per animal
    double totalPayoff;
    for (int i = 0; i < speciesSize; i++) {
        for (int j = 0; j < animalCount[i]; j++) {
            totalPayoff += animals[i][j] -> getPayoff();
        }
    }

    money += totalPayoff;

    cout << "You made $" << totalPayoff << " from animal payoff." << endl;
    cout << "You have $" << money << " dollars left.";

    // Check to see if we went bust that round
    if(money <= 0)
    {
        cout << "You've gone broke!" << endl;
        return true;
    }

    // Give the user a chance to buy an animal
    string msg = "Would you like to buy another animal?";
    vector<string> choicesStr {"Yes", "No"};
    vector<int> choicesInt {1,2};

    int userSelection = menuInts(msg, choicesStr, choicesInt);

    if(userSelection == 1)
    {
        buyAnimal();
    }

    cout << "You have \n" << animalCount[tigers] << " Tigers" << endl;
    cout << animalCount[penguins] << " Penguins" << endl;
    cout << animalCount[turtles] << " Turtles" << endl;
    cout << animalCount[randomAnimals] << " Random Animals" << endl;
    cout << "Money: $" << money << endl;

    // Ask the user to continue or not
    msg = "Would you like to keep playing";

    userSelection = menuInts(msg, choicesStr, choicesInt);

    bonus = 0;                      // reset bonus

    if(userSelection == 1)
    {   return false;   }
    else
    {   return true;    }

}

/***********************************************************************
* Starts the Zoo game. Begins by letting the user know how much money
* they have and then prompting them to buy either one or two of each animal
* type.
***********************************************************************/

void Zoo::playGame()
{
    const int DAYS_OLD = 3;
    std::vector<int> choicesInt {1,2};
    string animalString[4] = {"tigers", "penguins", "turtles", "other animals"};

    cout << "Let's buy a Zoo! You've got $" << money << " dollars to start." << endl;
    cout << "We need to start our zoo with at least three different kinds of animal." << endl;

    int initialCost = 0;
    for (int i = 0; i < speciesSize; i++) {
        string msg = "Please enter how many " + animalString[i] + " you'd like to start with.(1-2)";
        int num = validIntInput(msg, choicesInt);
        for (int j = 0; j < num; j++) {
            Species val = static_cast<Species>(i);
            initialCost += addAnimal(val, DAYS_OLD);
        }
    }
    money -= initialCost;
    bool noMoney = false;

    while(!noMoney)
    {
        noMoney = oneDay();
    }
    cout << "Thanks for playing!" << endl;
}

/***********************************************************************
* Destructor for type Zoo
***********************************************************************/

Zoo::~Zoo()
{
    for (int i = 0; i < speciesSize; i++) {
        for (int j = 0; j < animalCount[i]; j++) {
            if (animals[i][j] != NULL)
            {
                delete animals[i][j];
                animals[i][j] = NULL;
            }
        }
        delete [] animals[i];
    }
    delete [] animals;
}
