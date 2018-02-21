/************************************************************************
 * *Program Name: Predator-Prey Game, Critter class header file
 * *Author: Group 44
 * *Date: 2/12/18
 * *Description: Critter is the base class for Ant and Doodlebug.
 * *The member variable "type" designates each Critter as an Ant or
 * *Doodlebug (Ant = 1, Dooblebug = 2). The member variable "age" tracks
 * *each Critter's age used to determine breeding potential.
 * *********************************************************************/

#ifndef CRITTER_HPP
#define CRITTER_HPP



class Critter
{
   protected:

      int type;
      int age;
      int starveNum;
      bool moved;

   public:
      Critter();
      int getType();
      int getAge();
      bool hasMoved();
      void setMoved(bool);
      virtual void move(bool) = 0;
      virtual void breed() = 0;
      virtual bool starve() = 0;
      virtual ~Critter();
};

#endif
