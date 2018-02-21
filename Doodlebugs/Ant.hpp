/*********************************************************************
 ** File name: Ant.hpp
 ** Author: Group 44
 ** Date: 2/12/18
 ** Description: The Ant header file defines Ant objects.
 *********************************************************************/

#ifndef Ant_hpp
#define Ant_hpp

#include"Critter.hpp"

class Ant : public Critter
{

public:

	// Default Constructor
	Ant();

	// Increments Ant age
	void move(bool);

	// Resets Ant age to 0
	void breed();

	// Not used here, but necessary to allow Doodlebug to access starve through pointers to Critter
	bool starve();

	// Deconstructor
	~Ant();

};

#endif
