/***********************************************************************************
*Author: Alex McEvoy
*Date: 11/25/17
*Description: Implementation file for class Patron in Patron.hh
************************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include "Patron.hpp"


Patron::Patron(std::string idn, std::string n)
{
	idNum = idn;
	name = n;
	fineAmount = 0.0;
}

std::string Patron::getIdNum()
{	return idNum;	}

std::string Patron::getName()
{	return name;	}

std::vector<Book*> Patron::getCheckedOutBooks()
{	return checkedOutBooks;	}

void Patron::addBook(Book* b)
{
	checkedOutBooks.push_back(b);
}

void Patron::removeBook(Book* b)
{
	for(int i = 0; i < checkedOutBooks.size(); i++)
	{
		if (checkedOutBooks.at(i)->getIdCode() == b->getIdCode())
			checkedOutBooks.erase(checkedOutBooks.begin() + i);
	}
}

double Patron::getFineAmount()
{	return fineAmount;	}

void Patron::amendFine(double amount)
{	fineAmount += amount;	}
