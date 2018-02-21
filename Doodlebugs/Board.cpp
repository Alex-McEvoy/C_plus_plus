
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include"Board.hpp"
#include"Critter.hpp"
#include"Ant.hpp"
#include"Doodlebug.hpp"
#include"Utilities.hpp"

/***********************************************************************
* Copy constructor for clacc Board. Initializes our 2d array of pointer to
* array of pointers to pointers to objec of type Critter. Copies the exact
* info from the original Board object
***********************************************************************/

Board::Board(const Board &obj)
{
    userRows = obj.userRows;
    userColumns = obj.userColumns;

    arry = new Critter**[userRows];
    for (int i = 0; i < userRows; i++) {
        arry[i] = new Critter*[userColumns];
    }

    // Initialize our array
    for (int i = 0; i < userRows; i++) {
        for (int j = 0; j < userColumns; j++) {
            if ( obj.arry[i][j] != NULL && obj.arry[i][j]->getType() == 1 )
            {
                arry[i][j] = new Doodlebug();
                *arry[i][j] = *obj.arry[i][j];

            }
            else if ( obj.arry[i][j] != NULL && obj.arry[i][j]->getType() == 2 )
            {
                arry[i][j] = new Ant();
                *arry[i][j] = *obj.arry[i][j];
            }
            else
            {
                arry[i][j] = NULL;
            }

        }
    }

}

/***********************************************************************
* Overloaded = operator for class Board. This allows us to maintain the
* state of our board object while we are making changes, as dictated by
* the guidelines for this project. Deletes all of this Board objects 2d
* array and replaces it with a new one which is copied from the new rvalue
* on the = operator
***********************************************************************/

Board& Board::operator=(const Board &obj)
{
    if (this != &obj) // If our object is not the same as the object being passed in
    {   // Delete the current info within our Board object
        for (int i = 0; i < userRows; i++) {
            for (int j = 0; j < userColumns; j++) {
                if (arry[i][j] != NULL)
                {
                    delete arry[i][j];
                    arry[i][j] = NULL;
                }
            }
            delete [] arry[i];
        }
        delete [] arry;
        arry = NULL;
    }

    userRows = obj.userRows;
    userColumns = obj.userColumns;

    // Initialize our newly deleted array, so fresh and so clean clean
    arry = new Critter**[userRows];
    for (int i = 0; i < userRows; i++) {
        arry[i] = new Critter*[userColumns];
    }

    // Set our array equal to the passed in Board object's array
    for (int i = 0; i < userRows; i++) {
        for (int j = 0; j < userColumns; j++) {
            if ( obj.arry[i][j] != NULL && obj.arry[i][j]->getType() == 1 )
            {
                arry[i][j] = new Doodlebug();
                *arry[i][j] = *obj.arry[i][j];

            }
            else if ( obj.arry[i][j] != NULL && obj.arry[i][j]->getType() == 2 )
            {
                arry[i][j] = new Ant();
                *arry[i][j] = *obj.arry[i][j];
            }
            else
            {
                arry[i][j] = NULL;
            }

        }
    }

    return *this;
}

/***********************************************************************
* Prints our board with some primitive but classy formatting. Sometimes
* less is more.
***********************************************************************/

void Board::printBoard()
{

    // Print a nice neat divider
    std::cout << "\n\n";
    for(int x = 0; x <= userColumns + 1; x++)
    {   std::cout << "-";}

    // Print our board
    for (int i = 0; i < userRows; i++) {
        std::cout << std::endl;
        std::cout << "|";
        for (int j = 0; j < userColumns; j++) {
            if (arry[i][j] == NULL)
            { std::cout << " ";    }
            else if (arry[i][j]->getType() == 1)
            {   std::cout << "O";  }
            else if (arry[i][j]->getType() == 2)
            {   std::cout << "X";  }
        }
        std::cout << "|";
    }
    // More dividers
    std::cout << std::endl;
    for(int x = 0; x <= userColumns + 1; x++)
    {   std::cout << "-";}

}

/***********************************************************************
* Defualt constructor for type Board. Initializes a 2D array of pointer to
* array of pointers to pointers to type Critter. Get the array rows and
* columns from the user, as well as the number of ants and Doodlebugs.
* Randomly assignes their location
***********************************************************************/

Board::Board()
{
    userRows = userColumns = 0;
    srand(time(0));
    const int MAX_ROWS_COLS = 30;

    std::cout << "We completed the extra credit portion of this assignment" << std::endl;

    std::string msg = "Please enter how many rows you want (2-30)";
    std::vector<int> range = numRange(2,MAX_ROWS_COLS);

    userRows = validIntInput(msg, range);

    msg = "Please enter how many columns you want (2-30)";

    userColumns = validIntInput(msg, range);
    int maxAnts = (userRows * userColumns);   // Don't allow the user to enter more ants than can fit on the board
                                              // Save room for at least one Doodlebug
    std::ostringstream oss;         // Create a string stream to create a string using integer variables
    oss << "Please enter how many Ants you want to start with (1-" << maxAnts - 1 << ")";

    msg = oss.str();        // Set our menu string equal to the new string stream string

    range.clear();
    range = numRange(1, maxAnts - 1);

    userAnts = validIntInput(msg, range);

    int maxDoodlebugs = maxAnts - userAnts;

    oss.clear();
    oss.str("");

    oss << "Please enter how many Doodlebugs you want to have (1-" << maxDoodlebugs << ")";

    msg = oss.str();

    range.clear();
    range = numRange(1, maxDoodlebugs);

    int userDoodlebugs = validIntInput(msg, range);

    arry = new Critter**[userRows];
    for (int i = 0; i < userRows; i++) {
        arry[i] = new Critter*[userColumns];
    }

    // Initialize our array
    for (int i = 0; i < userRows; i++) {
        for (int j = 0; j < userColumns; j++) {
            arry[i][j] = NULL;
        }
    }
    // For each one of our ants, find a random location (keep trying until we find a spot)
    for (int i = 0; i < userAnts; i++) {
        bool success = false;
        while(success != true) // Keep trying until we find a spot
        {
            int antX = rand() % userRows;
            int antY = rand() % userColumns;

            if (arry[antX][antY] == NULL)
            {
                arry[antX][antY] = new Ant();
                success = true;
            }
        }
        }

        // For each one of our Doodlebugs, find a random location (keep trying until we find a spot)
        for (int i = 0; i < userDoodlebugs; i++) {
            bool success = false;
            while(success != true) // Keep trying until we find a spot
            {
                int dBugX = rand() % userRows;
                int dBugY = rand() % userColumns;
                if (arry[dBugX][dBugY] == NULL)
                {
                    arry[dBugX][dBugY] = new Doodlebug();
                    success = true;
                }
            }
            }

    printBoard();
}

/***********************************************************************
* This function generates a random number equivalent to one of the cardinal
* directions. If the bug can't move in that direction, because it's on the edge
* of the board or that space is occupied, the bug doesn't move, as per
* project guidelines
***********************************************************************/

void Board::antMove(int x, int y)
{
    int randMove = rand() % 4;
    // 0 = North, 1 = East, 2 = South, 3 = West


    // Try to move North
    if (randMove == 0)
    {
        if ( (x - 1 >= 0) && (arry[x - 1][y] == NULL) && (arry[x][y]->hasMoved() == false) )
        {
            arry[x][y]->move(false);     // Increments turns alive for critter, and for doodlebugs, indicate it has not eaten with false
            arry[x - 1][y] = arry[x][y];    // Move our bug north one space
            arry[x][y] = NULL;             // Set out current location to NULL
        }
    }

    // Try to move East
    if (randMove == 1)
    {
        if ( (y + 1 > userColumns) && (arry[x][y + 1] == NULL) && (arry[x][y]->hasMoved() == false) )
        {
            arry[x][y]->move(false);     // Increments turns alive for critter, and for doodlebugs, indicate it has not eaten with false
            arry[x][y + 1] = arry[x][y];    // Move our bug East one space
            arry[x][y] = NULL;              // Set out current location to NULL
        }
    }

    // Try to move South
    if (randMove == 2)
    {
        if ( (x + 1 < userRows) && (arry[x + 1][y] == NULL) && (arry[x][y]->hasMoved() == false) )
        {
            arry[x][y]->move(false);     // Increments turns alive for critter, and for doodlebugs, indicate it has not eaten with false
            arry[x + 1][y] = arry[x][y];    // Move our bug South one space
            arry[x][y] = NULL;              // Set out current location to NULL
        }
    }

    // Try to move West
    if (randMove == 3)
    {
        if ( (y - 1 >= 0) && (arry[x][y - 1] == NULL) && (arry[x][y]->hasMoved() == false)  )
        {
            arry[x][y]->move(false);     // Increments turns alive for critter, and for doodlebugs, indicate it has not eaten with false
            arry[x][y - 1] = arry[x][y];    // Move our bug West one space
            arry[x][y] = NULL;              // Set out current location to NULL
        }
    }

}

/***********************************************************************
* Checks all surrounding locations of select Doodlebug to find an ant to
* eat. If ant is available, then move to that location and remove ant, setting
* starveNum to 0 in the process. If no ants available, move as an ant would,
* randomly and without purpose.
***********************************************************************/

void Board::moveDoodlebug(int i, int j)
{
    // North: If cell not null, row is non-negative, and has ant,
    // then delete ant, reset starveNum to 0, and move to new spot
    if ((i - 1 >= 0) && (arry[i-1][j]!=NULL) && (arry[i-1][j]->getType()==1) && (arry[i][j]->hasMoved() == false))
    {
        arry[i][j]->move(true);
        delete arry[i-1][j];
        // Transfer ownership of Doodlebug to new space (move Doodlebug)

        arry[i - 1][j] = arry[i][j];
        arry[i][j] = NULL;
        return;
    }
    // North East: " "
    else if ((i-1>=0) && (j+1<userColumns) && (arry[i-1][j+1]!=NULL) && (arry[i-1][j+1]->getType() == 1) && (arry[i][j]->hasMoved() == false))
    {
        arry[i][j]->move(true);
        delete arry[i-1][j+1];
        // Transfer ownership of Doodlebug to new space (move Doodlebug)

        arry[i-1][j+1] = arry[i][j];
        arry[i][j] = NULL;
        return;
    }
    // East: " "
    else if ((j+1<userColumns) && (arry[i][j+1]!=NULL) && (arry[i][j+1]->getType() == 1) && (arry[i][j]->hasMoved() == false))
    {
        arry[i][j]->move(true);
        delete arry[i][j+1];
        // Transfer ownership of Doodlebug to new space (move Doodlebug)

        arry[i][j+1] = arry[i][j];
        arry[i][j] = NULL;
        return;
    }
    // South East: " "
    else if ((j+1<userColumns) && (i+1<userRows) && (arry[i+1][j+1]!=NULL) && (arry[i+1][j+1]->getType() == 1) && (arry[i][j]->hasMoved() == false))
    {
        arry[i][j]->move(true);
        delete arry[i+1][j+1];
        // Transfer ownership of Doodlebug to new space (move Doodlebug)

        arry[i+1][j+1] = arry[i][j];
        arry[i][j] = NULL;
        return;
    }
    // South: " "
    else if ((i+1<userRows) && (arry[i+1][j]!=NULL) && (arry[i+1][j]->getType() == 1) && (arry[i][j]->hasMoved() == false))
    {
        arry[i][j]->move(true);
        delete arry[i+1][j];
        // Transfer ownership of Doodlebug to new space (move Doodlebug)

        arry[i+1][j] = arry[i][j];
        arry[i][j] = NULL;
        return;
    }
    // South West: " "
    else if ((i+1<userRows) && (j-1>=0) && (arry[i+1][j-1]!=NULL) && (arry[i+1][j-1]->getType() == 1) && (arry[i][j]->hasMoved() == false))
    {
        arry[i][j]->move(true);
        delete arry[i+1][j-1];
        // Transfer ownership of Doodlebug to new space (move Doodlebug)

        arry[i+1][j-1] = arry[i][j];
        arry[i][j] = NULL;
        return;
    }
    // West: " "
    else if ((j-1>=0) && (arry[i][j-1]!=NULL) && (arry[i][j-1]->getType() == 1) && (arry[i][j]->hasMoved() == false))
    {
        arry[i][j]->move(true);
        delete arry[i][j-1];
        // Transfer ownership of Doodlebug to new space (move Doodlebug)

        arry[i][j-1] = arry[i][j];
        arry[i][j] = NULL;
        return;
    }
    // North West: " " +
    else if ((j-1>=0) && (i-1>=0) && (arry[i-1][j-1]!=NULL) && (arry[i-1][j-1]->getType() == 1) && (arry[i][j]->hasMoved() == false))
    {
        arry[i][j]->move(true);
        delete arry[i-1][j-1];
        // Transfer ownership of Doodlebug to new space (move Doodlebug)

        arry[i-1][j-1] = arry[i][j];
        arry[i][j] = NULL;
        return;
    }

    else
    {
        antMove(i, j);
    }

}

/***********************************************************************
* If a doodlebug has survived more than 8 turns, it gets to make a baby.
* Uses a vector of cardinal directions to take stock of any spots available.
* If not, no breeding occurs.
***********************************************************************/

void Board::breedDoodleBug(int x, int y)
{
    std::vector<std::string> freeSpaces;

    const int BREED_AGE = 8;
    if (arry[x][y]->getAge() >= BREED_AGE)
    {
        // Check North
        if ( (x - 1 >= 0) && (arry[x - 1][y] == NULL) )
        {  freeSpaces.push_back("north");    }

        // Check East
        if ( (y + 1 < userColumns) && (arry[x][y + 1] == NULL) )
        {   freeSpaces.push_back("east");    }

        // Check South
        if ( (x + 1 < userRows) && (arry[x + 1][y] == NULL) )
        {   freeSpaces.push_back("south");    }

        // Check West
        if ( (y - 1 >= 0) && (arry[x][y - 1] == NULL))
        {   freeSpaces.push_back("west");    }

        // If there are any available spaces to breed into
        if (freeSpaces.size() > 0)
        {
            int randDirection = rand() % freeSpaces.size();

            if(freeSpaces.at(randDirection) == "north")
            {
                arry[x - 1][y] = new Doodlebug();
            }

            if(freeSpaces.at(randDirection) == "east")
            {
                arry[x][y + 1] = new Doodlebug();
            }

            if(freeSpaces.at(randDirection) == "south")
            {
                arry[x + 1][y] = new Doodlebug();
            }

            if(freeSpaces.at(randDirection) == "west")
            {
                arry[x][y - 1] = new Doodlebug();
            }
            arry[x][y]->breed();
        }
    }
}

/***********************************************************************
* Breed ant if alive more than 3 turns. Behaves as breedDoodlebug().
***********************************************************************/

void Board::breedAnt(int x, int y)
{
    std::vector<std::string> freeSpaces;

    const int BREED_AGE = 3;
    if (arry[x][y]->getAge() >= BREED_AGE)
    {
        // Check North
        if ( (x - 1 >= 0) && (arry[x - 1][y] == NULL) )
        {  freeSpaces.push_back("north");    }

        // Check East
        if ( (y + 1 < userColumns) && (arry[x][y + 1] == NULL) )
        {   freeSpaces.push_back("east");    }

        // Check South
        if ( (x + 1 < userRows) && (arry[x + 1][y] == NULL) )
        {   freeSpaces.push_back("south");    }

        // Check West
        if ( (y - 1 >= 0) && (arry[x][y - 1] == NULL))
        {   freeSpaces.push_back("west");    }

        // If there are any available spaces to breed into
        if (freeSpaces.size() > 0)
        {
            int randDirection = rand() % freeSpaces.size();

            if(freeSpaces.at(randDirection) == "north")
            {
                arry[x - 1][y] = new Ant();
            }

            if(freeSpaces.at(randDirection) == "east")
            {
                arry[x][y + 1] = new Ant();
            }

            if(freeSpaces.at(randDirection) == "south")
            {
                arry[x + 1][y] = new Ant();
            }

            if(freeSpaces.at(randDirection) == "west")
            {
                arry[x][y - 1] = new Ant();
            }
            arry[x][y]->breed();

        }
    }
}

/***********************************************************************
* Performs all private member functions of Board, essentially completing
* one round of activity. First attempts to feed Doodlebugs with nearby ants,
* then moves Doodlebugs, moves ants, Breeds and starves Doodlebugs, and
* breeds ants. Sets all critters moved member function to false after each
* round. Finishes by printing the board to see progress
***********************************************************************/

void Board::moveBugs()
{
    // First cycle through all the spaces and for Doodlebugs, see if they can eat. If not, move normally
    for (int i = 0; i < userRows; i++) {
        for (int j = 0; j < userColumns; j++) {
            if (arry[i][j] != NULL && arry[i][j]->getType() == 2)
            {
                 moveDoodlebug(i, j);
            }
        }
    }

    // Then cycle through all the spaces and move all ants that can move
    for (int i = 0; i < userRows; i++) {
        for (int j = 0; j < userColumns; j++) {
            if (arry[i][j] != NULL && arry[i][j]->getType() == 1)
            {
                 antMove(i, j);
            }
        }
    }

    // Then Cycle through for all Doodlebugs, see if they can breed, then starve
    for (int i = 0; i < userRows; i++) {
        for (int j = 0; j < userColumns; j++) {
            if (arry[i][j] != NULL && arry[i][j]->getType() == 2)
            {
                 breedDoodleBug(i, j);
                 if (arry[i][j]->starve() == true)
                 {
                     delete arry[i][j];
                     arry[i][j] = NULL;
                 }
            }
        }
    }

    // Cycle through all our ants and see if they can breed
    for (int i = 0; i < userRows; i++) {
        for (int j = 0; j < userColumns; j++) {
            if (arry[i][j] != NULL && arry[i][j]->getType() == 1)
            {
                breedAnt(i, j);
            }
        }
    }

    // Cycle through all critters and set moved to false
    for (int i = 0; i < userRows; i++) {
        for (int j = 0; j < userColumns; j++) {
            if (arry[i][j] != NULL)
            {
                arry[i][j]->setMoved(false);
            }
        }
    }

    printBoard();

}

/***********************************************************************
* Default destructor. Frees all allocated memory
***********************************************************************/

Board::~Board()
{
    for (int i = 0; i < userRows; i++) {
        for (int j = 0; j < userColumns; j++) {
            if (arry[i][j] != NULL)
            {
                delete arry[i][j];
                arry[i][j] = NULL;
            }
        }
        delete [] arry[i];
    }
    delete [] arry;
    arry = NULL;
}
