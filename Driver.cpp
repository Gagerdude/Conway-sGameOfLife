#include "Driver.h"
#include "Game.h"
#include "Cell.h"

#include <fstream>
#include <iostream>
#include <string>

Driver::Driver(std::string fileName, bool crossIn)
{
	int fileWidth;
	int fileHeight;
	char temp;
	
	
	//Initializes initial conditions to be passed onto game
	std::ifstream inFile(fileName);
	inFile >> fileWidth;
	inFile >> fileHeight;
	
	bool** fileGrid = new bool*[fileHeight];
	for(int i = 0; i < fileHeight; i++)
	{
		fileGrid[i] = new bool[fileWidth];
		
		for(int j = 0; j < fileWidth; j++)
		{
			inFile >> temp;
			if(temp == '1')
			{
				fileGrid[i][j] = true;
			}
			else if(temp == '-')
			{
				fileGrid[i][j] = false;
			}
		}
	}
	
	currentGame = new Game(fileGrid, fileHeight, fileWidth, crossIn);
	
	for(int i = 0; i < fileHeight; i++)
	{
		delete fileGrid[i];
	}
	delete[] fileGrid;
	
	run();
}

Driver::~Driver()
{
	delete currentGame;
}

void Driver::print()
{
	for(int i = 0; i < currentGame->getRows(); i++)
	{
		if(i == 0)
		{
			for(int j = 0; j < currentGame->getCols() + 2; j++)
			{
				std::cout << '-';
			}
			std::cout << '\n';
		}
		for(int j = 0; j < currentGame->getCols(); j++)
		{
			if(j == 0)
			{
				std::cout << '|';
			}
			
			
			if(currentGame->getGrid()[i][j]->getState() == true)
			{
				std::cout << 'X';
			}
			else
			{
				std::cout << ' ';
			}
			
			if(j == currentGame->getCols() - 1)
			{
				std::cout << '|';
			}
		}
		std::cout << '\n';
		if(i == currentGame->getRows() - 1)
		{
			for(int j = 0; j < currentGame->getCols() + 2; j++)
			{
				std::cout << '-';
			}
			std::cout << '\n';
		}
	}

}

void Driver::printIteration()
{
	for(int i = 0; i < currentGame->getCols() + 2; i++)
	{
		std::cout << '=';
	}
	std::cout << '\n';
	std::cout << "Iteration Number: " << currentGame->getIterationNum()<< '\n';
	for(int i = 0; i < currentGame->getCols() + 2; i++)
	{
		std::cout << '=';
	}
	std::cout << '\n';
}

void Driver::run()
{
	bool running = true;
	while(running)
	{
		printIteration();
		print();
		std::cin.ignore();
		
		currentGame->iterate();
	}
	
	/*for(int i = 0; i < 2; i++)
	{
		print();
		clear();
		currentGame->iterate();
	}*/
}

