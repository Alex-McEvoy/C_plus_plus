CXX = g++ -std=c++11


SRCS = main.cpp Animal.cpp Tiger.cpp Penguin.cpp Turtle.cpp RandomAnimal.cpp Zoo.cpp Utilities.cpp

OBJS = main.o Animal.o Tiger.o Penguin.o Turtle.o Zoo.o RandomAnimal.o Utilities.o

HEADERS = Animal.hpp Tiger.hpp Penguin.hpp Turtle.hpp Zoo.hpp RandomAnimal.hpp Utilities.hpp

main: ${OBJS} ${HEADERS}
	${CXX}  ${SRCS} -o main

${OBJS}: ${SRCS}
	${CXX} -c ${SRCS}

clean:
	rm *.o main
