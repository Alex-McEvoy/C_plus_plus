

#ifndef BOARD_HPP
#define BOARD_HPP

#include"Critter.hpp"

class Board
{
private:
    Critter *** arry;
    int userAnts;
    int userDoodlebugs;
    int userRows, userColumns;
    void moveDoodlebug(int, int);
    void antMove(int, int);
    void breedDoodleBug(int, int);
    void breedAnt(int, int);

public:
    Board();
    Board(const Board &obj);
    Board& operator=(const Board &obj);
    void printBoard();
    void moveBugs();

    ~Board();


};


#endif
