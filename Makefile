CC=g++

FLAGS=-c -Wall

OUTPUT=bin

all: program

program: main.o astronaut.o travel.o astronautService.o
	${CC} ${OUTPUT}/main.o ${OUTPUT}/astronaut.o ${OUTPUT}/travel.o ${OUTPUT}/astronautService.o -o ${OUTPUT}/program.out

main.o : main.cpp
	${CC} ${FLAGS} main.cpp -o ${OUTPUT}/main.o

astronaut.o : domain/implementations/Astronaut.cpp
	${CC} ${FLAGS} domain/implementations/Astronaut.cpp -o ${OUTPUT}/astronaut.o

travel.o : domain/implementations/Travel.cpp
	${CC} ${FLAGS} domain/implementations/Travel.cpp -o ${OUTPUT}/travel.o

astronautService.o : services/AstronautService.cpp
	${CC} ${FLAGS} services/AstronautService.cpp -o ${OUTPUT}/astronautService.o

clean:
	rm -rf ${OUTPUT}/*.o ${OUTPUT}/program.out
