/***********************************************************************************
*Author: Alex McEvoy
*Date: 11/25/17
*Description: Implementation file for class Library in Library.hpp
************************************************************************************/

#include <string>
#include <vector>
#include "Library.hpp"

Library::Library()
{
	currentDate = 0;
}

void Library::addBook(Book* bookIn)
{	holdings.push_back(bookIn);	}

void Library::addPatron(Patron* patronIn)
{	members.push_back(patronIn);	}

Patron* Library::getPatron(std::string pID)
{
	//Go through our prestigious members and see if this member is present
	for (int i = 0; i < members.size(); ++i)
	{
		if (members.at(i)->getIdNum() == pID)
			//If they are, return a pointer to that member
			return members.at(i);

	}
	//If not, return null
	return NULL;

}

Book* Library::getBook(std::string bID)
{
	//Go through our holdings and see if the book is present
	for (int i = 0; i < holdings.size(); ++i)
		{
			if (holdings.at(i)->getIdCode() == bID)
				//If it is, return a pointer to that book
				return holdings.at(i);
		}
	//If it's not, return null
	return NULL;
}

std::string Library::checkOutBook(std::string pID, std::string bID)
{
	//set our local pointers to easily access the current Patron and book
	Book* currentBook = Library::getBook(bID);
	Patron* currentPatron = Library::getPatron(pID);


	if (!currentBook)
		return "book not found";
	else if (!currentPatron)
		return "patron not found";
	else if (currentBook->getLocation() == CHECKED_OUT)
		return "book already checked out";
	//Check to see if the book is on hold
	else if (currentBook->getLocation() == ON_HOLD_SHELF)
	{
		//Check if the book is on hold by the person requesting it here
		if(currentBook->getRequestedBy()->getIdNum() == pID)
		{
			//If our current book is requested by our current patron, check it out
			currentBook->setCheckedOutBy(currentPatron);
			currentBook->setDateCheckedOut(currentDate);
			currentBook->setLocation(CHECKED_OUT);
			currentBook->setRequestedBy(NULL);
			currentPatron->addBook(currentBook);
			return "check out successful";
		}
		else
			return "book on hold by other patron";
	}
	//If all else fails, just check out the book
	else
	{
		currentBook->setCheckedOutBy(currentPatron);
		currentBook->setDateCheckedOut(currentDate);
		currentBook->setLocation(CHECKED_OUT);
		currentPatron->addBook(currentBook);

		return "check out successful";
	}

}


std::string Library::returnBook(std::string bID)
{
	//set our local pointers to easily access the current Patron and book
	Book* currentBook = Library::getBook(bID);
	Patron* currentPatron = currentBook->getCheckedOutBy();

	if (!currentBook)
		return "book not found";
	else if (currentBook->getLocation() != CHECKED_OUT)
		return "book already in library";
	else
	{
		//Update Patrons status, book location and who it is checked out by (noone)
		currentPatron->removeBook(currentBook);
		currentBook->setLocation(ON_SHELF);
		currentBook->setCheckedOutBy(NULL);
	}
	//Check if our book is on reserve, if so, put it on the hold shelf
	if (currentBook->getRequestedBy() != NULL)
		currentBook->setLocation(ON_HOLD_SHELF);

	return "return successful";
}

std::string Library::requestBook(std::string pID, std::string bID)
{
	//set our local pointers to easily access the current Patron and book
	Book* currentBook = Library::getBook(bID);
	Patron* currentPatron = Library::getPatron(pID);


	if (!currentBook)
		return "book not found";
	else if (!currentPatron)
		return "patron not found";
	else if (currentBook->getRequestedBy() != NULL)
		return "book already on hold";
	else
	{
		currentBook->setRequestedBy(currentPatron);
		if (currentBook->getLocation() == ON_SHELF)
			currentBook->setLocation(ON_HOLD_SHELF);
		return "request successful";
	}

}

std::string Library::payFine(std::string pID, double payment)
{
	//set our local pointers to easily access the current Patron and book
	Patron* currentPatron = Library::getPatron(pID);

	if (!currentPatron)
		return "patron not found";
	else
	{
		payment = -1 * payment;
		currentPatron->amendFine(payment);
	}
	return "payment successful";
}

void Library::incrementCurrentDate()
{
	currentDate += 1;

	for (int whichPerson = 0; whichPerson < members.size(); ++whichPerson)
	{
		//For each Patron, get their book list
		std::vector<Book*> personsBooks = members.at(whichPerson)->getCheckedOutBooks();

		for (int whichBook = 0; whichBook < personsBooks.size(); ++whichBook)
		{	//days overdue is the difference in current date and when checked out, minus our allowed checkout time
			int days_overdue = (currentDate - personsBooks.at(whichBook)->getDateCheckedOut()) - personsBooks.at(whichBook)->getCheckOutLength();

			if (days_overdue > 0)
				members.at(whichPerson)->amendFine(0.10);


		}
	}
}
