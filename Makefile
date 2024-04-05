CC=g++

FLAGS=-c -Wall

OUTPUT=bin

all: program

program: main.o 
	${CC} ${OUTPUT}/main.o -o ${OUTPUT}/program.out

main.o : main.cpp
	${CC} ${FLAGS} main.cpp -o ${OUTPUT}/main.o

clean:
	rm -rf ${OUTPUT}/*.o ${OUTPUT}/program.out
