CC = g++ -std=c++14

library: libraryMain.o Library.o Patron.o Book.o
	$(CC) libraryMain.o Library.o Patron.o Book.o -o library

libraryMain.o: libraryMain.cpp
	$(CC) -c libraryMain.cpp

Library.o: library.cpp
	$(CC) -c library.cpp

Patron.o: Patron.cpp
	$(CC) -c Patron.cpp

Book.o: Book.cpp
	$(CC) -c Book.cpp

clean:
	rm *o library
