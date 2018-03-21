CXX = g++
CXXFLAGS = -std=c++11


SRCS = main.cpp Utilities.cpp Barbarian.cpp BlueMen.cpp Character.cpp Combat.cpp HarryPotter.cpp Medusa.cpp Node.cpp Queue.cpp Vampire.cpp

OBJS =	main.o Utilities.o Barbarian.o BlueMen.o Character.o Combat.o HarryPotter.o Medusa.o Node.o Queue.o Vampire.o


main: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o main

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c ${SRCS}

clean:
	rm *.o main
