CC=g++

FLAGS=-c -Wall

OUTPUT=bin

FILES=main.o astronaut.o travel.o astronautService.o travelService.o readonlyT.o readonlyA.o

all: program

program: ${FILES}
	${CC} ${OUTPUT}/main.o ${OUTPUT}/astronaut.o ${OUTPUT}/travel.o ${OUTPUT}/astronautService.o ${OUTPUT}/travelService.o ${OUTPUT}/readonlyA.o ${OUTPUT}/readonlyT.o -o ${OUTPUT}/program.out

main.o : main.cpp
	${CC} ${FLAGS} main.cpp -o ${OUTPUT}/main.o

astronaut.o : domain/implementations/Astronaut.cpp
	${CC} ${FLAGS} domain/implementations/Astronaut.cpp -o ${OUTPUT}/astronaut.o

travel.o : domain/implementations/Travel.cpp
	${CC} ${FLAGS} domain/implementations/Travel.cpp -o ${OUTPUT}/travel.o

astronautService.o : services/AstronautService.cpp
	${CC} ${FLAGS} services/AstronautService.cpp -o ${OUTPUT}/astronautService.o

travelService.o : services/TravelService.cpp
	${CC} ${FLAGS} services/TravelService.cpp -o ${OUTPUT}/travelService.o

readonlyA.o : domain/classes/ReadonlyAstronaut.cpp
	${CC} ${FLAGS} domain/classes/ReadonlyAstronaut.cpp -o ${OUTPUT}/readonlyA.o

readonlyT.o : domain/classes/ReadonlyTravel.cpp
	${CC} ${FLAGS} domain/classes/ReadonlyTravel.cpp -o ${OUTPUT}/readonlyT.o

clean:
	rm -rf ${OUTPUT}/*.o ${OUTPUT}/program.out
