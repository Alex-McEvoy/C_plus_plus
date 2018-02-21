CXX = g++
CXXFLAGS = -std=c++11

SRCS = main.cpp Vampire.cpp Utilities.cpp Medusa.cpp HarryPotter.cpp Character.cpp BlueMen.cpp Barbarian.cpp

OBJS = main.o Vampire.o Utilities.o Medusa.o HarryPotter.o Character.o BlueMen.o Barbarian.o 


main: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o main

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c ${SRCS}

clean:
	rm *.o main
