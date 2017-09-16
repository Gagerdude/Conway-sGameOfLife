#ifndef DRIVER_H
#define DRIVER_H

#include "Game.h"
#include "Cell.h"

#include <iostream>
#include <string>
#include <fstream>

class Driver
{
	public:
		Driver(std::string fileName, bool crossIn);
		~Driver();
		void print();
		void printIteration();
		void run();
	private:
		Game* currentGame;
};

#endif