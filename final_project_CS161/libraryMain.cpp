/***********************************************************************************
*Author: Alex McEvoy
*Date: 11/25/17
*Description: Client code for Library.cpp
************************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include<cstdlib>       //For use of rand()
#include<ctime>
#include "Library.hpp"
using namespace std;

void randomAction(vector<Book*>, vector<Patron*>, Library*);
Book* randomBook(vector<Book*>);


int main()
{
    // Seed our random number generator
    unsigned seed = time(0);
    srand(seed);

    // Initialize our books and create a list of pointers to Book
    Book b1("111", "War and Peace", "Tolstoy");
    Book b2("112", "Moby Dick", "Melville");
    Book b3("113", "Phantom Tollbooth", "Juster");
    Book b4("114", "Tender is the Night", "F. Scott Fitzgerald");
    Book b5("115", "The Most Beautiful Woman in Town", "Charles Bukowski");
    Book b6("116", "The Sirens of Titan", "Kurt Vonnegut");
    Book b7("117", "Ishmael", "Daniel Quinn");
    Book b8("118", "A Short History of Nearly Everything", "Bill Bryson");
    Book b9("119", "John Dies at the End", "David Wong");
    Book b10("120", "A Farewell to Arms", "Ernest Hemingway");

    vector<Book*> books {&b1, &b2, &b3, &b4, &b5, &b6, &b7, &b8, &b9, &b10};

    // Similarly, initialize our patrons and create a list of pointers to Patron
    Patron p1("221", "Felicity");
    Patron p2("222", "Waldo");
    Patron p3("223", "John");
    Patron p4("224", "Paul");
    Patron p5("225", "George");
    Patron p6("226", "Ringo");
    Patron p7("225", "Paige");
    Patron p8("225", "Trey");
    Patron p9("225", "Jon");
    Patron p10("225", "Mike");

    vector<Patron*> patrons {&p1, &p2, &p3, &p4, &p5, &p6, &p7, &p8, &p9, &p10};

    // Create our Library object and add all our books and patrons
    Library lib;

    // Please note I'm compiling this with -std=c++14 for range
    // based for loops
    for (Book* novel : books) {
        lib.addBook(novel);
    }

    for (Patron* person : patrons) {
        lib.addPatron(person);
    }

    // 100 days of activity, each day one random person completing one
    // random task
    int days = 100;
    for (int i = 0; i < days; i++) {
        randomAction(books, patrons, &lib);
        lib.incrementCurrentDate();
    }

    return 0;
}

/***********************************************************************************
* Takes a vector of pointers to type Book and returns a randomly
* selected one of them.
************************************************************************************/

Book* randomBook(vector<Book*> theBooks)
{
    short bookIndex = rand() % theBooks.size();
    Book* currentBook = theBooks.at(bookIndex);

    return currentBook;

}


/***********************************************************************************
* Takes vectors of pointers to type Book and Patron, as well as a Library object
* passed by reference. Randomly selects one of our patrons and has them commit
* one randomly selected action on one randomly selected book.
************************************************************************************/

void randomAction(vector<Book*> ourBooks, vector<Patron*> ourPeople, Library* ourLib)
{
    // Possible actions are checkOutBook, returnBook, requestBook, payFine
    int possibleActions = 4;

    // Access a random person in patrons
    short patronIndex = rand() % ourPeople.size();
    Patron* currentPerson = ourPeople.at(patronIndex);

    // Determine which action
    short action = (rand() % possibleActions) + 1;

    // Use a switch statement complete the random action
    switch (action)
    {
        case 1: {   Book* currentBook = randomBook(ourBooks);
                    if (ourLib->checkOutBook(currentPerson->getIdNum(), currentBook->getIdCode()) == "check out successful")
                    {
                        cout << currentPerson->getName() << " has just checked out ";
                        cout << currentBook->getTitle() << "." << endl;
                    }
                    break;
                }
        case 2: {   if (currentPerson->getCheckedOutBooks().empty() == false) //only return if they have a book checked out
                    {
                        Book* currentBook = currentPerson->getCheckedOutBooks().at(0);
                        if (ourLib->returnBook(currentBook->getIdCode()) == "return successful")
                        {
                            cout << currentPerson->getName() << " has just returned ";
                            cout << currentBook->getTitle() << "." << endl;
                        }
                    }
                    break;
                }
        case 3: {   Book* currentBook = randomBook(ourBooks);
                    if (ourLib->requestBook(currentPerson->getIdNum(), currentBook->getIdCode()) == "request successful")
                    {
                        cout << currentPerson->getName() << " has just put ";
                        cout << currentBook->getTitle() << " on hold." << endl;
                    }

                    break;
                }
        case 4: {   int fineTotal = currentPerson->getFineAmount();
                    if (fineTotal > 0)
                    {
                        currentPerson->amendFine(fineTotal);

                        cout << currentPerson->getName() << " has paid their ";
                        cout << "fine of $" << fineTotal << "." << endl;
                    }
                    break;
                }
        default: cout << "Number other than 1-4" << endl;
                    break;
    }
}
