#include "Driver.h"
#include "Game.h"
#include "Cell.h"

#include <iostream>

int main(int argc, char** argv)
{
	
	if(argc > 1)
	{
		bool cross;
		if(argc > 2 && argv[2][0] == 'c')
		{
			cross = true;
		}
		else
		{
			cross = false;
		}
		
		Driver gameDriver(argv[1], cross);
	
	}
	else
	{
		std::cout << "Must have 2 arguments in this format:\n";
		std::cout << "GameOfLife inputFile.txt (c)";
	}
	
	return(0);
}