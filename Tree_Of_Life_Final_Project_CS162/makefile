CXX = g++
CXXFLAGS = -std=c++11


SRCS = main.cpp Utilities.cpp World.cpp treeOfLife.cpp Sister.cpp Player.cpp Mother.cpp Item.cpp homeWorld.cpp Gromdrin.cpp FireWorld.cpp DwarfKingdom.cpp Character.cpp Basilisk.cpp Metropolis.cpp Jeweler.cpp Innkeeper.cpp Jungle.cpp ElfRanger.cpp Swamp.cpp Dreadwind.cpp

OBJS =	main.o Utilities.o World.o treeOfLife.o Sister.o Player.o Mother.o Item.o homeWorld.o Gromdrin.o FireWorld.o DwarfKingdom.o Character.o Basilisk.o Metropolis.o Jeweler.o Innkeeper.o Jungle.o ElfRanger.o Swamp.o Dreadwind.o

main: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o main

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c ${SRCS}

clean:
	rm *.o main
