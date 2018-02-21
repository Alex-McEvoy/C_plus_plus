
runGame: main.o Utilities.o Ant.o Board.o Critter.o Doodlebug.o
	g++ -std=c++11 -g main.o Utilities.o Ant.o Board.o Critter.o Doodlebug.o -o runGame

main.o: main.cpp Ant.cpp Board.cpp Critter.cpp Doodlebug.cpp
	g++ -std=c++11 -g -c main.cpp Ant.cpp Board.cpp Critter.cpp Doodlebug.cpp

Utilities.o: Utilities.cpp Utilities.hpp
	g++ -std=c++11 -g -c Utilities.cpp

Ant.o: Ant.cpp Ant.hpp
	g++ -std=c++11 -g -c Ant.cpp

Board.o: Board.cpp Board.hpp
	g++ -std=c++11 -g -c Board.cpp

Critter.o: Critter.cpp Critter.hpp
	g++ -std=c++11 -g -c Critter.cpp

Doodlebug.o: Doodlebug.cpp Doodlebug.hpp
	g++ -std=c++11 -g -c Doodlebug.cpp

clean:
	rm *.o runGame
