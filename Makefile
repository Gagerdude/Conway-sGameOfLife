GameOfLife: main.o Driver.o Game.o Cell.o
	g++ -std=c++11 -g -Wall main.o Cell.o Game.o Driver.o -o GameOfLife
main.o: main.cpp Cell.h Game.h Driver.h
	g++ -std=c++11 -g -Wall -c main.cpp
Cell.o: Cell.h Cell.cpp
	g++ -std=c++11 -g -Wall -c Cell.cpp
Game.o: Game.h Game.cpp
	g++ -std=c++11 -g -Wall -c Game.cpp
Driver.o: Driver.h Driver.cpp
	g++ -std=c++11 -g -Wall -c Driver.cpp
clean:
	rm *.o GameOfLife