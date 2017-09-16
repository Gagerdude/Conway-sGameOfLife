#include "Game.h"
#include "Cell.h"

#include <iostream>

Game::Game(bool** firstGrid, int firstRows, int firstCols, bool crossIn)
{
	rows = firstRows;
	cols = firstCols;
	cross = crossIn;
	iterationNum = 0;
	Grid = new Cell**[rows];
	for(int i = 0; i < rows; i++)
	{
		Grid[i] = new Cell*[cols];
		
		for(int j = 0; j < cols; j++)
		{
			Grid[i][j] = new Cell(firstGrid[i][j]);
		}
	}
}

Game::~Game()
{
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			delete Grid[i][j];
		}
		delete[] Grid[i];
	}
	delete[] Grid;
}

//will move game forward by one step by creating a temporary Grid, and modifying the current Grid
void Game::iterate()
{
	//Initializes newGrid
	Cell*** newGrid = new Cell**[rows];
	for(int i = 0; i < rows; i++)
	{
		newGrid[i] = new Cell*[cols];
	}
	
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			//Checks if cell is 'dead' or 'alive' and makes apropriate next checks
			if(Grid[i][j]->getState())
			{
				/*Cell is alive!
				Rules:
					Underpopulation: if less than two neighbors are alive, it will die.
					Overpopulation: if more than three neighbors are alive, it will die.
				*/
				if(neighborState(i, j) < 2 || neighborState(i, j) > 3)
				{
					//Grid[i][j]->setState(false);
					newGrid[i][j] = new Cell(false);
				}
				else
				{
					newGrid[i][j] = new Cell(true);
				}
			}
			else
			{
				/*Cell is dead.
				Rules:
					Reproduction: an 'off' cell will turn on if 3 neighbors are alive.
				*/
				if(neighborState(i, j) == 3)
				{
					//Grid[i][j]->setState(true);
					newGrid[i][j] = new Cell(true);
				}
				else
				{
					newGrid[i][j] = new Cell(false);
				}
			}
		}
	}
	
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			delete Grid[i][j];
		}
		delete[] Grid[i];
	}
	delete[] Grid;
	
	Grid = newGrid;
	
	iterationNum++;
}

//will return the number of living neighbors, 0 - 8
int Game::neighborState(int currentRow, int currentCol)
{
	int livingNeighbors = 0;
	int y;
	int x;
	
	if(cross)
	{
		//for loops grab all 8 surrounding cells
		for(int i = (currentRow - 1); i <= (currentRow + 1); i++)
		{
			for(int j = (currentCol - 1); j <= (currentCol + 1); j++)
			{
				//Condition that stops function from reporting the current cell.
				if(i != currentRow || j != currentCol)
				{
					//Loops i to other side of grid instead of walking off array
					if(i < 0)
					{
						y = (rows - 1);
					}
					else if(i > (rows - 1))
					{
						y = 0;
					}
					else 
					{
						y = i;
					}
					
					//Loops j to other side of grid instead of walking off array
					if(j < 0)
					{
						x = (cols - 1);
					}
					else if(j > (cols - 1))
					{
						x = 0;
					}
					else
					{
						x = j;
					}
					
					if(Grid[y][x]->getState())
					{
						livingNeighbors++;
					}
				}
			}
		}
	}
	else
	{
		int y = (currentRow - 1);
		int x = (currentCol - 1);
		int iStop = (currentRow + 1);
		int jStop = (currentCol + 1);
		
		if(y < 0)
		{
			y = 0;
		}
		
		if(x < 0)
		{
			x = 0;
		}
		
		if(iStop > (rows - 1))
		{
			iStop = (rows - 1);
		}
		
		if(jStop > (cols - 1))
		{
			jStop = (cols - 1);
		}
		
		for(int i = y; i <= iStop; i++)
		{
			for(int j = x; j <= jStop; j++)
			{
				if(Grid[i][j]->getState() && (i != currentRow || j != currentCol))
				{
					livingNeighbors++;
				}
			}
		}
	}
	
	return(livingNeighbors);
}

Cell*** Game::getGrid()
{
	return(Grid);
}

int Game::getRows()
{
	return(rows);
}

int Game::getCols()
{
	return(cols);
}

int Game::getIterationNum()
{
	return(iterationNum);
}