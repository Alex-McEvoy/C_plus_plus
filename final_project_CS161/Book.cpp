/***********************************************************************************
*Author: Alex McEvoy
*Date: 11/25/17
*Description: Implementation file for class Book in Book.hh  
************************************************************************************/


#include <string>
#include "Book.hpp"

Book::Book(std::string idc, std::string t, std::string a)
{
	//Initialize all our variables
	idCode = idc;
	title = t;
	author = a;
	setLocation(ON_SHELF);
	setCheckedOutBy(NULL);
	setRequestedBy(NULL);
	//Set datecheckedOut to -1 as a flag that it has not yet been checked out
	dateCheckedOut = -1;

}	

int Book::getCheckOutLength()
{	return CHECK_OUT_LENGTH;	}

std::string Book::getIdCode()
{	return idCode;	}

std::string Book::getTitle()
{	return title;	}

std::string Book::getAuthor()
{	return author;	}

Locale Book::getLocation()
{	return location;	}

void Book::setLocation(Locale locationIn)
{	location = locationIn;	}

Patron* Book::getCheckedOutBy()
{	return checkedOutBy;	}

void Book::setCheckedOutBy(Patron* patronCheckedOut)
{	checkedOutBy = patronCheckedOut;	}

Patron* Book::getRequestedBy()
{	return requestedBy;	}

void Book::setRequestedBy(Patron* patronRequestedBy)
{	requestedBy = patronRequestedBy;	}

int Book::getDateCheckedOut()
{	return dateCheckedOut;	}

void Book::setDateCheckedOut(int dateIn)
{	dateCheckedOut = dateIn;	}



