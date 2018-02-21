/*********************************************************************
 ** File name: Doodlebug.hpp
 ** Author: Group 44
 ** Date: 02/12/18
 ** Description: The Doodlebug header file defines Doodlebug objects.
 *********************************************************************/

#ifndef Doodlebug_hpp
#define Doodlebug_hpp
#include "Critter.hpp"

class Doodlebug : public Critter
{
private:

public:
    Doodlebug();                        // default constructor
    void move(bool);                    // move Doodlebug after eating or without eating
    void breed();                       // breed new Doodlebug
    bool starve();                      // Lets Board know if starving
    ~Doodlebug();                       // deconstructor
};

#endif
