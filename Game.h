#ifndef GAME_H
#define GAME_H

#include "Cell.h"

class Game
{
	public:
		Game(bool** firstGrid, int firstRows, int firstCols, bool crossIn);
		~Game();
		void iterate();
		int neighborState(int row, int col);
		Cell*** getGrid();
		int getRows();
		int getCols();
		int getIterationNum();
	private:
		Cell*** Grid;
		int rows;
		int cols;
		int iterationNum;
		bool cross;
};

#endif